#include "Maze1.h"
#include <iostream>
#include <cassert>

using namespace std;

Maze1::~Maze1()
{
	for (int j = 0; j < size + 2; ++j) {
		delete[] M[j];
	}
	delete[] M;
}

void Maze1::find_exit()
// Use the DFS method to fill the path stack with the exit path Positions
// If there is no path to the exit, then after execution of this function
// the stack path should be empty
// This function does no input and no output
{
	Position current;
	direction d;
	
	// Pushes the stack with the start so its not empty
	path.push(start);
	// Sets the current as the start and changes it to visited
	current = start;
	M[current.row][current.col] = VISITED;

	// Loops until the exit is found or the stack is empty
	while (!(path.size == 0())) {
		// Checks if current position is the exit
		// If so it breaks the loop
		if (current == exitpos)
			break; 

		// Finds an open spot and pushes the stack
		d = DOWN;
		while (d != NONE) {
			Position nbr = current.Neighbor(d);
			// If the spot is open then is moves the current position
			if (M[nbr.row] [nbr.col] == OPEN) {
				current = nbr;
				path.push(current);
				M[current.row] [current.col] = VISITED;
				break;
			}
			// If it is not open then it checks the next direction
			d = next_direction(d);
		}

		//  Pops the stack and moves back if there is a dead end
		if (d != NONE)
			continue;
		path.pop();
		if (!(path.size == 0())) {
			current = path.top();
		}
		
	}
}




