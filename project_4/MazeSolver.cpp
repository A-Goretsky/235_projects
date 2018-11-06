#include "MazeSolver.h"
#include <ios>
using std::string;

MazeSolver::MazeSolver(std::string input_file) {
    //fflush(stdout);
    std::ifstream file;
    int rows;
    int cols;
    try {
        file.open(input_file, std::fstream::in);
    }
    catch (int e) {
        std::cout << "Cannot read from input.txt" << std::endl;
        return; //more? no?
    }
    file >> maze_rows_ >> maze_columns_;
    initializeMaze(maze_rows_, maze_columns_);
    fillMaze(file);
    //std::cout << maze_rows_;
    //std::cout << maze_columns_;

    //print original maze
    for (int x = 0; x < maze_rows_; x++) {
        for (int y = 0; y < maze_columns_; y++) {
            std::cout << maze_[x][y] << " ";
        }
        std::cout << "\n";
    }

    mazeIsReady();
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
}

MazeSolver::~MazeSolver() {
    delete [] maze_;
    maze_ = nullptr;
    delete [] solution_;
    solution_ = nullptr;
}

bool MazeSolver::mazeIsReady() {
    return true;
}

//pre: current_position is a valid position on the maze_
    //post: adds all positions extensible from current_position to backtrack_stack_
    //return: true if path was extended, false otherwise
    //called by solveMaze()
bool MazeSolver::extendPath(Position current_position) {
    
}

//pre: old_position is a Position initialized with row and column to valid positions in maze_ and it is extensible in direction dir
    //return: a new Position on the maze moving in direction dir from old_position
    //called by extendPath()
Position MazeSolver::getNewPosition(Position old_position, direction dir) {

}

//checks if the path can be extended in maze_ from position current_position in direction dir
    //return: true if path can be extended given current_position and dir, false otherwise
    //called by extendPath
bool MazeSolver::isExtensible(Position current_position, direction dir) {

}

bool MazeSolver::solveMaze() {
    
}

void MazeSolver::printSolution() {
    std::cout << "The solution to this maze is:";
    for (int x = 0; x < maze_rows_; x++) {
        for (int y = 0; y < maze_columns_; y++) {
            std::cout << maze_[x][y] << " ";
        }
        std::cout << "\n";
    }
}

