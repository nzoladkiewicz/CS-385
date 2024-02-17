/*******************************************************************************
 * Name        : waterjugpuzzle.cpp
 * Author      : Natalie Zoladkiewicz
 * Date        : 10/21/2023
 * Description : Solve the famous water jug puzzle using BFS.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>
#include <sstream>
#include <queue>

using namespace std;


struct State {    
  int a, b, c;    
  string directions;    
  State *parent;

  State(int _a, int _b, int _c, string _directions) :        
    a{_a}, b{_b}, c{_c}, directions{_directions}, parent{nullptr} { }    
  
  // String representation of state in tuple form.
  string to_string() {        
    ostringstream oss;        
    oss << directions << " (" << a << ", " << b << ", " << c << ")";        
    return oss.str();    
  }

  bool stateEquals(const State* state) const {
    return state->a == a && state->b == b && state->c == c;
  }

};

bool stateVisited(State *s, const vector<vector<bool>>& matrix) {
  return matrix[s->a][s->b];
}


vector<State*> pour(State* state, int capA, int capB, int capC){
  vector<State*> storeStates;
  // C -> A
    if (state->a < capA && state->c != 0) {
      int capPoured = min(state->c, capA - state->a);
      string gallons = capPoured == 1 ? "gallon" : "gallons";
      string means = "Pour " + to_string(capPoured) + " " + gallons + " from C to A.";
      State* nextState = new State(state->a + capPoured, state->b, state->c - capPoured, means);
      nextState->parent = state;
      storeStates.push_back(nextState);
    }


    // B -> A
    if (state->a < capA && state->b != 0) {
      int capPoured = min(state->b, capA - state->a);
      string gallons = capPoured == 1 ? "gallon" : "gallons";
      string means = "Pour " + to_string(capPoured) + " " + gallons + " from B to A.";
      State* nextState = new State(state->a + capPoured, state->b - capPoured, state->c, means);
      nextState->parent = state;
      storeStates.push_back(nextState);
    }


    // C -> B
    if (state->b < capB && state->c != 0) {
      int capPoured = min(state->c, capB - state->b);
      string gallons = capPoured == 1 ? "gallon" : "gallons";
      string means = "Pour " + to_string(capPoured) + " " + gallons + " from C to B.";
      State* nextState = new State(state->a, state->b + capPoured, state->c - capPoured, means);
      nextState->parent = state;
      storeStates.push_back(nextState);
    }


    // A -> B
    if (state->b < capB && state->a != 0) {
      int capPoured = min(state->a, capB - state->b);
      string gallons = capPoured == 1 ? "gallon" : "gallons";
      string means = "Pour " + to_string(capPoured) + " " + gallons + " from A to B.";
      State* nextState = new State(state->a - capPoured, state->b + capPoured, state->c, means);
      nextState->parent = state;
      storeStates.push_back(nextState);
    }


    // B -> C
    if (state->c < capC && state->b != 0) {
      int capPoured = min(state->b, capC - state->c);
      string gallons = capPoured == 1 ? "gallon" : "gallons";
      string means = "Pour " + to_string(capPoured) + " " + gallons + " from B to C.";
      State* nextState = new State(state->a, state->b - capPoured, state->c + capPoured, means);
      nextState->parent = state;
      storeStates.push_back(nextState);
    }


    // A -> C
    if (state->c < capC && state->a != 0) {
      int capPoured = min(state->a, capC - state->c);
      string gallons = capPoured == 1 ? "gallon" : "gallons";
      string means = "Pour " + to_string(capPoured) + " " + gallons + " from A to C.";
      State* nextState = new State(state->a - capPoured, state->b, state->c + capPoured, means);
      nextState->parent = state;
      storeStates.push_back(nextState);
    }
    return storeStates;
}

State* bfs(int capacityA, int capacityB, int capacityC, State* goalState){
  vector<vector<bool>> hasVisited(capacityA + 1, vector<bool>(capacityB + 1, false));
  queue<State*> stateQueue;
  State* initialState = new State(0, 0, capacityC, "Initial state.");
  initialState->parent = nullptr;
  stateQueue.push(initialState);
  while (!stateQueue.empty()) {
    State* currentState = stateQueue.front();
    stateQueue.pop();
    if (currentState->stateEquals(goalState)) {
      return currentState;
    }
    if (!stateVisited(currentState, hasVisited)) {
      hasVisited[currentState->a][currentState->b] = true;
      vector<State*> possibleNextStates = pour(currentState, capacityA, capacityB, capacityC);

      for (State* nextState : possibleNextStates) {
        stateQueue.push(nextState);
      }
    }
  }
  delete initialState;
  return new State(-1, -1, -1, "NONE");
}

string detailed_error(int index, string argument) {
    string error = "Error: Invalid ";

    if (index >= 1 && index <= 3) {
        error += "capacity '" + argument + "' for jug ";
        error += (index == 1) ? "A." : (index == 2) ? "B." : "C.";
    } else {
        error += "goal '" + argument + "' for jug ";
        error += (index == 4) ? "A." : (index == 5) ? "B." : "C.";
    }

    return error;
}

void displaySolution(State* finalState) {
    if(finalState->a == -1 && finalState->b == -1 && finalState->c == -1){
        cout << "No solution." << endl;
        return;
    }

    vector<State*> stateOrder;

    while(finalState != nullptr){
        stateOrder.insert(stateOrder.begin(), finalState);
        finalState = finalState->parent;
    }

    for(State* state : stateOrder){
        cout << state->to_string() << endl;
    }
}

int main(int argc, char * const argv[]) {

  int capA, capB, capC, goalA, goalB, goalC;
  istringstream iss1;

  if(argc != 7){
    cout << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
    return 1;
  }

  for(int i = 1; i < 7; i++){
    int n;
    iss1.str(argv[i]);
    if(!(iss1 >> n)){
      iss1.clear();
      iss1.str(argv[i]);
      string ar;
      iss1 >> ar;

      cout << detailed_error(i, ar) << endl;
      return 1;
    }
    if(n < 0){
      cout << detailed_error(i, to_string(n)) << endl;
      return 1;
    }
    if(n == 0){
      if(i <= 3 && i >= 1){
        cout << detailed_error(i, to_string(n)) << endl;
        return 1;
      }
    }
    iss1.clear();
  }

  istringstream iss2;
  istringstream iss3;
  istringstream iss4;
  istringstream iss5;
  istringstream iss6;
  istringstream iss7;

  iss2.str(argv[1]);
  iss2 >> capA;

  iss3.str(argv[2]);
  iss3 >> capB;

  iss4.str(argv[3]);
  iss4 >> capC;

  iss5.str(argv[4]);
  iss5 >> goalA;

  iss6.str(argv[5]);
  iss6 >> goalB;
  
  iss7.str(argv[6]);
  iss7 >> goalC;

  if(goalA > capA){
    cout << "Error: Goal cannot exceed capacity of jug A." << endl;
    return 1;
  }

  if(goalB > capB){
    cout << "Error: Goal cannot exceed capacity of jug B." << endl;
    return 1;
  }

  if(goalC > capC){
    cout << "Error: Goal cannot exceed capacity of jug C." << endl;
    return 1;
  }

  if((goalA + goalB + goalC) != capC){
    cout << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
    return 1;
  }

  State* goalReached = bfs(capA, capB, capC, new State(goalA, goalB, goalC, "Goal state."));
  displaySolution(goalReached);

  delete goalReached;
  return 0;
}
