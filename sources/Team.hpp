#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace ariel{

    class Team{
        public:
        Team(Character* captain);
        Team(const Team& other);  // Copy constructor
        ~Team();
        Team& operator=(const Team& other);  // Overloaded assignment operator


        virtual void add(Character* player);
        virtual void attack(Team* enemy);
        void attack_checks(Team* enemy);
        int stillAlive() const;
        virtual string print();
        Character* getCaptian() const;
        void setCapitain(Character* new_captain);
        const std::vector<Character*>& getWarriors() const;
        Character* potantial_choice(Team* team) const;
        void sort_team(SortOrder sortOrder);

        private:
        Character* captain;
        vector<Character*> warriors; 
    };

    class SmartTeam : public Team{
        public:
            SmartTeam(Character* captain);
            SmartTeam(const SmartTeam& other);  //copy constructor
            ~SmartTeam();
            
            void attack(Team* team) override;
            string print() override; 
    };
}