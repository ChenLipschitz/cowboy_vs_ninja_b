#include "Point.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace ariel;
using namespace std;

//-------------------------- constructors --------------------------//
Point::Point(){
    //by default create 0
    this->x = 0.0;
    this->y = 0.0;
}

Point::Point(double x_, double y_){
    this->x = x_;
    this->y = y_;
}

//-------------------------- getters & setters--------------------------//
double Point::getX() const{
    return this->x;
}
double Point::getY() const{
    return this->y;
}
void Point::setX(double x_){
    this->x = x_;
}
void Point::setY(double y_){
    this->y = y_;
}

//-------------------------- class methods --------------------------//
void Point::print(){
    cout << "Location: (" << this->x << "," << this->y << ")" << endl;
}

double Point::distance(const Point &other){
    double dist = sqrt(pow((other.getX() - this->x), 2) + pow((other.getY() - this->y), 2));
    if (dist < 0){
        throw std::runtime_error("ERROR- Distance cannot be negative");
    }
    return dist;
}

Point Point::moveTowards(Point source, Point destination, double dist){
    if (dist<0){
        throw std::invalid_argument("ERROR- Cannot move in a negative distance");
    }

    double distance_ = source.distance(destination);
    if (distance_ <= dist){
        return destination;
    }
    
    // was taken from ChatGPT
    double ratio = dist / distance_;
    double newX = source.getX() + ratio * (destination.getX() - source.getX());
    double newY = source.getY() + ratio * (destination.getY() - source.getY());

    return Point{newX, newY};
}
