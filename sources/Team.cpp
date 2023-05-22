#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
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
    add(captain);
}

Team::Team(const Team& other) : captain(other.captain), warriors(), size(0) {    // Copy constructor
    for (const auto& player : other.warriors) {
        add(player);
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
    if (warriors.size() == 10 ){
        throw std::runtime_error("Error- cannot add another warrior, the team reached maximum capacity");
    }
    if (warrior != nullptr && warrior->isAlive() && !warrior->isATeamMember()){
        warriors.push_back(warrior);
        warrior->setAsATeamMember();
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
        if (!target->isAlive()){
            target = potantial_choice(enemy);
        }
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
        }
    }
    for (Character* warrior: warriors){
        if (!target->isAlive()){
            target = potantial_choice(enemy);
        }
        if (warrior->isAlive()){
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
}

Character* Team::potantial_choice(Team* team){
    Character* the_chosen = team->getCaptian();
        double closest_distance = std::numeric_limits<double>::max();
        for (Character* warrior: team->getWarriors()){
            double curr_distance = warrior->getLocation().distance(captain->getLocation());
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