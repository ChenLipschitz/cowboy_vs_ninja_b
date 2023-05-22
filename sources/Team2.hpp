#pragma once
#include "Character.hpp"
#include "Team.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ariel{
    class Team2 : public Team{
        public:
        Team2(Character* captain);
        Team2(const Team2& other);  // Copy constructor

        void attack(Team* enemy) override;
        string print() override;

    };
}