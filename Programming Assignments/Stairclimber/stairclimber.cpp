/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Natalie Zoladkiewicz
 * Date        : 10/3/23
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // From the get_ways() function from the Python file on Canvas
    vector<vector<int>> ways;
	int min_stairs = 1;
    if (num_stairs <= 0) {
    	vector<int> temp;
    	ways.push_back(temp);

    } else {
    	for (int i = min_stairs; i < 4; i++) {
    		if (num_stairs >= i) {
    			vector<vector<int>> result;
    			result = get_ways(num_stairs - i);
    			for (auto &results: result) {
    				results.insert(results.begin(), i);

    			}
    			ways.insert(ways.end(), result.begin(), result.end());
    		}
    	}
    }
    return ways;
}

void display_ways(const vector< vector<int> > &ways) {
	for (unsigned int x = 0; x < ways.size(); x++){
        unsigned int y = 10;
		if (ways.size() < y) {
			cout << x+1 << ". " << "[";
        }
        if (ways.size() >= y) {
			if (x > 8) {
				cout << x+1 << ". " << "[";
            }
			if (x <= 8) {
				cout << " " << x+1 << ". " << "[";
			}
	    }
		for (unsigned int y = 0; y < ways[x].size(); y++) {
            if (y > ways[x].size()-1) {
				cout << ways[x][y] << ", ";
			}
            if (y == ways[x].size()-1) {
				cout << ways[x][y];
			}
            if (y < ways[x].size()-1) {
				cout << ways[x][y] << ", ";
			}
		}
		cout << "]" << endl;
	}
}

int main(int argc, char * const argv[]) {
	int num_moves;
	istringstream iss;
	int lim = 2;
	if (argc < lim) {
		cerr <<  "Usage: " << argv[0] << " <number of stairs>";
		cout << endl;
		return -1;
	}
	if (argc > lim) {
		cerr << "Usage: " << argv[0] << " <number of stairs>";
		cout << endl;
		return -1;
	}
	// Directly from my sqrt.cpp assignment
	iss.str(argv[1]);
	if (!(iss >> num_moves)) {
		cerr << "Error: Number of stairs must be a positive integer." << endl;
		return -1;
	}

	if (num_moves <= 0) {
		cerr << "Error: Number of stairs must be a positive integer." << endl;
		return -1;
	}
	if(num_moves > 0){
        vector< vector<int> > total_ways = get_ways(num_moves);
		if(num_moves >= lim){
            cout << total_ways.size() << " ways to climb " << num_moves << " stairs." << endl;
        }
        if(num_moves < 1) {  
            cout << total_ways.size() << " ways to climb " << num_moves << " stairs." << endl;
        }
        if(num_moves == 1){
            cout << "1 way to climb 1 stair.";
            cout << endl;
        } 
        display_ways(total_ways); 
    }
	return 0;
}
