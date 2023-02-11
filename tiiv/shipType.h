#pragma once

#include <string>

namespace tiiv {
    class shipType {
    public:
        shipType();
        shipType(std::string name, int toHitValue, bool armored, int attackRolls);
        std::string getName();
        int getToHit();
        bool getArmored();
        int getRolls();
    private:
        std::string name_;
        int toHitValue_;
        bool armored_;
        int attackRolls_;
    };
}