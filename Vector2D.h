//
//  Vector2D.hpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

//#ifndef Vector2D_hpp
//#define Vector2D_hpp

#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;
//#endif /* Vector2D_hpp */

class Vector2D
{
public:
    double x;
    double y;
    Vector2D();
    Vector2D(double in_x, double in_y);
    
};

 const Vector2D operator*(const Vector2D& left, double d);

 const Vector2D operator/(const Vector2D& left, double d);

 ostream& operator << (ostream& left, const Vector2D& right) ;
