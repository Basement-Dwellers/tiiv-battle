//This class takes in the values from the ships folder and creates a template for engine and fleet to build ships from
#include "shipType.h"
#include <string>

namespace tiiv{

    shipType::shipType() {
        name_ = "";
        toHitValue_ = 0;
        armored_ = false;
        attackRolls_ = 0;
    }

    shipType::shipType(std::string name, int toHitValue, bool armored, int attackRolls) {
        name_ = name;
        toHitValue_ = toHitValue;
        armored_ = armored;
        attackRolls_ = attackRolls;
    }
    std::string shipType::getName(){
        return name_;
    }
    int shipType::getToHit(){
        return toHitValue_;
    }
    bool shipType::getArmored(){
        return armored_;
    }
    int shipType::getRolls(){
        return attackRolls_;
    }
}
