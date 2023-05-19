#include "Character.hpp"
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
    if (isAlive() && num_of_bullets>0){
        enemy->hit(10);
        num_of_bullets--;
    }
}
bool Cowboy::hasboolets() const{
    return this->num_of_bullets > 0;
}
void Cowboy::reload() {
    this->num_of_bullets+=6;
}
string Cowboy::print() const{
    string str = "C Name: ";
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