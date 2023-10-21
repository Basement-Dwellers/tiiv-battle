#pragma once
#include <string>
#include <vector>
#include "buildData.h"
#include "fleet.h"
#include "shipType.h"

namespace tiiv {
    class engine {
        public:
            engine(buildData data);
            std::vector<Fleet> runFight(std::vector<shipType> types);
        private:
            buildData b_;
    };
}
