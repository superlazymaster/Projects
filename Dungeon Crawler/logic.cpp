#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */

char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {

    ifstream inFS;
    inFS.open(fileName);
    if(!inFS.is_open()){
        inFS.close();
        return nullptr;
    }
    inFS>>maxRow>>maxCol;
    if(inFS.fail()){
        inFS.close();
        return nullptr;
    }

    if(maxRow>999999||maxCol>999999||maxRow<=0||maxCol<=0||INT32_MAX/maxRow<maxCol){
        inFS.close();
        return nullptr;
    }
    char** map = createMap(maxRow, maxCol);
    inFS>>player.row>>player.col;
    if(inFS.fail()){
        inFS.close();
        deleteMap(map,maxRow);
        return nullptr;
    }

    if(player.row<0||player.col<0||player.row>=maxRow||player.col>=maxCol){
        inFS.close();
        deleteMap(map,maxRow);
        return nullptr;
    }
    bool doorFound=false;
    bool exitFound=false;
    char curr_tile=' ';
    for(int r=0; r<maxRow; r++){
        for(int c=0; c<maxCol; c++){
            // check for valid tile
            inFS>>curr_tile;
            if(inFS.fail()){
                deleteMap(map, maxRow);
                return nullptr;
            }
            if(curr_tile!=TILE_OPEN
            &&curr_tile!=TILE_AMULET
            &&curr_tile!=TILE_DOOR
            &&curr_tile!=TILE_EXIT
            &&curr_tile!=TILE_MONSTER
            &&curr_tile!=TILE_PILLAR
            &&curr_tile!=TILE_TREASURE){
                inFS.close();
                deleteMap(map,maxRow);
                return nullptr;
            }
            //check for person coordinate
            if(r==player.row&&c==player.col){
                if (curr_tile==TILE_OPEN){
                    map[r][c]=TILE_PLAYER;
                }
                else{
                    inFS.close();
                    deleteMap(map,maxRow);
                    return nullptr;
                }
            }
            else{
                if(curr_tile==TILE_DOOR){
                    doorFound = true;
                }
                if(curr_tile==TILE_EXIT){
                    exitFound = true;
                }
                map[r][c]=curr_tile;
            }
        }
    }
    if(!doorFound&&!exitFound){
        deleteMap(map, maxRow);
        return nullptr;
    }
    inFS>>curr_tile;
    if(!inFS.fail()){
        inFS.close();
        deleteMap(map,maxRow);
        return nullptr;
    }
    else{
        inFS.close();
        return map;
    }
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if(input==MOVE_UP){
        nextRow-=1;
    }
    else if(input==MOVE_DOWN){
        nextRow+=1;
    }
    else if(input==MOVE_LEFT){
        nextCol-=1;
    }
    else if(input==MOVE_RIGHT){
        nextCol+=1;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    char **arr = new char *[maxRow];
    for (int x = 0; x < maxRow; x++) {
        arr[x] = new char[maxCol];
    }
    for (int x = 0; x < maxRow; x++) {
        for (int y = 0; y < maxCol; y++) {
            arr[x][y] = '-';
        }
    }
    return arr;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if(map!=nullptr) {
        for (int x = 0; x < maxRow; x++) {
            delete[] map[x];
        }
        delete[] map;
        map = nullptr;
        maxRow = 0;
    }
    else{
        maxRow=0;
    }
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    if(map!= nullptr&&INT32_MAX/2>maxRow&&INT32_MAX/2>maxCol&&maxRow>0&&maxCol>0) {
        char **arr = new char *[maxRow * 2];
        for (int x = 0; x < maxRow * 2; x++) {
            arr[x] = new char[maxCol * 2];
        }
        for (int r = 0; r < maxRow; r++) {
            for (int c = 0; c < maxCol; c++) {
                arr[r][c] = map[r][c];
            }
        }
        for (int r = maxRow; r < maxRow * 2; r++) {
            for (int c = 0; c < maxCol; c++) {
                if (map[r - maxRow][c] == TILE_PLAYER) {
                    arr[r][c] = TILE_OPEN;
                } else {
                    arr[r][c] = map[r - maxRow][c];
                }
            }
        }
        for (int r = 0; r < maxRow; r++) {
            for (int c = maxCol; c < maxCol * 2; c++) {
                if (map[r][c - maxCol] == TILE_PLAYER) {
                    arr[r][c] = TILE_OPEN;
                } else {
                    arr[r][c] = map[r][c - maxCol];
                }
            }
        }
        for (int r = maxRow; r < maxRow * 2; r++) {
            for (int c = maxCol; c < maxCol * 2; c++) {
                if (map[r - maxRow][c - maxCol] == TILE_PLAYER) {
                    arr[r][c] = TILE_OPEN;
                } else {
                    arr[r][c] = map[r - maxRow][c - maxCol];
                }
            }
        }
        for (int r = 0; r < maxRow; r++) {
            delete[] map[r];
        }
        delete[] map;
        maxRow *= 2;
        maxCol *= 2;
        return arr;
    }
    else {
        return nullptr;
    }
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    int status=1;
    if(nextRow>=maxRow||nextCol>=maxCol||nextRow<0||nextCol<0||map[nextRow][nextCol]==TILE_PILLAR||map[nextRow][nextCol]==TILE_MONSTER){
        nextRow=player.row;
        nextCol=player.col;
        return 0;
    }
    else if(map[nextRow][nextCol]==TILE_TREASURE){
        player.treasure+=1;
        status = 2;
    }
    else if(map[nextRow][nextCol]==TILE_AMULET){
        status =  3;
    }
    else if(map[nextRow][nextCol]==TILE_DOOR){
        status =  4;
    }
    else if(map[nextRow][nextCol]==TILE_EXIT){
        if(player.treasure>0){
            status =  5;
        }
        else{
            return 0;
        }
    }
    map[nextRow][nextCol]=TILE_PLAYER;
    map[player.row][player.col]=TILE_OPEN;
    player.row=nextRow;
    player.col=nextCol;
    return status;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
        for(int r=player.row-1; r>=0; r--){
            if(map[r][player.col]==TILE_PILLAR){
                break;
            }
            else if(map[r][player.col]==TILE_MONSTER){
                map[r+1][player.col]=TILE_MONSTER;
                map[r][player.col]=TILE_OPEN;
            }
        }
        //check down
        for(int r=player.row+1; r<maxRow; r++){
            if(map[r][player.col]==TILE_PILLAR){
                break;
            }
            else if(map[r][player.col]==TILE_MONSTER){
                map[r-1][player.col]=TILE_MONSTER;
                map[r][player.col]=TILE_OPEN;
            }
        }
        //check left
        for(int c=player.col-1; c>=0; c--){
            if(map[player.row][c]==TILE_PILLAR){
                break;
            }
            else if(map[player.row][c]==TILE_MONSTER){
                map[player.row][c+1] = TILE_MONSTER;
                map[player.row][c]=TILE_OPEN;
            }
        }
        //check right
        for(int c=player.col+1; c<maxCol; c++){
            if(map[player.row][c]==TILE_PILLAR){
                break;
            }
            else if(map[player.row][c]==TILE_MONSTER){
                map[player.row][c-1] = TILE_MONSTER;
                map[player.row][c]=TILE_OPEN;
            }
        }
    if(map[player.row][player.col]==TILE_MONSTER){
        return true;
    }
    else{
        return false;
    }
}
