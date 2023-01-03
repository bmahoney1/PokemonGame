//
//  Building.cpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//
#include <iostream>
#include <string>
#include <math.h>

#include "Building.h"

using namespace std;



Building::Building() //default constructor
: GameObject('B')
{
    trainer_count = 0;
    cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc) // constructor for building
: GameObject(in_loc, in_Id, in_code)
{
    trainer_count = 0;
    cout << "Building constructed" << endl;
}

void Building::AddOneTrainer() // increments
{
    trainer_count++;
}

void Building::RemoveOneTrainer() // decrements
{
    trainer_count--;
}

void Building::ShowStatus() // shows the status of the building
{
    GameObject::ShowStatus();
    if(trainer_count == 1) // this is used to determine is/are
    {
        cout << trainer_count << " trainer is in this building" << endl;
    }
    else
    {
        cout << trainer_count << " trainers are in this building" << endl;
    }

}

bool Building::ShouldBeVisible()
{
    return true;
}

Building::~Building() // used as placeholder for the destructor
{
    cout << "Building destructed" << endl;
}
