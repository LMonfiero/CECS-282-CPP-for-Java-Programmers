#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



double Blah(int *p) {
    *p = *p + 5;
    double local = *p / 2;
    return local;
}

int SolveQuadratic(double a, double b, double c, double *Solution1, double *Solution2) {
    *Solution1 = (-b + sqrt((b*b) - (4 * a * c))) / (2 * a);
    *Solution2 = (-b - sqrt((b*b) - (4 * a * c))) / (2 * a);
    int numberOfSol = -1;
    //Use Discriminant to see how many solutions there are
    if ((b*b) - (4 * a * c) == 0) {
        if (*Solution1 == *Solution2)   {
            *Solution2 = 0;
        }
        return 1;
    }

    else if ((b*b) - (4 * a * c) < 0) {
        *Solution1 = 0;
        *Solution2 = 0;
        return 0;
    }

    else if ((b*b) - (4 * a * c) > 0) {
        return 2;
    }
    return numberOfSol;//should never get to this
}

void FA(vector<int> &p1)    {
    p1.pop_back();
    p1.push_back(0);
}

void FB(vector<int> p2) {
    FA(p2);
}

int main()  {
    // //Number #1:
    // int x = 10;
    // int *y = &x; 
    // double z = Blah(y);
    // cout << x << endl << z << endl;

    //Number #2:
    double xSolution1, xSolution2;
    double a, b, c;
    //Scenario 1
    a = 1;
    b = 2;
    c = 1;
    int numberOfSolutions = SolveQuadratic(a, b, c, &xSolution1, &xSolution2);
    cout << numberOfSolutions << " solutions" << endl;
    cout << "Solution #1: " << xSolution1 << endl;
    cout << "Solution #2: " << xSolution2 <<  endl << endl;
    //Scenario 2
    a = 1;
    b = 0;
    c = 1;
    numberOfSolutions = SolveQuadratic(a, b, c, &xSolution1, &xSolution2);
    cout << numberOfSolutions << " solutions" << endl;
    cout << "Solution #1: " << xSolution1 << endl;
    cout << "Solution #2: " << xSolution2 <<  endl << endl;
    //Scenario 3
    a = 1;
    b = -3;
    c = -4;
    numberOfSolutions = SolveQuadratic(a, b, c, &xSolution1, &xSolution2);
    cout << numberOfSolutions << " solutions" << endl;
    cout << "Solution #1: " << xSolution1 << endl;
    cout << "Solution #2: " << xSolution2 <<  endl << endl;

    // //Number #3
    // string a = "hello";
    // string b = a;
    // string *c = &a;
    // string &d = *c;
    // string e = *c;

    //Number #5
    // int x = 0;
    // vector<int> v = {1, 2, 3, 4};
    // FB(v);
    // cout << v.size() << "     " << v[3];
}