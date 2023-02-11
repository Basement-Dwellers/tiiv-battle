#pragma once
#include <string>
#include <vector>

namespace tiiv {
    class buildData {
        public:
            buildData();
            buildData(std::vector<std::vector<int>> fleetData);
            std::vector<int> getFleetData(int fleet_number);

        private:
            std::vector<int> fleet_1_data_;
            std::vector<int> fleet_2_data_;            
    };
}