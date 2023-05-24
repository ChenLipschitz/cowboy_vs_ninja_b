#include "Character.hpp"
#include "Cowboy.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace ariel;
using namespace std;

//-------------------------- constructor --------------------------//

Cowboy::Cowboy(string name, Point location) : Character(name, location, 110) {
    this->num_of_bullets = 6; // start with 6 bullets
}

//-------------------------- class methods --------------------------//

void Cowboy::shoot(Character* enemy) {
    if (enemy == this){
        throw std::runtime_error("Cowboy cannot shoot himself- it will be a suicide");
    }
    if (!enemy->isAlive()){
        throw std::runtime_error("The enemy is already dead");
    }
    if (!isAlive()){
        throw std::runtime_error("Error- cannot shoot because the cowboy is dead");
    }
    if (num_of_bullets>0){
        enemy->hit(10);
        num_of_bullets--;
    }
}

void Cowboy::CowboyAttack(Character* target) {
    if (target == nullptr) {
        throw std::invalid_argument("Error - invalid target");
    }
    if (!target->isAlive()) {
        throw std::runtime_error("Error - your job is done, the target is already dead");
    }
    if (!isAlive()) {
        throw std::runtime_error("Error - looks like you are dead");
    } else {
        if (num_of_bullets == 0) {
            reload();
        } else {
            shoot(target);
        }
    }
}


bool Cowboy::hasboolets() const{
    return this->num_of_bullets > 0;
}

void Cowboy::reload() {
    if (!isAlive()){
        throw std::runtime_error("Error- the cowboy is dead therefore cannot reload");
    }
    this->num_of_bullets = 6;
}

string Cowboy::print() const{
    string str = "C Name: ";
    if (isAlive()){
       str += this->getName() + "\nHit Points: " + to_string(this->getHit());
    }
    else{
        str += "(" + this->getName() + ")";
    }
    str += "\n"+getLocation().print();
    // cout<<str<<endl;
    return str;
}