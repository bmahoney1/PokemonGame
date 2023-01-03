//
//  Model.cpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#include "Model.h"

Model::Model()
{
    time = 0;
    
    Point2D position1(5,1);
    Trainer* trainer1 = new Trainer ("Ash",1, 'T', 1, position1);
    object_ptrs[0] = trainer1;
    trainer_ptrs[0] = trainer1;

    Point2D position2(10,1);
    Trainer* trainer2 = new Trainer ("Misty",2, 'T', 2, position2);
    object_ptrs[1] = trainer2;
    trainer_ptrs[1] = trainer2;
    
    Point2D position3(1,20);
    PokemonCenter* center1 = new PokemonCenter(1,1,100, position3);
    object_ptrs[2] = center1;
    center_ptrs[0] = center1;
    
    Point2D position4(10,20);
    PokemonCenter* center2 = new PokemonCenter(2,2,200, position4);
    object_ptrs[3] = center2;
    center_ptrs[1] = center2;
    
    Point2D position5(0,0);
    PokemonGym* gym1 = new PokemonGym(1, 1 , 2, 3, 1, position5);
    object_ptrs[4] = gym1;
    gym_ptrs[0] = gym1;
    
    Point2D position6(5,5);
    PokemonGym* gym2 = new PokemonGym(2, 5 , 7.5, 4, 2, position6);
    object_ptrs[5] = gym2;
    gym_ptrs[1] = gym2;
    
    num_objects = 6;
    num_trainers = 2;
    num_centers = 2;
    num_gyms = 2;
    
    cout << "Model default constructed" << endl;
}


Model::~Model()
{
//    delete object_ptrs;
//    delete trainer_ptrs;
//    delete gym_ptrs;
//    delete center_ptrs;
    
    cout << "Model Destructed" << endl;
    
}

Trainer* Model::GetTrainerPtr(int id) // returns trainer pointer for the specific id
{
    if(trainer_ptrs[id-1] != NULL)
    {
        return trainer_ptrs[id-1];
    }
    else
    {
        return 0;
    }
}

PokemonCenter* Model::GetPokemonCenterPtr(int id) // returns pokemoncenter pointer for the specific id
{
    if(center_ptrs[id-1] != NULL)
    {
        return center_ptrs[id-1];
    }
    else
    {
        return 0;
    }
}

PokemonGym* Model::GetPokemonGymPtr(int id) // returns pokemongym pointer for the specific id
{
    if(gym_ptrs[id-1] != NULL)
    {
        return gym_ptrs[id-1];
    }
    else
    {
        return 0;
    }
}

bool Model::Update() // gives an updates on the gyms and trainers and if the game has been won or lost
{
    //increment time:
        time = time + 1;
    int gym_counter = 0;

        for(int i = 0; i < num_objects; i++)
        {
            if(object_ptrs[i]->Update() == true)
            {
                for(int j = 0; j < num_gyms; j++)
                {
                    if(gym_ptrs[j]->passed() == true)
                    {
                        gym_counter++;
                    }
                        if (gym_counter == num_gyms)
                        {
                        cout << "GAME OVER: You win! All battles done! " << endl;
                        exit(0);
                        }
                    
                }
                return true;
            }
        }

        
        int num_trainers_fainted = 0;
        for(int k = 0; k < num_trainers; k++)
        {
            if(trainer_ptrs[k]->HasFainted() == true)
            {
                num_trainers_fainted = num_trainers_fainted + 1;
            }
        }

        if(num_trainers_fainted == num_trainers)
        {
            cout << "GAME OVER: You lose! All of your Trainers' Pokemon have fainted! " << endl;
            exit(0);
        }

        return false;
    }



void Model::Display(View& view)
{

    view.Clear();

    for(int i = 0; i < num_objects; i++)
    {
        view.Plot(object_ptrs[i]);
    }

    view.Draw();
}


void Model::ShowStatus() // shows status for every object as well as the time

{

    cout << "Time: " << time << endl;

    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}
