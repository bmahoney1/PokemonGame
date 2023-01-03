//
//  Vector2D.cpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#include "Vector2D.h"
#include <math.h>
#include <iostream>
using namespace std;

Vector2D::Vector2D() // default constructor
{
    x = 0.0;
    y = 0.0;
}

Vector2D::Vector2D(double in_x, double in_y) // constructor
{
    x = in_x;
    y = in_y;
}



const Vector2D operator*(const Vector2D &left, double d) // * overloaded operator
{
    double x;
    double y;
    x = left.x * d;
    y = left.y * d;
    Vector2D result(x,y);
    return result;
}

const Vector2D operator/(const Vector2D &left, double d) // / overloaded operator
{
    double x;
    double y;
    x = left.x / d;
    y = left.y / d;
    Vector2D result(x,y);
    return result;
}

ostream& operator << (ostream& left, const Vector2D& right) // do this so that cout can be used
{
left << "<" <<right.x << ","  << right.y << ">" << endl;
return left;
}

// we use these overloaded operators later in the program
