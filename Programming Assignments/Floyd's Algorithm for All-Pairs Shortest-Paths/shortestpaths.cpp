/*******************************************************************************
 * Filename: shortestpaths.cpp
 * Author  : Natalie Zoladkiewicz
 * Version : 1.0
 * Date    : December 3, 2023
 * Description: Solves all pairs shortest paths problem with Floyd's algorithm
 * Pledge  : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <utility>
#include <fstream>
#include <climits>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <queue>
using namespace std;

string findPath(long** matrix, long start, long end) {
    if (matrix[start][end] != LONG_MAX) {
        std::string path = findPath(matrix, start, matrix[start][end]) + findPath(matrix, matrix[start][end], end);
        return path;
    } else {
        return " -> " + std::string(1, static_cast<char>(65 + end));
    }
}

int len(long num) {
    int count = 1;
    while (num > 9) {
        num /= 10;
        count++;
    }
    return count;
}

/**
 * Displays the matrix on the screen formatted as a table. 
 */ 
void display_table(long** const matrix, int const count_vertices, const string &label, const bool use_letters = false) { 
    cout << label << endl; 
    long max_val = 0; 
    long INF = std::numeric_limits<long>::max();
    for (int i = 0; i < count_vertices; i++) { 
        for (int j = 0; j < count_vertices; j++) { 
            long cell = matrix[i][j]; 
            if (cell < INF && cell > max_val) { 
                max_val = matrix[i][j]; 
            } 
        } 
    } 
    int max_cell_width = use_letters ? len(max_val) : len(max(static_cast<long>(count_vertices), max_val)); 
    cout << ' '; 
    for (int j = 0; j < count_vertices; j++) { 
        cout << setw(max_cell_width + 1) << static_cast<char>(j + 'A'); 
    } 
    cout << endl; 
    for (int i = 0; i < count_vertices; i++) { 
        cout << static_cast<char>(i + 'A'); 
        for (int j = 0; j < count_vertices; j++) { 
            cout << " " << setw(max_cell_width); 
            if (matrix[i][j] == INF) { 
                cout << "-"; 
            } else if (use_letters) { 
            cout << static_cast<char>(matrix[i][j] + 'A'); 
            } else { 
                cout << matrix[i][j]; 
            } 
        } 
        cout << endl; 
    } 
    cout << endl; 
}

void display_paths(long** matrix, long** intermediate_matrix, int count_vertices) {
    for (int i = 0; i < count_vertices; ++i) {
        for (int j = 0; j < count_vertices; ++j) {
            std::cout << static_cast<char>('A' + i) << " -> " << static_cast<char>('A' + j);

            if (i == j) {
                std::cout << ", distance: 0, path: " << static_cast<char>('A' + i) << '\n';
            } else if (matrix[i][j] == LONG_MAX) {
                std::cout << ", distance: infinity, path: none\n";
            } else {
                std::cout << ", distance: " << matrix[i][j] << ", path: " << static_cast<char>('A' + i);

                if (intermediate_matrix[i][j] == LONG_MAX) {
                    std::cout << " -> " << static_cast<char>('A' + j) << '\n';
                } else {
                    std::string path = findPath(intermediate_matrix, i, j);
                    std::cout << path << '\n';
                }
            }
        }
    }
}

bool isNumber(string str){
  for (size_t i = 0; i < str.size(); ++i) {
    char some_char = str[i];
    if (!isdigit(some_char)){
        return false;
    }
  }
  return true;
}

void deleteMatrix(long **matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
        matrix[i] = nullptr;
	}
	delete[] matrix;
    matrix = nullptr;
}

void floyds_algo(long** path, long** intermediate_matrix, int count_vertices) {
    for (int k = 0; k < count_vertices; k++) {
        for (int i = 0; i < count_vertices; i++) {
            for (int j = 0; j < count_vertices; j++) {
                bool feas_path = (path[i][k] != LONG_MAX && path[k][j] != LONG_MAX);
                if (feas_path) {
                    long poten_dis = path[i][k] + path[k][j];
                    if (poten_dis < path[i][j]) {
                        intermediate_matrix[i][j] = k;
                        path[i][j] = poten_dis;
                    }
                }
            }
        }
    }
}

// Helper
vector<string> split_string(const string& line) {
    istringstream iss(line);
    vector<string> parts;
    string part;
    while (iss >> part) {
        parts.push_back(part);
    }
    return parts;
}

// Helper
bool validate_edges(const string& line, long** matrix, int count_vertices, unsigned int& line_number) {
    vector<string> edge_parts = split_string(line);
    int baseline = 0;
    int first = 0;

    if (edge_parts.size() != 3) {
        cerr << "Error: Invalid edge data '" << line << "' on line " << line_number << "." << endl;
        return false;
    }

    char start = edge_parts[first][first];
    char end = edge_parts[1][first];
    string weightstr = edge_parts[2];

    if (start < 'A' || start > ('A' + count_vertices - 1) || edge_parts[0].length() > 1) {
        cerr << "Error: Starting vertex '" << edge_parts[0] << "' on line " << line_number << " is not among valid values A-" << char('A' + count_vertices - 1) << ".";
        cout << endl;
        return false;
    }

    if (end < 'A' || end > ('A' + count_vertices - 1) || edge_parts[1].length() > 1) {
        cerr << "Error: Ending vertex '" << edge_parts[1] << "' on line " << line_number << " is not among valid values A-" << char('A' + count_vertices - 1) << ".";
        cout << endl;
        return false;
    }

    if (!isNumber(weightstr)) {
        cerr << "Error: Invalid edge weight '" << edge_parts[2] << "' on line " << line_number << ".";
        cout << endl;
        return false;
    }

    int weight = stoi(weightstr);
    if (weight <= baseline) {
        cerr << "Error: Invalid edge weight '" << edge_parts[2] << "' on line " << line_number << ".";
        cout << endl;
        return false;
    }

    matrix[start - 'A'][end - 'A'] = weight;
    ++line_number;
    return true;
}


int main(int argc, const char *argv[]) {
    // Make sure the right number of command line arguments exist.
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    // Create an ifstream object.
    ifstream input_file(argv[1]);
    // If it does not exist, print an error message.
    if (!input_file) {
        cerr << "Error: Cannot open file '" << argv[1] << "'." << endl;
        return 1;
    }
    // Add read errors to the list of exceptions the ifstream will handle.
    input_file.exceptions(ifstream::badbit);
    string line;
    try {
        unsigned int line_number = 1;
        int count_vertices = 0; 
        // Use getline to read in a line.
        // See http://www.cplusplus.com/reference/string/string/getline/
        getline(input_file,line);
        if (!isNumber(line)) {
            cerr << "Error: Invalid number of vertices '" << line << "' on line 1." << endl;
            return -1;
        }
        count_vertices = stoi(line);
        if (count_vertices < 1 || count_vertices > 26) {
          cerr << "Error: Invalid number of vertices '" << count_vertices << "' on line 1." << endl;
          return -1;
        }
      
      long** matrix = new long*[count_vertices];
        for (int i = 0; i < count_vertices; i++) {
          matrix[i] = new long[count_vertices];
          for (int j = 0; j < count_vertices; j++) {
            if (j == i) {
                matrix[i][j] = 0;
            }
            else {
              matrix[i][j] = LONG_MAX;
            }
          }
        }
        ++line_number;
        while (getline(input_file, line)) {
            if (!validate_edges(line, matrix, count_vertices, line_number)) {
                deleteMatrix(matrix, count_vertices);
                return -1;
            }
        }
        // Don't forget to close the file.
        input_file.close();
        display_table(matrix,count_vertices,"Distance matrix:", false);
        long** dist = new long*[count_vertices];
        long** intermediate_matrix = new long*[count_vertices];
        for (int i = 0; i < count_vertices; ++i) {
            dist[i] = new long[count_vertices];
            memcpy(dist[i], matrix[i], count_vertices * sizeof(long));
        }
        for (int i = 0; i < count_vertices; ++i) {
            intermediate_matrix[i] = new long[count_vertices];
            for (int j = 0; j < count_vertices; ++j) {
                intermediate_matrix[i][j] = LONG_MAX;
            }
        }

        floyds_algo(dist, intermediate_matrix, count_vertices);
        display_table(dist,count_vertices,"Path lengths:", false);
        display_table(intermediate_matrix,count_vertices,"Intermediate vertices:", true);
        display_paths(dist, intermediate_matrix, count_vertices);

        // Deallocating memory
        deleteMatrix(matrix,count_vertices);
        deleteMatrix(dist,count_vertices);
        deleteMatrix(intermediate_matrix,count_vertices);
      
    } catch (const ifstream::failure &f) {
        cerr << "Error: An I/O error occurred reading '" << argv[1] << "'.";
        return 1;
    }
    return 0;
}
