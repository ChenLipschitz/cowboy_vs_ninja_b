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

const vector<Character*>& Team::getWarriors() const {
        return warriors;
}

//-------------------------- class methods --------------------------//
void Team::add(Character* warrior){
    if (warrior != NULL && warrior->isAlive()){
        warriors.push_back(warrior);
    }
}

void Team::attack(Team* enemy){
    if (enemy == nullptr){
        throw std::invalid_argument("Error- cannot attack bull team");
    }
    if (enemy->stillAlive() == 0){
        return; //all the enemy warriors are dead
    }
    if (this->stillAlive() == 0){
        return; //cannot attack, the entire team died
    }
    if (this == enemy){
        throw std::invalid_argument("Error- Trojan horse, looks like you are trying to attack your own team");
    }

    // if the current captian is dead coronate a new captain
    if (!captain->isAlive()){
        this->setCapitain(potantial_choice(this));
    }

    Character* target = potantial_choice(enemy);
    for (Character* warrior: warriors){
        if (target->isAlive()){
            if (warrior->isAlive()){
                Cowboy* cowboy = dynamic_cast<Cowboy*>(warrior);
                if (cowboy != nullptr) {
                    if (cowboy->hasboolets()){
                        cowboy->shoot(target);
                    }
                    else{
                        cowboy->reload();
                    }
                }
                Ninja* ninja = dynamic_cast<Ninja*>(warrior);
                if (ninja != nullptr) {
                    if (ninja->getLocation().distance(target->getLocation()) <= 1){
                        ninja->slash(target);
                    }
                    else{
                        ninja->move(target);
                    }
                }
            }
        }
        else{
            target = potantial_choice(enemy);
        }
    }
}

Character* Team::potantial_choice(Team* team){
    Character* the_chosen = team->getCaptian();
        double closest_distance = std::numeric_limits<double>::max();
        for (Character* warrior: team->getWarriors()){
            double curr_distance = warrior->getLocation().distance(team->getCaptian()->getLocation());
            if(curr_distance < closest_distance && warrior->isAlive()){
                closest_distance = curr_distance;
                the_chosen = warrior;
            }
        }
        return the_chosen;
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