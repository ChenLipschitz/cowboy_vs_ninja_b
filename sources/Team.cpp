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
    setCapitain(captain_);
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
    if (new_captain == nullptr){
        throw std::invalid_argument("Error- got a null pointer as a new captian");
    }
    if (new_captain->isACaptian() || !new_captain->isAlive()){
        throw std::runtime_error("Error- choose another captian");
    }
    captain = new_captain;
    captain->setAsACaptian();
}

const vector<Character*>& Team::getWarriors() const {
        return warriors;
}

//-------------------------- class methods --------------------------//
void Team::add(Character* warrior){
    if (warriors.size() == 10 ){
        throw std::runtime_error("Error- cannot add another warrior, the team reached its maximum capacity");
    }
    if (warrior == nullptr){
        throw std::invalid_argument("Error- got null warrior");
    }
    if (warrior->isATeamMember()){
        throw std::runtime_error("Error- this warrior is already a team member");
    }
    if (warrior->isAlive()){
        warriors.push_back(warrior);
        warrior->setAsATeamMember();
    }
}

void Team::attack(Team* enemy){
    if (enemy == nullptr){
        throw std::invalid_argument("Error- cannot attack bull team");
    }
    if (enemy->stillAlive() == 0){
        throw std::runtime_error("Error- all the enemy warriors are dead");
    }
    if (stillAlive() == 0){
        return; //cannot attack, the entire team died
    }
    if (this == enemy){
        throw std::invalid_argument("Error- Trojan horse, looks like you are trying to attack your own team");
    }

    // if the current captian is dead coronate a new captain
    if (!captain->isAlive()){
        this->setCapitain(potantial_choice(this));
    }
    if (captain == nullptr){
            throw std::runtime_error("Error- there is no captian");
    }

    Character* target = potantial_choice(enemy);
    
    for (Character* warrior: warriors){
        if (warrior == nullptr || !warrior->isAlive()){
            continue;
        }
         if(auto *cowboy = dynamic_cast<Cowboy *>(warrior)){
            if(!(target->isAlive())){
                target = potantial_choice(enemy);
            }
            if(target == nullptr){
                break;
            }
            cowboy->CowboyAttack(target);
        }
    }

    for (Character* warrior: warriors){
        if(target == nullptr)
            break;
        if(warrior == nullptr)
            continue;
        if(!warrior->isAlive())
            continue;
        if(auto *ninja = dynamic_cast<Ninja *>(warrior)){
            if(!target->isAlive()){
                target = potantial_choice(enemy);
            }
            if(target == nullptr)
                break;
            ninja->NinjaAttack(target);
        }
    }
    
}

Character* Team::potantial_choice(Team* team) const{
    Character* the_chosen = nullptr;
        double closest_distance = std::numeric_limits<double>::max();
        for (Character* warrior: team->getWarriors()){
            if (warrior == nullptr || !warrior->isAlive()){
                continue;
            }
            double curr_distance = warrior->distance(captain);
            if(curr_distance < closest_distance){
                closest_distance = curr_distance;
                the_chosen = warrior;
            }
        }
        return the_chosen;
}

int Team::stillAlive() const {
    int aliveWarriors = 0;
    for (Character* warrior : warriors) {
        if (warrior != nullptr && warrior->isAlive()) {
            aliveWarriors++;
        }
    }
    return aliveWarriors;
}


string Team::print(){
    return "";
}