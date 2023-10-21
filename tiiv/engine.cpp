#include "engine.h"
#include <iostream>

namespace tiiv {
    engine::engine(buildData data) {
        b_ = data;
    }
    void engine::runFight(std::vector<shipType> types){
        Fleet fleet1;
        Fleet fleet2;

        // std::cout << b_.getFleetData(1).at(0) << std::endl;
        // std::cout << b_.getFleetData(1).at(1) << std::endl;
        // std::cout << b_.getFleetData(1).at(2) << std::endl;
        for (int i = 0; i < b_.getFleetData(1).size(); i++) {

            for (int j = 0; j < b_.getFleetData(1)[i]; j++) {

                fleet1.addShip(types[i]);

            }
        }
        
        for (int i = 0; i < b_.getFleetData(2).size(); i++) {

            for (int j = 0; j < b_.getFleetData(2)[i]; j++) {

                fleet2.addShip(types[i]);

            }
        }

        while(fleet1.getFleetTop() && fleet2.getFleetTop()){
            int damage1 = fleet1.attack();
            int damage2 = fleet2.attack();
            //std::cout << "Fleet 1 Hits: " << damage1 << " Fleet 2 Hits: " << damage2 << std::endl;
            for(int i = 0; i < damage1; i++){
                fleet2.removeShip();
            }
            for(int i = 0; i < damage2; i++){
                fleet1.removeShip();
            }
        }

        return;
    }
}