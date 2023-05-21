#pragma once
#include <iostream>

using namespace std;
namespace ariel{

    class Point{
        
        public:
        Point();
        Point (double x, double y);
        double getX() const;
        double getY() const;
        void setX(double x_);
        void setY(double y_);
        void print();
        double distance(const Point &other);
        Point static moveTowards(Point source, Point destination, double dist);

        private:
        double x;
        double y;

    };
}