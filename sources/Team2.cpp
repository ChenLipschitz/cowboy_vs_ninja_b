#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
using namespace ariel;
using namespace std;


// Constructor for Team2
Team2::Team2(Character* captain) : Team(captain){}

void Team2::attack(Team* enemy) {
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
    if (!getCaptian()->isAlive()){
        this->setCapitain(this->potantial_choice(this));
    }

    Character* target = potantial_choice(enemy);
    for (Character* warrior: getWarriors()){
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


string Team2::print() {return"";}
