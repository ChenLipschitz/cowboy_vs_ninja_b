#pragma once

#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

namespace ariel{
      class Cowboy : public Character{

        public:
        Cowboy(string name, Point location);
        ~Cowboy() override = default;
        void shoot(Character* enemy);
        bool hasboolets() const;
        void reload();
        string print() const override;
        void CowboyAttack(Character* target);

        private:
        int num_of_bullets;

    };
}