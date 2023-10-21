#include "fleet.h"
#include <iostream>

namespace tiiv {
    void Fleet::addShip(shipType ship_type) {
        if(ship_type.getArmored()){
            armoredShipsLeft_ = true;
        }
        Ship *newShip = new Ship(ship_type);
        Ship *p = fleetTop_;
        while (p) {
            if (newShip->getToHit() >= p->getToHit()) {
                newShip->next = p->next;
                p->next = newShip;
                return;
            }
            p = p->next;
        }
        if (p) {
            p->next = newShip;
        } else {
            fleetTop_ = newShip;
        }
        return;
    }

    Fleet::Fleet(Fleet f){
        Ship *p = f.getFleetTop();
        Ship *s = this->getFleetTop();
        if(p){
            this->getFleetTop() = new Ship(*p);
            this->getFleetTop()->next = nullptr;
            p = p->next;
        }
        while(p){
            s->next = new Ship(*p);
            s = s->next;
            s->next = nullptr;
            p = p->next;
        }
        this->armoredShipsLeft_ = f.armoredShipsLeft_;
    }

    Fleet::~Fleet() {
        Ship *s = fleetTop_;
        Ship *p = nullptr;
        while(s) {
            p = s;
            s = s->next;
            delete(p);
        }
    }

    void Fleet::removeShip() {
        if (!armoredShipsLeft_ && fleetTop_) {
            Ship *p = fleetTop_->next;
            delete(fleetTop_);
            fleetTop_ = p;
        } else if(fleetTop_){
            Ship *p = fleetTop_;
            while(p){
                if(p->getArmor()) {
                    p->breakArmor();
                    return;
                }
                p = p->next;
            }
            armoredShipsLeft_ = false;
            removeShip();
        }
        return;
    }

    int Fleet::attack() {
        Ship *p = fleetTop_;
        int hits = 0;
        while (p) {
            hits += p->rollAttack();
            p = p->next;
        }

        return hits;
    }

    Ship* Fleet::getFleetTop(){
        return fleetTop_;
    }
}
