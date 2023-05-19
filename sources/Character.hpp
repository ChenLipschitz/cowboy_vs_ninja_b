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
        double distance(Character &other);
        void hit(int);
        virtual string print() const = 0;
        string getName() const;
        Point getLocation() const;
        int getHit() const;
        void setHit(int);

        private:
        string name;
        Point location;
        int hit_points;      
        
    };

    //-------------------------- Cowboy --------------------------//
    class Cowboy : public Character{

        public:
        Cowboy(string name, Point location);
        ~Cowboy() override = default;
        void shoot(Character* enemy);
        bool hasboolets() const;
        void reload();
        string print() const override;

        private:
        int num_of_bullets;

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

    //-------------------------- Different types of Ninjas --------------------------//
    class OldNinja : public Ninja{
        public:
        OldNinja(string name, Point location);
    };

    class TrainedNinja : public Ninja{
        public:
        TrainedNinja(string name, Point location);
    };

    class YoungNinja : public Ninja{
        public:
        YoungNinja(string name, Point location);
    };
}