//
//  GameObject.hpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#pragma once

#include "Point2D.h"
#include "GameObject.h"
#include "Point2D.h"
// point2d and vector2d are referenced which is why they need to be included

class GameObject
{
    
protected:

    Point2D location;
    int id_num;
    char display_code;
    char state;

public:

    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    Point2D GetLocation();
    int GetId();
    char GetState();
    virtual void ShowStatus(); //declare show status to be virtual

    //destructor, made virtual so derived classes can use theirs
    virtual ~GameObject();

    // these are made virtual so that they can be used in derived classes
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;

    //added from view section
    void DrawSelf(char *ptr);

    
};
