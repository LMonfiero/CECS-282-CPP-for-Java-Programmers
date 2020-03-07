#include "Cannon.h"

bool Cannon::displayResult(double distance, double targetDist)    {
    if (distance - 1 < targetDist && distance + 1 > targetDist) {
        cout << "Nice hit!" << endl;
        return false;
    }
    
    else if ((distance + 1) > targetDist)  {
        cout << "You overshot by " << distance - targetDist << endl;
    }

    else if ((distance - 1) < targetDist) {
        cout << "You're short by " << targetDist - distance << endl;
    }
    cout <<"Please do try again!\n";
    return true;
}

double Cannon::degToRad()   {
    double angle;
    cout << "Enter angle of elevation!\n";
    cin >> angle;

    while (angle < 0 || angle > 90) {
        cout << "That's not right, try again between 0 and 90\n";
        cin >> angle;
    }

    return angle * PI / 180;
}

double Cannon::velocityCalc()   {
    double gunPow;
    cout << "Enter gunpowder amount! (in kilograms)\n";
    cin >> gunPow;
    while (gunPow <= 1)  {
        cout << "That's not right, try again (positive value)\n";
        cin >> gunPow;
    }
    return gunPow * 30; //Kilogram conversion to vel
}

double Cannon::distanceCalc(double velY, double velX)   {
    return (velY/GRAVITY) * 2 * velX;
}