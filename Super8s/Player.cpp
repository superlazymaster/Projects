#include <iostream>
#include <sstream>

#include "Player.h"

using std::vector, std::string, std::size_t;

Player::Player(bool isAI) : isAI(isAI), hand({}) {
    //  std::cout << "The constructor is being called and this person is: "
    //            << std::boolalpha << isAI << std::endl;
}

void Player::addToHand(Card* c) {
    // TODO: Add the card c to the player's hand
    // std::cout << this->getHandString() << std::endl;

    this->hand.push_back(c);
}

size_t Player::getHandSize() { return this->hand.size(); }


std::string Player::getHandString() {
    // TODO: Implement getter

    string card_str;
    if (this->hand.size() > 0) {
        for (unsigned int i = 0; i < this->hand.size() - 1; i++) {
            card_str += this->hand.at(i)->getRank() + " " +
                        this->hand.at(i)->getSuit() + ", ";
        }
        card_str += this->hand.at(hand.size() - 1)->getRank() + " " +
                    this->hand.at(hand.size() - 1)->getSuit();
    }
    return card_str;
}

Card* Player::playCard(vector<string> const& suits, string& currentRank, string& currentSuit) {
    // TODO: Choose a card to play and return the chosen card

    // AI playing
    if (this->isAI) {
        // Loop 1
        for (unsigned int i = 0; i < this->hand.size(); i++) {
            if (this->hand.at(i)->canBePlayed(currentRank, currentSuit)) {
                currentRank = this->hand.at(i)->getRank();
                currentSuit = this->hand.at(i)->getSuit();
                this->hand.at(i)->play();
                Card *card_i_need = this->hand.at(i);
                hand.erase(this->hand.begin() + i);
                return card_i_need;
            }
        }
        return nullptr;
    }
        // Human playing
    else {
        std::cout << "Your hand contains: " << this->getHandString() << std::endl;
        std::cout << "The next card played must be a " << currentRank << " or "
                  << currentSuit << std::endl;
        std::cout
                << "What would you like to play? (enter \"draw card\" to draw a card)"
                << std::endl;

        // User inputs what card they want to play
        string newRank;
        string newSuit;
        // Loop 2 - Seems to be terminal loop
        while (true) {
            std::cin >> newRank >> newSuit;
            if (!std::cin.fail()) {
                // drawing a card return nullptr
                if (newRank == "draw" && newSuit == "card") {
                    return nullptr;
                }
                else {
                    Card* card_i_need = nullptr;
                    // check if that card exists
                    // Loop 3 - Terminal loop
                    int index = 0;
                    bool is_in_deck = false;
                    for (unsigned int i = 0; i < this->hand.size(); i++) {
                        if (newRank == this->hand.at(i)->getRank() &&
                            newSuit == this->hand.at(i)->getSuit()) {
                            is_in_deck = true;
                            index = i;
                            break;
                        }
                    }
                    // Card not in deck, bring back control to top of loop
                    if (!is_in_deck) {
                        std::cout << "That's not a card you have. Try again." << std::endl;
                        continue;
                    }
                    else if(!this->hand.at(index)->canBePlayed(currentRank, currentSuit)) {
                        std::cout << "You can't play that card. Try again." << std::endl;
                        continue;
                    }
                    else{
                            // Check power play
                            currentRank = this->hand.at(index)->getRank();
                            if (currentRank == "8") {
                                std::cout << "What suit would you like to declare?" << std::endl;

                                bool valid_suit = false;
                                // Loop 4- Terminal loop
                                while (!valid_suit) {
                                    std::cin >> newSuit;
                                    // Check if the suit exists in suits vector
                                    for (unsigned int i = 0; i < suits.size(); i++) {
                                        if (suits.at(i) == newSuit) {
                                            valid_suit = true;
                                            currentSuit = newSuit;
                                            break;
                                        }
                                    }
                                    if (!valid_suit) {
                                        std::cout << "That's not a suit in this deck. Try again."
                                                  << std::endl;
                                    }
                                }
                            }
                                // Normal play
                            else {
                                currentSuit = this->hand.at(index)->getSuit();
                            }
                            this->hand.at(index)->play();
                            card_i_need = this->hand.at(index);
                            hand.erase(this->hand.begin() + index);
                            return card_i_need;
                    }
                }
            }
            else {
                return nullptr;
            }
        }
    }
}