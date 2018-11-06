//Anton Goretsky
//CSCI 235 - Project 4
//MazeSolver.cpp
//MazeSolver implementation.

#include "MazeSolver.h"
#include <ios>
using std::string;

MazeSolver::MazeSolver(std::string input_file) {
    //fflush(stdout);
    std::ifstream file;
    try {
        file.open(input_file, std::fstream::in);
    }
    catch (int e) {
        std::cout << "Cannot read from " << input_file << "\n";
    }
    file >> maze_rows_ >> maze_columns_;
    initializeMaze(maze_rows_, maze_columns_);
    fillMaze(file);
    initializeSolution();
}

void MazeSolver::initializeMaze(int rows, int columns) {
    maze_ = new char*[rows];    
    for (int i = 0; i < rows; i++)
        maze_[i] = new char[columns];
}

void MazeSolver::fillMaze(std::ifstream& input_stream) {
    for (int x = 0; x < maze_rows_; x++) {
        for (int y = 0; y < maze_columns_; y++) {
            input_stream.ignore();
            input_stream.get(maze_[x][y]);
        }
    }
}

void MazeSolver::initializeSolution() {
    solution_ = new char*[maze_rows_];
    for (int i = 0; i < maze_rows_; i++) {
        solution_[i] = new char[maze_columns_];
    }
    copyMazetoSolution();
}

void MazeSolver::copyMazetoSolution() {
    for (int x = 0; x < maze_rows_; x++) {
        for (int y = 0; y < maze_columns_; y++) {
            solution_[x][y] = maze_[x][y];
        }
    }
    maze_ready = true;
}

MazeSolver::~MazeSolver() {
    delete [] maze_;
    maze_ = nullptr;
    delete [] solution_;
    solution_ = nullptr;
}

bool MazeSolver::mazeIsReady() {
    return maze_ready;
}

//pre: current_position is a valid position on the maze_
    //post: adds all positions extensible from current_position to backtrack_stack_
    //return: true if path was extended, false otherwise
    //called by solveMaze()
bool MazeSolver::extendPath(Position current_position) {
    bool extended = false;
    if (isExtensible(current_position, SOUTH)) {
        backtrack_stack_.push(getNewPosition(current_position, SOUTH));
        extended = true;
    }
    if (isExtensible(current_position, EAST)) {
        backtrack_stack_.push(getNewPosition(current_position, EAST));
        extended = true;
    }
    return extended;
}

//pre: old_position is a Position initialized with row and column to valid positions in maze_ and it is extensible in direction dir
    //return: a new Position on the maze moving in direction dir from old_position
    //called by extendPath()
Position MazeSolver::getNewPosition(Position old_position, direction dir) {
    if (dir == SOUTH) {
        old_position.row = old_position.row + 1;
    }
    if (dir == EAST) {
        old_position.column = old_position.column + 1;
    }
    return old_position;
}

//checks if the path can be extended in maze_ from position current_position in direction dir
    //return: true if path can be extended given current_position and dir, false otherwise
    //called by extendPath
bool MazeSolver::isExtensible(Position current_position, direction dir) {
    if (dir == SOUTH) {
        if ((current_position.row + 1 > (maze_rows_ - 1)) || maze_[current_position.row + 1][current_position.column] == '*' || maze_[current_position.row + 1][current_position.column] == 'X') {
            return false;
        }
        else {
            return true;
        } 
    }
    if (dir == EAST) {
        if ((current_position.column + 1 > (maze_columns_ - 1)) || maze_[current_position.row][current_position.column + 1] == '*' || maze_[current_position.row][current_position.column + 1] == 'X') {
            return false;
        }
        else {
            return true;
        }   
    }
    return false;
}

bool MazeSolver::solveMaze() {
    Position cur_pos = {0, 0};
    backtrack_stack_.push(cur_pos);
    solution_[cur_pos.row][cur_pos.column] = '>';

    while (!backtrack_stack_.empty()) {
        if (maze_[cur_pos.row][cur_pos.column] == '$') {
            std::cout << "Found the exit!!!\n";
            return true;
        }
    
        bool extended = extendPath(cur_pos);
    
        if (extended == true) {
            //std::cout << "EXTENDED!!!!!!!\n";
            solution_[cur_pos.row][cur_pos.column] = '>';
            cur_pos = backtrack_stack_.top();
        }

        //cur_pos = backtrack_stack_.top();
        if (extended == false) {
            //std::cout << "STUCK!!!!!\n";
            maze_[cur_pos.row][cur_pos.column] = 'X';
            solution_[cur_pos.row][cur_pos.column] = '@';
            backtrack_stack_.pop();
            if ((int) backtrack_stack_.size() != 0) {
                cur_pos = backtrack_stack_.top();
            }
            else {
                std::cout << "This maze has no solution.\n";
            }
        }
    }
    return false;
}

void MazeSolver::printSolution() {
    std::cout << "The solution to this maze is:\n";
    for (int x = 0; x < maze_rows_; x++) {
        for (int y = 0; y < maze_columns_; y++) {
            if (y == maze_columns_ - 1) {
                std::cout << solution_[x][y];
            }
            else {
                std::cout << solution_[x][y] << " ";
            }
        }
        std::cout << "\n";
    }
}

