#include "shipType.h"
#include <string>

namespace tiiv{

    shipType::shipType() {
        name_ = "Fighter";
        toHitValue_ = 9;
        armored_ = false;
        attackRolls_ = 1;
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