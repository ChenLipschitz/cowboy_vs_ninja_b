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
        int stillAlive() const;
        virtual string print();
        Character* getCaptian() const;
        void setCapitain(Character* new_captain);
        const std::vector<Character*>& getWarriors() const;
        Character* potantial_choice(Team* team);

        private:
        Character* captain;
        vector<Character*> warriors; 
        int size;
    };

    class Team2 : public Team{
        public:
        Team2(Character* captain);
        Team2(const Team2& other);  // Copy constructor
        ~Team2();
        Team2& operator=(const Team2& other);  // Overloaded assignment operator

        void attack(Team* enemy) override;
        string print() override;
        int stillAlive() const;

    };

    class SmartTeam : public Team{
        public:
            SmartTeam(Character* captain);
            SmartTeam(const SmartTeam& other);  //copy constructor
            ~SmartTeam();
            SmartTeam& operator=(const SmartTeam& other);
            
            void attack(Team* team) override;
            string print() override; 
    };
}