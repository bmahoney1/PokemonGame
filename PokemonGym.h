//
//  PokemonGym.hpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//



#include <iostream>
#include <string>
#include <math.h>

#pragma once


#include "Building.h"

class PokemonGym : public Building
{
    
enum PokemonGymStates {
    NOT_DEFEATED = 0,
    DEFEATED = 1
    };
    
private:
    unsigned int num_battle_remaining;
    unsigned int max_number_of_battles;
    unsigned int health_cost_per_battle;
    double PokeDollar_cost_per_battle;
    unsigned int experience_per_battle;
    
public:
    virtual ~PokemonGym();
    PokemonGym();
    PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc);
    double GetPokeDollarCost(unsigned int battle_qty);
    unsigned int GetHealthCost(unsigned int battle_qty);
    unsigned int GetNumBattlesRemaining();
    bool IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health);
    unsigned int TrainPokemon(unsigned int battle_units);
    unsigned int GetExperiencePerBattle();
    bool Update();
    bool passed ();
    void ShowStatus();
    
};



