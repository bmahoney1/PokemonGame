//
//  View.hpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#pragma once

#include <iostream>

#include "GameObject.h"
#include "Point2D.h"

using namespace std;

//constant:
const int view_maxsize = 20;

class View
{

private:

    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];
    bool GetSubscripts(int& out_x, int& out_y, Point2D location);


public:

    View();

    //function:
    void Clear();
    void Plot(GameObject* ptr);

    void Draw();


};
