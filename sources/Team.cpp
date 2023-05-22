#include "Character.hpp"
#include "Team.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
using namespace ariel;
using namespace std;


//-------------------------- constructors & initializations --------------------------//
Team::Team(Character* captain_){
    this->captain = captain_;
    warriors.push_back(captain);
}

Team::Team(const Team& other) : captain(other.captain), warriors(), size(0) {    // Copy constructor
    for (const auto& player : other.warriors) {
        this->add(player);
    }
}

Team::~Team() { // Destructor
    for (auto& warrior : warriors) {
        delete warrior;
    }
}

//-------------------------- getters & setters --------------------------//
Character* Team::getCaptian() const{
    return captain;
}

void Team::setCapitain(Character* new_captain){
    this->captain = new_captain;
}

//-------------------------- class methods --------------------------//
void Team::add(Character* warrior){
    if (warrior != NULL && warrior->isAlive()){
        warriors.push_back(warrior);
    }
}

void Team::attack(Team* enemy){
    if (enemy == NULL){
        throw std::invalid_argument("Error- cannot attack bull team");
    }
    // if the current captian is dead coronate a new captain
    if (!enemy->getCaptian()->isAlive()){
        Character* potantial_captain = this->captain;
        double closest_distance = std::numeric_limits<double>::max();
        for (Character* warrior: warriors){
            double curr_distance = warrior->getLocation().distance(captain->getLocation());
            if(curr_distance < closest_distance && warrior->isAlive()){
                closest_distance = curr_distance;
                potantial_captain = warrior;
            }
        }
        this->setCapitain(potantial_captain);
    }
}

int Team::stillAlive() const {
    int aliveWarriors = 0;
    for (std::vector<Character*>::size_type i = 0; i < warriors.size(); i++) {
        if (warriors[i] != nullptr && warriors[i]->isAlive()) {
            aliveWarriors++;
        }
    }
    return aliveWarriors;
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