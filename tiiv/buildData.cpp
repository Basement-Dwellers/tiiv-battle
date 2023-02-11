#include "buildData.h"

namespace tiiv {
    buildData::buildData(std::vector<std::vector<int>> fleetData) {
        fleet_1_data_ = fleetData.at(0);
        fleet_2_data_ = fleetData.at(1);
    }

    buildData::buildData(){
        fleet_1_data_ = {};
        fleet_2_data_ = {};
    }

    std::vector<int> buildData::getFleetData(int fleet_number) {
        switch (fleet_number) {
        case 1:
            return fleet_1_data_;
            break;
        case 2:
            return fleet_2_data_;
            break;
        default:
            return fleet_1_data_;
            break;
        }
    }
}