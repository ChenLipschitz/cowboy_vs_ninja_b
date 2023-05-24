#pragma once
#include "Point.hpp"
#include <iostream>
#include <vector>

using namespace std;

enum SortOrder {
    HIT_POINTS_ASCENDING = 0,
    HIT_POINTS_DESCENDING = 1,
    C_TO_N = 2
};
 
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
        bool isACaptian() const;
        void setAsACaptian();
        void setLocation(Point location_);
        void sort_hit_ascending_order(std::vector<Character*>& characters);
        void sort_hit_descending_order(std::vector<Character*>& characters);
        void sort_speed_ascending_order(std::vector<Character*>& characters);
        static bool compare_to_hit_ascending(const Character* chara1, const Character* chara2);
        static bool compare_to_hit_descending(const Character* chara1, const Character* chara2);
        static bool compare_to_C_to_N(const Character* chara1, const Character* chara2);
        static void sortCharacters(std::vector<Character*>& characters, SortOrder sortOrder);
        // virtual void attackTarget(Character* warrior);

        private:
        string name;
        Point location;
        int hit_points;      
        bool aTeamMember;
        bool aCapatian;
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
        void NinjaAttack(Character* target);

        private:
        int speed;

        protected:
        Ninja(string name, Point location);
    };

}