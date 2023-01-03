//
//  PokemonGym.cpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#include "PokemonGym.h"

using namespace std;

PokemonGym::PokemonGym() // default constructor
: Building()
{
    display_code = 'G';
    state = NOT_DEFEATED;
    max_number_of_battles = 10;
    num_battle_remaining = max_number_of_battles;
    health_cost_per_battle = 1;
    PokeDollar_cost_per_battle = 1.0;
    experience_per_battle = 2;
    cout << "PokemonGym default constructed" << endl;
}

PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc) // constructor
: Building('G', in_id, in_loc)
{
    id_num = in_id;
    max_number_of_battles = max_battle;
    health_cost_per_battle = health_loss;
    experience_per_battle = exp_per_battle;
    PokeDollar_cost_per_battle = PokeDollar_cost;
    location = in_loc;
    num_battle_remaining = max_number_of_battles;
    display_code = 'G';
    state = NOT_DEFEATED;
    cout << "PokemonGym constructed" << endl;
    
}

double PokemonGym::GetPokeDollarCost(unsigned int battle_qty) // returns value
{
    
        return battle_qty * PokeDollar_cost_per_battle;
}

unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty) // returns value
{
    
        return battle_qty * health_cost_per_battle;
    
}

unsigned int PokemonGym::GetNumBattlesRemaining() // returns value
{
    return num_battle_remaining;
}

bool PokemonGym::IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health) // decides if their is enough money and health for battle
{
    if(budget >= (PokeDollar_cost_per_battle * battle_qty)  &&  health >= (health_cost_per_battle * battle_qty))
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int PokemonGym::TrainPokemon(unsigned int battle_units) // returns the experience gained from the number of battles (battle_units_
// of there are not enough battles remaining for requested battle units, it will just use up what is left
{
    if(battle_units <= num_battle_remaining)
    {
        num_battle_remaining = num_battle_remaining - battle_units;
        return battle_units * experience_per_battle;
    }
    else
    {
        int battler = num_battle_remaining;
        num_battle_remaining = 0;
        return battler * experience_per_battle;
    }

}

unsigned int PokemonGym::GetExperiencePerBattle() // returns value
{
    return experience_per_battle;
}

bool PokemonGym::Update()
{
    if(num_battle_remaining == 0)
    {
        
        display_code = 'g';
        state = DEFEATED;
        cout << display_code << id_num << " has been beaten" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool PokemonGym::passed() // checks to see if there are any battles remaining in the gym
{
    if (num_battle_remaining == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void PokemonGym::ShowStatus() // shows the status of the gym
{
    cout << "PokemonGymStatus: " << endl;
    Building::ShowStatus();
    cout << endl << "Max number of battles: " << max_number_of_battles;
    cout <<  endl << "Health cost per battle: " << health_cost_per_battle;
    cout << endl << "PokeDollar per battle: " << PokeDollar_cost_per_battle;
    cout << endl <<  "Experience per battle: " << experience_per_battle << endl;
    cout << num_battle_remaining << " battle(s) are remaining for this PokemonGym" << endl << endl;
    
}

PokemonGym::~PokemonGym() // destructor
{
    cout << "PokemonGym destructed" << endl;
}
