#include "Character.hpp"
#include "Team.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace ariel;
using namespace std;


//-------------------------- constructors & initializations --------------------------//
Team::Team(Character* captain_){
    this->captain = captain_;
    players.push_back(captain);
}
Team::Team(const Team& other) : captain(other.captain), players(), size(0) {    // Copy constructor
    for (const auto& player : other.players) {
        this->add(player);
    }
}
Team::~Team() { // Destructor
    for (auto& player : players) {
        delete player;
    }
}

//-------------------------- Overloaded assignment operator --------------------------//
// Team& Team::operator=(const Team& other) {
//     if (this != &other) {
//         captain = other.captain;    // Copy the captain
//         players.clear();           // Copy the players vector
//         for (auto player : other.players) {
//             players.push_back(new Character(*player));
//         }
//         size = other.size;
//     }
//     return *this;
// }

//-------------------------- class methods --------------------------//
void Team::add(Character* player){
    // players.push_back(player);
    // size++;
}
void Team::attack(Team* enemy){}
int Team::stillAlive() const{
    return 0;
}
string Team::print(){
    return "";
}



// Constructor for Team2
Team2::Team2(Character* captain) : Team(captain){}

void Team2::attack(Team* enemy) {}
string Team2::print() {return"";}

int Team2::stillAlive() const {
    return 1;
}