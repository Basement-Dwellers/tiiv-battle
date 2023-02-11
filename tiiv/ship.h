#pragma once

#include "shipType.h"
#include <string>

namespace tiiv {
    class Ship {
        public:
            Ship();
            Ship(int toHit, bool a = false, int r = 1, std::string n = "");
            Ship(shipType ship_type);

            bool getArmor();
            int getToHit();
            std::string getName();
            shipType getShipType();
            int getRolls();

            void breakArmor();
            int rollAttack();
            
            Ship* next = nullptr;
        private:
            bool armored_;
            int toHitValue_;
            int attackRolls_;
            std::string name_;
            shipType shipType_;
    };
}