/*
maze.cpp
*/

#include <iostream>
#include "maze.h"
using namespace std;


// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
  if(argc < 2)
  {
      cout << "Please provide a maze input file" << endl;
      return 0;
  }
  const char* invalid_char_msg = "Error, invalid character.";
  const char* invalid_maze_file_msg = "Invalid maze file.";
  const char* invalid_maze_msg = "Invalid maze start or finish.";
  const char* no_path_msg = "No path could be found!";

  Maze m;
  if (m.read_maze(argv[1])) {
      cout << invalid_maze_file_msg << endl;
      return 0;     // ALWAYS RETURN 0 from this program.

  }

  // m.print_maze();

  if (m.valid_characters() == false) {
    cout << invalid_char_msg << endl;
  }

  if (m.valid_startAndEnd() == false) {
    cout << invalid_maze_msg << endl;
  }

  if(m.solve_maze() == false) {
    cout << no_path_msg << endl;
  }
  else {
    // cout << "DEBUG: " << "Maze Solved!" << endl;
    m.print_maze();
  }

  return 0;
}