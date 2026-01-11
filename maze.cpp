 /* 
maze.cpp
*/

#include <iostream>
#include <fstream>
#include "queue.h"
#include "maze.h"

using namespace std;


Maze::Maze() {
  // Complete this function
  rows = 0;
  columns = 0;
  maze = nullptr;

}
Maze::~Maze() {
  // Complete this function
  if (maze != nullptr) {
    for (int i = 0; i < rows; i++) {
      delete[] maze[i];
    }
    delete[] maze;
    maze = nullptr;
  }
}

// Intializes the maze from the given file.
// Expects the appropriate format from the assignment
// Returns true, if there was an error reading the file,
// false otherwise
bool Maze::read_maze(char* filename) {
  // // Complete this function
  ifstream file(filename);

  if (!file.is_open()) { // file doesn't exist
    return true;
  }

  // bool success = (file >> rows >> columns);

  if(!(file >> rows >> columns) || rows <= 0 || columns <= 0) {
    return true; // invalid dimensions;
  }

  // reading maze chars
  maze = new char*[rows];

  for(int r = 0; r < rows; r++){
    maze[r] = new char[columns];

    for(int c = 0; c < columns; c++) {
      if(!(file >> maze[r][c])) {
        for (int i = 0; i <= r; i++){
          delete[] maze[i];
        }
        delete[] maze;

        maze = nullptr;

        return true; // invalid maze data;
      }
    }
  }

  return false;
}

// Prints the maze to cout using the format
// specified in the assignment
void Maze::print_maze() const {

  if (maze == nullptr) {
    return;
  }

  cout << rows << " " << columns << endl;

  for(int i = 0; i < rows; i++) {
    for (int k = 0; k < columns; k++) {
      cout << maze[i][k];
    }
    cout << endl;
  }

}

bool Maze::solve_maze() {
  Queue c;

  Location** pre = new Location*[rows];
  bool** visitedAlready = new bool*[rows];
  // loop for location
  for (int i = 0; i < rows; i++) {
    pre[i] = new Location[columns];
    for (int k = 0; k < columns; k++) {
      pre[i][k] = {-1, -1}; // Intializes
    }
  }
  // loop for bool of visited 
  for (int i = 0; i < rows; i++) {
    visitedAlready[i] = new bool[columns];
    for (int k = 0; k < columns; k++) {
      visitedAlready[i][k] = false;
    }
  }

  Location start;
  Location end;

  // finds the start & end points
  for (int i = 0; i < rows; i++) {
    for (int k = 0; k < columns; k++) {
      char tracking = maze[i][k];
      if (tracking == 'S') {
        start = {i, k};
        c.add_to_back(start);
      }
    
      if (tracking == 'F') {
        end = {i, k};
      }
    }
  }

  // N, W, S, E;
  int directRow[] = {-1, 0, 1, 0};
  int directCol[] = {0, -1, 0, 1};

  while (c.is_empty() == false) {
    Location curr = c.remove_from_front(); // gets location of first in queue
    // cout << curr.row << " " << curr.col << endl;

    for (int i = 0; i < 4; i++) { // loops through direction cor.
      int row = curr.row + directRow[i];
      int col = curr.col + directCol[i];
      
      // checks validity, open, and not yet explored;
      if (row >= 0 && col >= 0 && col < columns && row < rows) {
        // if its at the end, retrace to find short path
        if (maze[row][col] == 'F') {
          // cout << "DEBUG: " << "maze[row][col] = " << maze[row][col] << endl;

          pre[row][col] = curr;
          Location goBack = {row, col};
          while (goBack.row != start.row || goBack.col != start.col) {
            // cout << "DEBUG: goBack = " << goBack.row << ", " << goBack.col << endl;
            
            if (pre[goBack.row][goBack.col].row == -1 || pre[goBack.row][goBack.col].col == -1) {
              // cout << "DEBUG: reached invalid." << endl;
              break;
            }

            if (maze[goBack.row][goBack.col] != 'F' && maze[goBack.row][goBack.col] != 'S'){
              // cout << "Reached star." << endl;
              maze[goBack.row][goBack.col] = '*';
            }
            goBack = pre[goBack.row][goBack.col];
          }

          // cout << "DEBUG: success in backtracking." << endl; 
  
  // delete allocated memory
          for (int i = 0; i < rows; i++) {
            delete[] pre[i];
            delete[] visitedAlready[i];
          }

          delete[] pre;
          delete[] visitedAlready;

          return true; 
        }

       if ((maze[row][col] == '.') && (!(visitedAlready[row][col]))) {
          c.add_to_back({row, col});
          pre[row][col] = curr;
          visitedAlready[row][col] = true;
        }
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    delete[] pre[i];
    delete[] visitedAlready[i];
  }

  delete[] pre;
  delete[] visitedAlready;

  return false; // no path found;

}

bool Maze:: valid_startAndEnd() {
  int start = 0;
  int end = 0;

  for (int i = 0; i < rows; i++) {
    for (int k = 0; k < columns; k++) {
      char tracking = maze[i][k];
//start & end checking; only one;
      if (tracking == 'S') {
        start++;
      }

      else if (tracking == 'F') {
        end++;
      }
    }
  }

  if (start != 1 || end != 1) {
    return false;
  }

  return true;
}

bool Maze:: valid_characters() {

  for (int i = 0; i < rows; i++) {
    for (int k = 0; k < columns; k++) {
      char tracking = maze[i][k];
      // other chars detected
      if (tracking != '.' && tracking != '#' && tracking != 'S' && tracking != 'F') {
        // cout << "invalid char: " << tracking << " at: " << i << ", " << k << endl;
        return false;
      }
    }
  }

  return true;
}