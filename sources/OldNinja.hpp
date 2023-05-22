#pragma once

#include "Character.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;
 
namespace ariel {

    class OldNinja : public Ninja{
        public:
        OldNinja(string name, Point location);
    };
}