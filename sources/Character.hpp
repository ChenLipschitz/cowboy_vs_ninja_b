#pragma once
#include "Point.hpp"
#include <iostream>

using namespace std;
 
namespace ariel {

    //-------------------------- Character --------------------------//
    class Character{
        
        public:
        Character(string name, Point location, int hit_points);
        virtual ~Character() = default;
        bool isAlive() const;
        double distance(const Character* other) const;
        void hit(int);
        virtual string print() const = 0;
        string getName() const;
        Point getLocation() const;
        int getHit() const;
        void setHit(int);
        bool isATeamMember() const;
        void setAsATeamMember();

        private:
        string name;
        Point location;
        int hit_points;      
        bool aTeamMember;
    };

    //-------------------------- Ninja --------------------------//
    class Ninja : public Character{

        public:
        ~Ninja() override = default;
        void move(Character* enemy);
        void slash(Character* enemy);
        void setSpeed(int speed_);
        int getSpeed() const;
        string print() const override;

        private:
        int speed;

        protected:
        Ninja(string name, Point location);
    };

}