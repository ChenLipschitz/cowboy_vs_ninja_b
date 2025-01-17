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

// Constructor for SmartTeam
SmartTeam::SmartTeam(Character* captain) : Team(captain){}

void SmartTeam::attack(Team* enemy) {
    attack_checks(enemy);
    sort_team(HIT_POINTS_ASCENDING);
    Character* target = potantial_choice(enemy);
    for (Character* warrior: getWarriors()){
        if (!target->isAlive()){
            target = potantial_choice(enemy);
            if (target == nullptr){
                return;
            }
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


string SmartTeam::print() {
    string str = "Team Captian: " + this->getCaptian()->getName() +"\n"+"Team warriors:";
    cout<<str<<endl;
	for (Character* warrior : this->getWarriors()){
		if (dynamic_cast<Ninja *>(warrior) != nullptr){
			str+="\n"+warrior->print();
        }
        if (dynamic_cast<Cowboy *>(warrior) != nullptr){
			str+="\n"+warrior->print();
        }
	}
    return str;
}