#pragma once
#ifndef CANNON_H
#define CANNON_H
#include <iostream>
#include <cmath>
#include <iomanip>
#define GRAVITY 9.81
#define PI 3.141592653589793238463
using namespace std;

class Cannon    {
private:
    int distance;
    int target;
    int velY;
    int velX;
public:
    Cannon();
    bool displayResult(double distance, double target);
    double degToRad();
    double velocityCalc();
    double distanceCalc(double velY, double velX);
};


#endif