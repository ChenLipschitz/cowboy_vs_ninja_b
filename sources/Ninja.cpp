#include "Character.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
using namespace ariel;

//-------------------------- Ninja --------------------------//
Ninja::Ninja(string name, Point location) : Character(name, location, 100) {}


//--- getters & setters ---//
int Ninja::getSpeed() const{
    return this->speed;
}

void Ninja::setSpeed(int speed_){
    this->speed = speed_;
}


//--- class methods ---//
void Ninja::move(Character* enemy) {
    if (enemy == nullptr){
        throw invalid_argument("Error- the passed argument is NULL");
    }
    if (!isAlive()){
        throw std::runtime_error("Error- Cannot move if the ninja is dead");
    }
    if (enemy == this){
        return; //don't move because u can't move towards yourself
    }
    this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
}

void Ninja::slash(Character* enemy) {
    if (enemy == nullptr){
        throw invalid_argument("Error- the passed argument is NULL");
    }
    if (!isAlive()){
        throw std::runtime_error("Error- The ninja is not alive");
    }
    if (!enemy->isAlive()){
        throw std::runtime_error("Error- The enemy is already dead");
    }
    if (enemy == this){
        throw std::runtime_error("Ninja cannot slash himself- it will be a suicide");
    }
    if (this->distance(enemy) <= 1) {
        enemy->hit(40);
    }
}

string Ninja::print() const{
    string str = "N Name: ";
    if (isAlive()){
       str += this->getName() + "\nHit Points: " + to_string(this->getHit());
    }
    else{
        str += "(" + this->getName() + ")";
    }
    cout<<str<<endl;
    this->getLocation().print();
    return str;
}



//-------------------------- YoungNinja --------------------------//
YoungNinja::YoungNinja(string name, Point location): Ninja(name, location){
    setSpeed(14);
}

//-------------------------- TrainedNinja --------------------------//
TrainedNinja::TrainedNinja(string name, Point location): Ninja(name, location){
    setSpeed(12);
    setHit(120);
}

//-------------------------- OldNinja --------------------------//
OldNinja::OldNinja(string name, Point location): Ninja(name, location){
    setSpeed(8);
    setHit(150);
}