//
//  Trainer.cpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#include "Trainer.h"
#include <time.h> // included for the random number generator

Trainer::Trainer()
: GameObject('B') // Use this because it is the derived class from the base class GameObject
{
    // initianlizing and setting variables for the default constructor
    speed = 5;
    cout << "Trainer default constructed. " << endl;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    
}

Trainer::Trainer(char in_code)
: GameObject(in_code) // Use this because it is the derived class from the base class GameObject
{
    speed = 5;
    cout << "Trainer constructed." << endl;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    
}

Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
: GameObject(in_loc, in_id, in_code) // Use this because it is the derived class from the base class GameObject
{
    // This one constructs a more specific trainer
    speed = in_speed;
    name = in_name;
    cout << "Trainer constructed." << endl;
    is_at_center = false;
    is_IN_GYM = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
   
}

void Trainer::SetupDestination(Point2D dest) // sets up the destination of where the trainer wants to go

{
    destination = dest; // initializes the variable
    delta = (destination - location) * (speed / GetDistanceBetween(destination , location)); // computes delta
    
    if (state == AT_CENTER)
    {
        current_center->RemoveOneTrainer();
    }
    
    if (state == IN_GYM)
    {
        current_center->RemoveOneTrainer();
    }
    
}

bool Trainer::UpdateLocation() // updates the location of the trainer (used after moving)
{
    if((fabs(destination.x - location.x) <= fabs(delta.x)) && (fabs(destination.y - location.y) <= fabs(delta.y)))
    {
        cout << display_code << id_num << ": I'm there!" << endl;
        location = destination;
        return true;
    }
    else
    {
        location = location + delta;
        cout << display_code << id_num << ": step..." << endl;
        PokeDollars = PokeDollars + GetRandomAmountOfPokeDollars();
        if (health != 0)
        {
        health = health - 1;
        }
        return false;
    }
}

void Trainer::StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if(GetDistanceBetween(location, dest) == 0) // there would be no change in either direction
    {
        cout << display_code << id_num << ": I'm already there. See?" << endl;
    }
    else if(state == FAINTED)
    {
       cout << display_code << id_num << ": My pokemon have fainted. I may move but you cannot see me." << endl;
    }
    else
    {
        PokeDollars += 10;
        state = MOVING;
        cout << display_code << id_num << ": On my way." << endl;
    }
}

void Trainer::StartMovingToGym(PokemonGym* gym)
{
    current_gym = gym;
    SetupDestination(gym->GetLocation()); // use the pointer to access the location of the gym
    if(GetDistanceBetween(location, destination) == 0) // in the scenerio where you are already in the gym
    {
        state = IN_GYM;
        current_gym = gym;
        cout << display_code << id_num << ": I am already at the PokemonGym!" << endl;
    }
    else if(state == FAINTED)
    {
        cout << display_code << id_num << ": My Pokemon have fainted so I can't move to gym... " << endl;
        
    }
    else
    {
        PokeDollars += 10;
        state = MOVING_TO_GYM;
        cout << display_code << id_num << ": on my way to gym " <<  gym->GetId();
    }
}

void Trainer::StartMovingToCenter(PokemonCenter* center)
{
    current_center = center;
    SetupDestination(center->GetLocation()); // use pointer to acccess the location of the center
    if(GetDistanceBetween(location, destination) == 0)
    {
        state = AT_CENTER;
        current_center = center; // setting the current center to the center they are in
        cout << display_code << id_num << ": I am already at the Center! " << endl;
            }
    else if(state == FAINTED)
    {
        cout << display_code << id_num << ": My pokemon have fainted so I should have gone to the center.." << endl;

    }
    else
    {
        PokeDollars += 10;
        state = MOVING_TO_CENTER;
        cout << display_code << id_num << ": On my way to Center " << center->GetId() << endl;
    }
}

void Trainer::StartBattling(unsigned int num_battles)
{
    if(state == FAINTED)
    {
        cout << display_code << id_num << ": My Pokemon have fainted so no more battles for me... " << endl;
    }
    else if(state != IN_GYM)
    {
        cout << display_code << id_num << ": I can only battle in a PokemonGym!" << endl;
    }
    else if(PokeDollars < current_gym->GetPokeDollarCost(num_battles)) // using current_gym pointer
    {
        cout << display_code << id_num << ": Not enough money for battles" << endl;
    }
    else if(current_gym->GetNumBattlesRemaining() < num_battles)
    {
        cout << display_code << id_num << ": Can't battle! This PokemonGym has no more trainers to battle" << endl;
    }
    else
    {
        cout << display_code << ": Started to battle at the PokemonGym " << current_gym->GetId() << " with " << current_gym->GetNumBattlesRemaining() << " battles " << endl;
        state = BATTLING_IN_GYM;
        battles_to_buy = num_battles;
        
    }
    
}

void Trainer::StartRecoveringHealth(unsigned int num_potions)
{

    if(current_center->CanAffordPotion(num_potions , PokeDollars) == false) // once again using the current_center pointer
    {
        cout << display_code << id_num << ": Not enough money to recover health. " << endl;
    }
    else if(current_center->HasPotions() == false)
    {
        cout << display_code << id_num << ": Cannot recover! No potion remaining in this Pokemon Center " << endl;
    }
    else if(state != AT_CENTER)
    {
        cout << display_code << id_num << ": I can only recover health at a Pokemon Center! " << endl;
    }
    else
    {
        cout << display_code << id_num << ": Started recovering " << num_potions << " potions at Pokemon Center " << current_center->GetId() << endl;
        unsigned int potions_to_buy = current_center->DistributePotion(num_potions);
        health = health + (5 * potions_to_buy);
    }
}

void Trainer::Stop()
{
    state = STOPPED;
    cout << display_code << id_num << ": Stopping..." << endl;
}


bool Trainer::HasFainted()
{
    if(health == 0)
    {
        state = FAINTED;
        return true;
    }
    else
    {
        return false;
    }
}

bool Trainer::ShouldBeVisible()
{
    if(state == FAINTED)
        return false;
    else
        return true;
}


void Trainer::ShowStatus()
{
    cout << name << " status: ";
    GameObject::ShowStatus();
    switch(state)
    {
        case 0:
            cout << "stopped" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 1:
            cout << "moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 6:
            cout << "heading to PokemonGym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 5:
            cout << "heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 4:
            cout << "inside PokemonGym " << current_gym->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 3:
            cout << "inside PokemonCenter " << current_center->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 7:
            cout << "battling in PokemonGym " << current_gym->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 8:
            cout << "recovering health in Pokemon Center " << current_center->GetId() << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            break;
        case 2:
            cout << "Fainted" << endl;
            
    }
}


bool Trainer::Update()
{
    switch(state)
    {
        case 0: //stopped
        {
            return false;
            break;
        }

        case 1: //moving
        {
            if(UpdateLocation() == true) //?
            {
                state = STOPPED;
                return true;
                break;
            }
            else
            {
                state = MOVING; //is this necessary?
                return false;
                break;
            }
        }

        case 6: //moving_to_gym
        {
            if(UpdateLocation() == true)
            {
                current_gym->AddOneTrainer(); //testing...worked!!

                state = IN_GYM;
                return true;
                break;
            }
            else
            {
                state = MOVING_TO_GYM;
                return false;
                break;
            }
        }

        case 5: //moving to center
        {
            if(UpdateLocation() == true)
            {
                current_center->AddOneTrainer(); //testing...worked!!

                state = AT_CENTER;
                return true;
                break;
            }
            else
            {
                state = MOVING_TO_CENTER;
                return false;
                break;
            }
        }

        case 4: //in gymn
        {
            return false;
            break;
        }

        case 3: //at center
        {
            return false;
            break;
        }

        case 7: //battling in gym
        {
            unsigned int current_health_cost =  current_gym->GetHealthCost(battles_to_buy);
            health = health - current_health_cost;//? reduce Trainer health based on total health cost for the current gym request

            unsigned int current_dollar_cost = current_gym->GetPokeDollarCost(battles_to_buy);
            PokeDollars = PokeDollars - current_dollar_cost;

            unsigned int current_experience_gain = current_gym->TrainPokemon(battles_to_buy);
            experience = experience + current_experience_gain;

            if(battles_to_buy <= 1)
                cout << "** " << name << " completed " << battles_to_buy << " battle! **" << endl;
            else
                cout << "** " << name << " completed " << battles_to_buy << " battles! **" << endl;

            cout << "** " << name << " gained " << current_experience_gain << " experiences! **" << endl;

            state = IN_GYM;
            //state = BATTLING_IN_GYM;
            return true;
            break;
        }

        case 8: //recovering_health
        {

            unsigned int healthpoints_recovered = potions_to_buy * 5;
            
            unsigned int current_dollar_cost = current_center->GetPokeDollarCost(potions_to_buy);

            PokeDollars = PokeDollars - current_dollar_cost;

            cout << "** " << name << " recovered " << healthpoints_recovered << " health! **" << endl;
            if(potions_to_buy <= 1)
            {
                cout << "** " << name << " bought " << potions_to_buy << " potion! **" << endl;
            }
            else
                cout << "** " << name << " bought " << potions_to_buy << " potions! **" << endl;

            state = AT_CENTER;
            return true;
            break;
        }

        default:
        {
            state = STOPPED;
            return false;
        }
    }
}

double GetRandomAmountOfPokeDollars()
{
    srand(time(NULL));
        float rando = static_cast<float>(rand()) / static_cast<float>(RAND_MAX/2.0);
        return rando;
}

string Trainer::GetName() // gets the name of the trainer
{
    return name;
}

Trainer::~Trainer()
{
    cout << "Trainer destructed" << endl;
}
