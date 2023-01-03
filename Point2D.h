//
//  Point2D.hpp
//  EC327_PA3
//
//  Created by Brennan Mahoney on 11/3/22.
//



#pragma once

#include <stdio.h>
#include <iostream>
using namespace std;
#include <string>
#include "Vector2D.h" // need this because vector2d is used


class Point2D
{
public:
    double x;
    double y;
    Point2D();
    Point2D(double in_x, double in_y);
    
};



 const Point2D operator+(const Point2D& left, const Vector2D& right);

 const Vector2D operator-(const Point2D& left, const Point2D& right);

 ostream& operator << (ostream& left, const Point2D& right) ;

double GetDistanceBetween(Point2D, Point2D);
