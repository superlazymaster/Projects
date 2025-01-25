#include "Game.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::string, std::vector;

Game::Game()
        : players({}), suits({}), ranks({}), deck({}), drawPile({}),
          discardPile({}) {}

// STATUS: WORKING
void Game::loadDeckFromFile(string filename) {
    // TODO: initialize suits, ranks, deck, and drawPile from the given file
    std::ifstream inFS(filename);
    if (!inFS.is_open()) {
        throw std::invalid_argument("Incorrect filename");
    }

    string suits;
    getline(inFS, suits);
    // std::cout << suits << std::endl;
    std::istringstream inSS(suits);
    string curr_suit;
    while (inSS >> curr_suit) {
        // std::cout << curr_suit << std::endl;
        this->suits.push_back(curr_suit);
    }

    string ranks;
    getline(inFS, ranks);
    // std::cout << ranks << std::endl;
    string curr_rank;
    std::istringstream inSS2(ranks);
    while (inSS2 >> curr_rank) {
        // std::cout << curr_rank << std::endl;
        this->ranks.push_back(curr_rank);
    }

    // for (int i = 0; i < this->ranks.size(); i++) {
    //   std::cout << this->ranks.at(i) << std::endl;
    // }
    // for (int i = 0; i < this->suits.size(); i++) {
    //   std::cout << this->suits.at(i) << std::endl;
    // }

    string line;
    while (getline(inFS, line)) {
        // std::cout << line << std::endl;
        std::istringstream inSS3(line);
        bool found_rank = false;
        bool found_suit = false;

        inSS3 >> curr_rank;
        inSS3 >> curr_suit;
        if (inSS3.fail()) {
            // std::cout << curr_rank << std::endl;
            // std::cout << curr_suit << std::endl;
            throw std::runtime_error("Not enough information to create card.");
        }
        string temp;
        inSS3 >> temp;
        if (!inSS3.fail()) {
            throw std::runtime_error("Too much information for one card");
        }
        for (unsigned int j = 0; j < this->ranks.size(); j++) {
            if (curr_rank == this->ranks.at(j)) {
                // std::cout << "I reach here" << std::endl;
                found_rank = true;
                break;
            }
        }
        for (unsigned int j = 0; j < this->suits.size(); j++) {
            if (curr_suit == this->suits.at(j)) {
                found_suit = true;
                break;
            }
        }
        if (!found_rank || !found_suit) {
            throw std::runtime_error("Invalid rank provided for card.");
        }
        try {
            Card *newCard = new Card(curr_rank, curr_suit);
            this->deck.push_back(newCard);
            this->drawPile.insert(this->drawPile.begin(), newCard);
        } catch (std::invalid_argument &excpt) {
            throw std::runtime_error("Unable to create card.");
        }
    }
}

// STATUS: WORKING
void Game::addPlayer(bool isAI) {
    // TODO: add a new player to the game
    Player *newPlayer = new Player(isAI);
    this->players.push_back(newPlayer);
}

// STATUS: WORKING
void Game::drawCard(Player *p) {
    // TODO: Move the top card of the draw pile to Player p's hand
    // If the draw pile is empty, flip the discard pile to create a new one
     if (this->drawPile.size() < 1) {
        std::cout << "Draw pile, empty, flipping the discard pile." << std::endl;
        if(this->discardPile.size()<1){
            throw std::runtime_error("");
        }
        else {
            for (unsigned int i = 0; i < this->discardPile.size(); i++) {
                // std::cout << i << std::endl;

                // std::cout << this->discardPile.at(i)->getRank()
                //           << this->discardPile.at(i)->getSuit() << std::endl;
//                std::cout << this->discardPile.at(0)->getRank() << " " << this->discardPile.at(0)->getSuit()
//                          << std::endl;
                this->drawPile.insert(this->drawPile.begin(), this->discardPile.at(i));
            }
            this->discardPile.clear();
            // std::cout << this->drawPile.back()->getRank() << std::endl;
            p->addToHand(this->drawPile.back());
            // std::cout << "Do i reach here?" << std::endl;
            this->drawPile.pop_back();
            // std::cout << "Do i reach here?" << std::endl;
        }
    } else {
        p->addToHand(this->drawPile.back());
        this->drawPile.pop_back();
    }
}

// STATUS: WORKING
Card *Game::deal(int numCards) {
    // TODO: Flip the top card of the draw pile to be the initial discard
    // then deal numCards many cards to each player
    Card *initial_disc = this->drawPile.back();
    this->discardPile.push_back(this->drawPile.back());
    this->drawPile.pop_back();
    for (int i = 0; i < numCards; i++) {
        for (unsigned int j = 0; j < this->players.size(); j++) {
            drawCard(this->players.at(j));
        }
    }
    // std::cout << "Do i reach here?" << std::endl;
    // if (this->discardPile.size() > 0) {
    //   return this->discardPile.at(0);
    // }
    // std::cout << "Do i reach here?" << std::endl;
    return initial_disc;
}

// STATUS: WORKING
string Game::mostPlayedSuit() {
    // TODO: Return the suit which has been played the most times
    // if there is a tie, choose any of the tied suits

    vector<int> cardCounts(this->suits.size());
    for(unsigned int i=0; i<this->suits.size(); i++){
        for(unsigned int j=0; j<this->deck.size(); j++){
            if(this->deck.at(j)->getSuit()==this->suits.at(i)){
                cardCounts.at(i)+=this->deck.at(j)->getTimesPlayed();
            }
        }
    }
    int maxCount=cardCounts.at(0);
    int maxCountIndex=0;
    for(unsigned int i=0; i<cardCounts.size(); i++){
        if(cardCounts.at(i)>maxCount){
            maxCount=cardCounts.at(i);
            maxCountIndex=i;
        }
    }
    return this->suits.at(maxCountIndex);
}

int Game::runGame() {
    // TODO: Run the game and return the number of the winning player
    // std::cout << "Hey I can cout things here" << std::endl;
//    if(this->players.size()<2||this->deck.empty()||this->drawPile.empty()||this->suits.empty()||this->ranks.empty()){
//        return -1;
//    }
    int player_index = 0;
    string currentRank, currentSuit;

    //If it is in the deck then the card is valid
    currentRank = this->deck.at(0)->getRank();
    currentSuit = this->deck.at(0)->getSuit();

    // LOOP 1
    while (true){

        std::cout << "Player " << player_index << "'s turn!" << std::endl;
//        std::cout<<"Draw Pile: "<<std::endl;
//        for(int i=0; i<this->drawPile.size(); i++){
//            std::cout<<this->drawPile.at(i)->getRank()<<" "<<this->drawPile.at(i)->getSuit()<<std::endl;
//        }
//        std::cout<<"Discard Pile: "<<std::endl;
//        for(int i=0; i<this->discardPile.size(); i++){
//            std::cout<<this->discardPile.at(i)->getRank()<<" "<<this->discardPile.at(i)->getSuit()<<std::endl;
//        }
        Card *card = this->players.at(player_index)
                ->playCard(this->suits, currentRank, currentSuit);
        if (card == nullptr) {
            try {
                this->drawCard(this->players.at(player_index));
                std::cout << "Player " << player_index << " draws a card." << std::endl;
            } catch (const std::runtime_error&){
                std::cout << "Player " << player_index << " cannot draw a card."<<std::endl;
                return -1;
            }
        } else {
            if (card->getRank() == "8") {
                std::cout << "Player " << player_index << " plays " << card->getRank()
                          << " " << card->getSuit() << " and changes the suit to "
                          << currentSuit << "." << std::endl;

            } else {
                std::cout << "Player " << player_index << " plays " << card->getRank()
                          << " " << card->getSuit() << "." << std::endl;

            }
            this->discardPile.push_back(card);
        }
        if (this->players.at(player_index)->getHandSize() <=0) {
            return player_index;
        }
        player_index = (player_index+1)%this->players.size();
    }
}

// Destructor--Deallocates all the dynamic memory we allocated
Game::~Game() {
    for (unsigned int i = 0; i < deck.size(); i++) {
        delete deck.at(i);
    }
    for (unsigned int i = 0; i < players.size(); i++) {
        delete players.at(i);
    }
}
