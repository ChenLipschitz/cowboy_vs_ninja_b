#pragma once

#include "Character.hpp"
#include "TrainedNinja.hpp"
#include "Point.hpp"
#include <iostream>


namespace ariel{
    
    class TrainedNinja : public Ninja{
        public:
        TrainedNinja(string name, Point location);
    };
}