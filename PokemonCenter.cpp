//
//  PokemonCenter.cpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#include <iostream>

#include "PokemonCenter.h"

using namespace std;

PokemonCenter::PokemonCenter() // default constructor
: Building()
{
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

// more detailed constructor
PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc)
: Building('C',in_id, in_loc)
{
    id_num = in_id;
    location = in_loc;
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    display_code = 'C';
    num_potions_remaining = potion_capacity;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
}

bool PokemonCenter::HasPotions() // checks to see if the center has potions
{
    if (num_potions_remaining >=1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


unsigned int PokemonCenter::GetNumPotionRemaining() // this will retrieve a single value
{
    return num_potions_remaining;
}

bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget) // compares budget w total cost
{
    double costOfPotion = potion * pokedollar_cost_per_potion;
        if(budget > costOfPotion)
        {
            return true;
        }
        else
        {
            return false;
        }
}

double PokemonCenter::GetPokeDollarCost(unsigned int potion) // finds the total cost
{
    double costOfPotion = potion * pokedollar_cost_per_potion;
    return costOfPotion;
}

// if there is enough potions remaining, this function returns the amount needed and subtracts from total
// if there is not enough, it will return the max amouunt it can, and then set remaining to 0
unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed)
{
    if (num_potions_remaining>=  potion_needed)
    {
        num_potions_remaining =  num_potions_remaining - potion_needed;
        return potion_needed;
    }
    else
    {
        unsigned int num_potions_remaining2 = num_potions_remaining;
        num_potions_remaining = 0;
        return num_potions_remaining2;
    }
}

bool PokemonCenter::Update() // this will give an update of the center
{
    if(num_potions_remaining == 0)
       {
           state = NO_POTIONS_AVAILABLE;
           display_code = 'c';
           cout << "PokemonCenter " << id_num << " has ran out of potions." << endl;
           return true;
       }
       else
       {
           return false;
       }
}

void PokemonCenter::ShowStatus() // shows the status of the center
{
    cout << "PokemonCenter Status: " << endl;
    Building::ShowStatus();
    cout << endl << "PokeDollars per potion: " << pokedollar_cost_per_potion << endl;
    cout << "Has " << num_potions_remaining << " potion(s) remaining." << endl;
}

PokemonCenter::~PokemonCenter() // destructor
{
    cout << "PokemonCenter destructed" << endl;
}
