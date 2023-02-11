#include "ship.h"
#include <random>
#include <ctime>

namespace tiiv {
    Ship::Ship() {
        toHitValue_ = 9;
        armored_ = false;
        attackRolls_ = 1;
        name_ = "Fighter";
    }

    Ship::Ship(int toHit, bool a, int r, std::string n) {
        toHitValue_ = toHit;
        armored_ = a;
        attackRolls_ = r;
        name_ = n;
    }

    Ship::Ship(shipType ship_type) {
        toHitValue_ = ship_type.getToHit();
        armored_ = ship_type.getArmored();
        attackRolls_ = ship_type.getRolls();
        name_ = ship_type.getName();
        shipType_ = ship_type;
    }

    int Ship::getToHit() {
        return toHitValue_;
    }

    bool Ship::getArmor() {
        return armored_;
    }

    void Ship::breakArmor() {
        armored_ = false;
    }

    std::string Ship::getName() {
        return name_;
    }

    shipType Ship::getShipType() {
        return shipType_;
    }

    int Ship::getRolls() {
        return attackRolls_;
    }
    
    int Ship::rollAttack() {
        int h = 0;
        for(int i = 0, r = getRolls(); i < r; i++) {
            if(rand()%10+1 >= toHitValue_) {
                h++;
            }
        }
        return h;
    }

}