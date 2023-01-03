//
//  Point2D.cpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//

#include "Point2D.h"
//#include "Vector2D.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Point2D::Point2D() // default constructor
{
    x = 0.0;
    y = 0.0;
}

Point2D::Point2D(double in_x, double in_y) // constructor
{
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double xundersquare = pow(p1.x-p2.x, 2);
    double yundersquare = pow(p1.y-p2.y, 2);
    
    return sqrt(xundersquare + yundersquare); 
}


const Point2D operator+(const Point2D &left, const Vector2D &right) // + overloaded operator
{
    double x;
    double y;
    x = left.x + right.x;
    y = left.y + right.y;
    Point2D result(x,y);
    return result;
}

const Vector2D operator-(const Point2D &left, const Point2D &right) // - overloaded operator
{
    double x;
    double y;
    x = left.x - right.x;
    y = left.y - right.y;
    Vector2D result(x,y);
    return result;
}


ostream& operator << (ostream& left, const Point2D& right) // do this so that cout can be used
{
left << "(" <<right.x << ","  << right.y << ")" << endl;
return left;
}



