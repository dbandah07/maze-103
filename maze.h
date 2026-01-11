/* 
maze.h
*/

#ifndef MAZE_H
#define MAZE_H

// Class that stores the maze and performs
// operations on the maze
class Maze {
public:
    Maze();
    ~Maze();
    // Intializes the maze from the given file.
    // Expects the appropriate format from the assignment
    // Returns true, if there was an error reading the file,
    // false otherwise
    bool read_maze(char* filename);
    // Prints the maze to cout using the format
    // specified in the assignment
    void print_maze() const;

    
    // Add any other desired functions
    bool valid_startAndEnd();
    bool valid_characters();
    
    bool solve_maze ();


private:
    // Add private data members and private functions here
    int rows, columns;
    char** maze;
};

#endif
