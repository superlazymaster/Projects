#include <iostream>

#include "Card.h"

using std::string;

Card::Card(string rank, string suit) : rank(rank), suit(suit), timesPlayed(0) {
    // TODO: implement constructor checks
    // cout << "Rank: " << rank << " Suit: " << suit << endl;
    if (rank == "" || suit == "") {
        throw std::invalid_argument("The rank or suit is empty");
    }
    for (unsigned int i = 0; i < rank.length(); i++) {
        if (!isalpha(rank[i]) && !isdigit(rank[i])) {
            throw std::invalid_argument(
                    "The rank contains non alphanumeric characters");
        }
    }
    for (unsigned int i = 0; i < suit.length(); i++) {
        if (!isalpha(suit[i]) && !isdigit(suit[i])) {
            throw std::invalid_argument(
                    "The suit contains non alphanumeric characters");
        }
    }
}

string Card::getRank() {
    // cout << "Rank of current card: " << this->rank << endl;
    return this->rank;
}

string Card::getSuit() {
    // cout << "Suit of current card: " << this->suit << endl;
    return this->suit;
}

int Card::getTimesPlayed() {
    // cout << "Times played: " << this->timesPlayed << endl;
    return this->timesPlayed;
}

bool Card::canBePlayed(string currentRank, string currentSuit) {
    if (this->rank == "8") {
        return true;
    }
    if (this->rank == currentRank || this->suit == currentSuit) {
        return true;
    }
    return false;
}

void Card::play() {
  timesPlayed++;
}
