//
//  PokemonCenter.hpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#pragma once

#include "Building.h"
#include "GameObject.h"
#include "Point2D.h"

class PokemonCenter : public Building
{
    
enum PokemonCenterStates {
    POTIONS_AVAILABLE = 0,
    NO_POTIONS_AVAILABLE = 1
    };
    
private:
    unsigned int potion_capacity;
    unsigned int num_potions_remaining;
    double pokedollar_cost_per_potion;
    
public:
    virtual ~PokemonCenter(); // destructor added
    PokemonCenter ();
    PokemonCenter (int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc);
    bool HasPotions();
    unsigned int GetNumPotionRemaining();
    bool CanAffordPotion(unsigned int potion, double budget);
    double GetPokeDollarCost(unsigned int potion);
    unsigned int DistributePotion(unsigned int potion_needed);
    bool Update();
    void ShowStatus();
    
};




