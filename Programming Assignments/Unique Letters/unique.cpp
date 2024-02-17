/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Natalie Zoladkiewicz
 * Date        : 9/29/23
 * Description : This program determines if a string has all unique
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>

using namespace std;
bool check_unique(const string & x) {
    unsigned int checker = 0;
    for(char z : x) {
        int bit = z - 'a';
        int shift = 1 << bit;
        if((checker & shift) > 0) {
            return false;
        }
        checker = checker | shift;
    }
    return true;
}

bool check_lowercase(const string & y) {
    for (const auto & str : y) {
        if (!(islower(str))) {
            return false;
        }
    }
    return true;
}

int main(int argc, char * const argv[]) {
    if (argc < 2 || argc > 2) {
    	cerr << "Usage: ./unique <string>" << endl;
    	return -1;
    }

    if (argc == 2) {
        string a = string(argv[1]);
        if (check_lowercase(a)) {
            
            if (!check_unique(a)) {
                cout << "Duplicate letters found." << endl;
                return -1;
            } 

            if (check_unique(a)) {
                cout << "All letters are unique." << endl;
                return -1;
            }
        } 
        if (!check_lowercase(a)) {
            cout << "Error: String must contain only lowercase letters." << endl;
            return -1;
        }
    }
    return 0;
}
