#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
#define GRAVITY 9.81
#define PI 3.141592653589793238463
using namespace std;

//Louis Monfiero
//Homework 2

int seedVal();
bool displayResult(double, double);
double degToRad();
double velocityCalc();
double distanceCalc(double, double);

//ALL DECIMAL VALUES BY 2
int main() {
    int seed = seedVal();
    random_device rd;
    mt19937 engine = mt19937{seed};
    uniform_real_distribution<double> range{1, 1000};

    bool loop = true;
    double targetDist = range(engine);
    cout << "The target is " << fixed << setprecision(2) << targetDist << "m away.\n";
    while (loop)    {
        double angle, iniVelocity;
        angle = degToRad();
        iniVelocity = velocityCalc();
            
        double velY, velX;

        velY = iniVelocity * sin(angle);
        velX = iniVelocity * cos(angle);
        double distance = distanceCalc(velY, velX);
        loop = displayResult(distance, targetDist);


    }
    
}
