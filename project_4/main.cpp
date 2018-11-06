#include <iostream>
#include "MazeSolver.h"
int main() {

	MazeSolver solver("inputC.txt");
	solver.printSolution();

	if(solver.mazeIsReady()) {		
 		solver.solveMaze();
 		solver.printSolution();
	}
	return 0;
}
