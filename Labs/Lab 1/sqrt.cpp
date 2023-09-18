/*******************************************************************************
* Filename: sqrt.cpp
* Author : Natalie Zoladkiewicz
* Version : 1.0
* Date : 09/07/2023
* Description: Basic algorithm to calculate sqrt using Newton's method.
* Pledge : I pledge my honor that I have abided by the Stevens Honor System.
****************************************************************************/

#include <iostream>
#include <sstream>
#include <limits> 
#include <iomanip>
using namespace std;

double sqrt(double num, double epsilon) {
    double last_guess = num;
    double next_guess = (last_guess + (num / last_guess)) / 2;
    int x = 0; 
    int y = 1;
    
    // Handling incorrect user inputs
    if (num < x) {
        return numeric_limits<double>::quiet_NaN();
    }

    if (num == x || num == y) {
        return num;
    }

    // Repeating the process until the epsilon precision is satisfied
    while (abs(last_guess - next_guess) >= epsilon) {
        last_guess = next_guess;
        next_guess = (last_guess + (num / last_guess)) / 2;
    }

    return next_guess;
}

int main(int argc, char* argv[]) {
    double m;
    double n = 1e-7;
    int min_input = 2;
    int max_input = 3;

    istringstream iss1;
    istringstream iss2;

    // Checking that the user provided correct number of command-line arguments
    if (!(argc == min_input || argc == max_input)) {
        cerr << "Usage: " << argv[0] << " <value> [epsilon]" << endl;
        return 1;
    }

    // Checking that the input is a double
    iss1.str(argv[1]);
    if (!(iss1 >> m)) {
        cerr << "Error: Value argument must be a double." << endl;
        return 1;
    }

    // Checking the validity of the 3rd argument
    if (argc == max_input) {
        iss2.str(argv[2]);

        if (!(iss2 >> n) | (n <= 0)) {
            cerr << "Error: Epsilon argument must be a positive double." << endl;
            return 1;
        }
    }

    cout << fixed << setprecision(8) << sqrt(m, n) << endl;
    return 0;
}