#include "Character.hpp"
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
}
void Ninja::slash(Character* enemy) {
        if (!isAlive()){
        throw std::runtime_error("Error- the ninja is not alive");
    }
}
string Ninja::print() const{
    return "";
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