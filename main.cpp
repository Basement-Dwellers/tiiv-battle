#include "tiiv/engine.h"
#include "tiiv/shipType.h"
#include "tiiv/buildData.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdio>
#include <unordered_map>
#include <random>
#include <ctime>

std::vector<tiiv::shipType> generateShipTypes();
void printShipTypes(std::vector<tiiv::shipType> shipTypeVector);
bool isInt(std::string s);

int main(int argc, char *argv[]) {
    srand(time(0));
    std::vector<tiiv::shipType> types = generateShipTypes();
    printShipTypes(types);
    std::unordered_map<std::string, int> shipNames;
    std::vector<std::vector<int>> fleetCounts;
    fleetCounts.push_back({});
    fleetCounts.push_back({});
    
    for(int i = 0, s = types.size(); i < s; i++) {
        fleetCounts[0].push_back(0);
        fleetCounts[1].push_back(0);
    }

    for (int i = 0; i < types.size(); i++) {
        shipNames[types[i].getName()] = i;
    }
    
    std::vector<std::string> args;
    for (int i = 0; i < argc; i++) {
        std::string s = argv[i];
        args.push_back(s);
    }

    for (int i = 0, p = -1; i < args.size(); i++) {
        if (args[i] == "-p") {
            if (p < 1) {
                p++;
            } else {
                //Scream and die
            }
        } else if (isInt(args[i])) {
            if (i > 0) {
                
            }
        } else if (args[i] == "-s") {
            if (i + 3 > args.size()) {
                //Scream and die
            } else if (shipNames.find(args[i+1]) == shipNames.end()) {
                //Scream and die
            } else {
                fleetCounts.at(p).at(shipNames[args[i+1]]) = std::stoi(args[i+2]);
            }
        }
    }

    tiiv::buildData data(fleetCounts);
    tiiv::engine battleEngine(data);
    battleEngine.runFight(types);
    
}

std::vector<tiiv::shipType> generateShipTypes() {
    std::vector<tiiv::shipType> shipTypeVector;
    for (const auto& dirEntry : std::filesystem::recursive_directory_iterator("ships")) {
        
        std::ifstream inFS;
        inFS.open(dirEntry.path().string());

        std::string shipTypeName;
        int shipTypeToHit;
        bool shipTypeArmored = false;
        int shipTypeRolls;
        std::string shipTypeArmoredString;

        inFS >> shipTypeName;
        inFS >> shipTypeToHit;
        inFS >> shipTypeArmoredString;
        inFS >> shipTypeRolls;
        if (shipTypeArmoredString == "true") {
            shipTypeArmored = true;
        }

        shipTypeVector.push_back(tiiv::shipType(shipTypeName, shipTypeToHit, shipTypeArmored, shipTypeRolls)); 
    }
    return shipTypeVector;
}

void printShipTypes(std::vector<tiiv::shipType> shipTypeVector) {
    std::cout << "------------------\nList of Available Ship Types:\n\n";
    for (int i = 0, s = shipTypeVector.size(); i < s; i++) {
        std::cout << i << ": ";
        std::cout << shipTypeVector[i].getName() << " - ";
        std::cout << "To Hit Value: " << shipTypeVector[i].getToHit() << " - ";
        std::cout << "Is Armored?: " << std::boolalpha << shipTypeVector[i].getArmored() << " - ";
        std::cout << "Number of Attack Dice: " << shipTypeVector[i].getRolls() << "\n";
    }
    std::cout << "------------------\n";
}

bool isInt(std::string s) {
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s.at(i))) {
            return false;
        }
    }
    return true;
}

