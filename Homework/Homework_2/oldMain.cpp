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

bool displayResult(double distance, double targetDist)    {
    if (distance - 1 < targetDist && distance + 1 > targetDist) {
        cout << "Nice hit!" << endl;
        return false;
    }
    
    else if ((distance + 1) > targetDist)  {
        cout << "You overshot by " << distance - targetDist << "m" << endl;
    }

    else if ((distance - 1) < targetDist) {
        cout << "You're short by " << targetDist - distance << "m" << endl;
    }
    cout <<"Please do try again!\n";
    return true;
}

double degToRad()   {
    double angle;
    cout << "Enter angle of elevation!\n";
    cin >> angle;

    while (angle < 0 || angle > 90) {
        cout << "That's not right, try again between 0 and 90\n";
        cin >> angle;
    }

    return angle * PI / 180;
}

double velocityCalc()   {
    double gunPow;
    cout << "Enter gunpowder amount! (in kilograms)\n";
    cin >> gunPow;
    while (gunPow <= 1)  {
        cout << "That's not right, try again (positive value)\n";
        cin >> gunPow;
    }
    return gunPow * 30; //Kilogram conversion to vel
}

double distanceCalc(double velY, double velX)   {
    return (velY/GRAVITY) * 2 * velX;
}

int seedVal()   {
    int seed = 0;
    cout << "Enter positive seed value: ";
    cin >> seed;
    while (seed <= 0)    {
        cout << "Error. Enter a POSITIVE seed value: ";
        cin >> seed;
    }
    return seed;
}