#include "Character.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace ariel;
using namespace std;

//basic implementation

//-------------------------- constructor & initializations --------------------------//
Character::Character(string name_, Point location_, int hit_points_){
    this->name = name_;
    this->location = location_;
    this->hit_points = hit_points_;
    this->aTeamMember = false;
}


//-------------------------- getters & setters --------------------------//
int Character::getHit() const{
    return this->hit_points;
}

void Character::setHit(int new_hit){
    this->hit_points = new_hit;
}

string Character::getName() const{
    return this->name;
}

Point Character::getLocation() const{
    return this->location;
}

bool Character::isATeamMember() const{
    return aTeamMember;
}

void Character::setAsATeamMember(){
    this->aTeamMember = !isATeamMember();
}


//-------------------------- class methods --------------------------//

bool Character::isAlive() const{
    return this->hit_points > 0;
}

void Character::hit(int num){
    hit_points = hit_points - num;
}

double Character::distance(const Character* other) const{
    return getLocation().distance(other->getLocation());
}
