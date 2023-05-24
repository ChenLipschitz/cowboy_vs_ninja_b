#include "Character.hpp"
#include "Cowboy.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace ariel;
using namespace std;

//basic implementation

//-------------------------- constructor & initializations --------------------------//
Character::Character(string name_, Point location_, int hit_points_){
    this->name = name_;
    this->location = location_;
    this->hit_points = hit_points_;
    this->aTeamMember = false;
    this->aCapatian = false;
}


//-------------------------- getters & setters --------------------------//
int Character::getHit() const{
    return this->hit_points;
}

void Character::setHit(int new_hit){
    if (new_hit < 0){
        throw std::invalid_argument("Error- Hit cannot be negative");
    }
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
    this->aTeamMember = true;
}

bool Character::isACaptian() const{
    return aCapatian;
}

void Character::setAsACaptian(){
    this->aCapatian = true;
}

void Character::setLocation(Point location_){
    this->location = location_;
}


//-------------------------- class methods --------------------------//

bool Character::isAlive() const{
    return this->hit_points > 0;
}

void Character::hit(int num){
    if (num < 0){
        throw std::invalid_argument("Error- the given number cannot be negative");
    }
    hit_points = hit_points - num;
}

double Character::distance(const Character* other) const{
    return getLocation().distance(other->getLocation());
}


bool Character::compare_to_hit_ascending(const Character* chara1, const Character* chara2) {
    return chara1->getHit() < chara2->getHit();
}

bool Character::compare_to_hit_descending(const Character* chara1, const Character* chara2){
    return chara1->getHit() > chara2->getHit();
}

bool Character::compare_to_C_to_N(const Character* chara1, const Character* chara2){
    const Cowboy* cowboy1 = dynamic_cast<const Cowboy*>(chara1);
    const Cowboy* cowboy2 = dynamic_cast<const Cowboy*>(chara2);

    if (cowboy1 && !cowboy2) {
        // chara1 is a Cowboy and chara2 is not
        return true;
    } else if (!cowboy1 && cowboy2) {
        // chara2 is a Cowboy and chara1 is not
        return false;
    } else {
        // Either both characters are Cowboys or neither of them is
        return false;
    }
}

void Character::sortCharacters(std::vector<Character*>& characters, SortOrder sortOrder) {
    if (sortOrder == HIT_POINTS_ASCENDING) {
        sort(characters.begin(), characters.end(), compare_to_hit_ascending);
    } else if (sortOrder == HIT_POINTS_DESCENDING) {
        sort(characters.begin(), characters.end(), compare_to_hit_descending);
    } else if (sortOrder == C_TO_N) {
        sort(characters.begin(), characters.end(), compare_to_C_to_N);
    } else {
        throw std::invalid_argument("Invalid sortOrder value. Expected 0 (hit points ascending), 1 (hit points descending), or 2 (speed points ascending).");
    }
}
