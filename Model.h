//
//  Model.hpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#pragma once

#include <iostream>
#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"
#include "View.h"

using namespace std;

class Model
{
private:
    int time;
    GameObject * object_ptrs[10];
    int num_objects;
    Trainer * trainer_ptrs[10];
    int num_trainers;
    PokemonCenter * center_ptrs[10];
    int num_centers;
    PokemonGym * gym_ptrs[10];
    int num_gyms;
    
public:
    Model();
    ~Model();
    Trainer * GetTrainerPtr(int id);
    PokemonCenter * GetPokemonCenterPtr(int id);
    PokemonGym * GetPokemonGymPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
};

