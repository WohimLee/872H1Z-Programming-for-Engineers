/*
Breadth-First Search (BFS) - Basic search template

*/
#include <stdio.h>
#include <stdlib.h>

// It can be useful to use struct to define a state representation
// because we can bundle up several variables in one state
typedef struct{
   // your state rep here
   
} state;

// Variables at global scope
// ***
// Define here queue arrays (fringe, visited) and 
// their pointer integers (front, rear)
state queue[1000]   = {};   // This is the FIFO waiting queue - we put all states yet to be examined in here
state visited[1000] = {};   // This is the visited states list - we put all states we have already examined in here
int vfront = -1; // next pos in the visited list
int front = 0; // front pos of the queue
int rear = -1; // rear pos of the queue
int stateCount = 0; // amount of states in the waiting list
int searchCost = 0; // a counter to measure the number of search iterations

// function prototypes
void addToFringe(state);
int addToVisited(state);
int equalStates(state,state);
void generateSuccessors(state,int);
int hasBeenVisited(state);
int isGoalState(state);
void printSolution(state);
state pop();
void push(state);


// main program - this is where the search happens
main() {
    state initialState = ??? 	// TO DO: set initial state to start from
    state s; 					// variable to hold the current state that we want to explore during search
    int parentIndex = 0;			// array index of the current state in the "visited" list
    printf("*** WELCOME ***\n");
    push(initialState);				// add initial state to the "waiting" queue
	
    // Search - we are trying to explore states as long as there are any left in the queue
    printf("\n\nI'm searching...\n");
    while(stateCount > 0) {
		// GET NEXT STATE
        s = pop();						// get a state from the queue
        parentIndex = addToVisited(s);	// add this state to the visited list and retrieve storage index
        
        // GOAL TEST
        if(isGoalState(s)) {
           // if the current state is the goal, then print the solution
           printf("\nI found a solution (%d states explored): ", searchCost);
           printSolution(s);
		   // Wait for key press
           getchar();
           printf("\n\nI'm searching...\n");
        }
        // if current state s is not the goal, then run successor function
        else {
            generateSuccessors(s, parentIndex);   // generate the children of s, and make them remember s as their parent
        }
        // increment search iterations counter
        searchCost++;
    }
    printf("\n\nNo further solutions found.");
    getchar();
}

/* CORE SEARCH FUNCTIONS
*
*  push and pop - control the queue operations that implement BFS as our search strategy
*  generateSuccessors - creates further states to explore according to the rules of the problem
*  isGoalState - checks if the current state is a goal state
*
*  Details below
*/

// push adds a state to the rear of the queue
void push(state s) {				

}

// pop retrieves a state from the queue
state pop() {						

}

// Takes a single state and that state's storage index in the visited list as input
// It then generates all valid successor states (children) of this state
// The contents of the successor function depend largely on the problem we are trying to solve

void generateSuccessors(state s, int p) { 

    // TO DO: CREATE YOUR SUCCESSOR FUNCTION HERE

} 

// Takes a state as input and checks if this state is the goal state
// Returns 1 if this is so, and 0 if the state is not the goal
int isGoalState(state s) {
    // TO DO: YOUR GOAL TEST HERE
}


// OUTPUT 
// printSolution calls itself recursively to backtrack to the root and print each state
// in sequence. 
void printSolution(state s) {		
     if(s.p != -1)			// Check if we reached the root state
         printSolution(visited[s.p]);	// Recursive call to the parent of s
     printf("???");	// TODO: insert your state rep format - to print state info
     if(!isGoalState(s))		// print arrows if not the goal (i.e., last) state
         printf("->"); 
     return;
}

// UTILITY FUNCTIONS

// addToVisited takes a state as an argument and adds it to the visited list
// returns the position in the list  at which the state was stored 
// (we need this information for maintaining parent links)
int addToVisited(state s) {
    vfront++;				// increase list index
    visited[vfront] = s;	// add state at index
    return vfront;			// return storage index for s
}

// equalStates takes two states as input and compares their internal variables a and b 
// if both a and both b values are equal, this function will return 1, otherwise 0;
int equalStates(state s1, state s2) {
    if(???)   // TODO: insert your state rep format - DEVISE AN EXPRESSION TO EVALUATE EQUALITY BETWEEN NODES
        return 1;
    else
        return 0;
}

// hasBeenVisited takes a state as input and compares it to all states stored in the "visited" list
// returns 1 if the state has been visited before
// returns 0 if the state 
int hasBeenVisited(state s) {
    int i;
    for(i=0; i<vfront; i++){
        if(equalStates(visited[i],s))
             return 1;
    }   
    return 0;
}

// addToFringe takes a state as input and checks if this state has not been explored yet 
// If the state was not previously visited, then we recognise the state 
// to be "at the fringe" of its parent and add it to the waiting queue
// otherwise, the function returns to the point of call without doing anything 

void addToFringe(state s) {
    if(!hasBeenVisited(s))		// check if s was visited before
        push(s);			// if not, then add to queue
    return;
}
