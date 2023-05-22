#pragma once

#include "Character.hpp"
#include "YoungNinja.hpp"
#include "Point.hpp"
#include <iostream>

namespace ariel{
    class YoungNinja : public Ninja{
        public:
        YoungNinja(string name, Point location);
    };
}