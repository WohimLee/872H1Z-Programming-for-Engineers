/*
Breadth-First Search (BFS) - Robo-Search

*/
#include <stdio.h>
#include <stdlib.h>

// use struct to define a state representation
typedef struct{
   char a; // room label letter
   int b;  // room label number
   int p;  // parent index;
} state;

// variables at global scope
int vfront = -1; // next pos in the visited list
int front = 0; // front pos of the queue
int rear = -1; // rear pos of the queue
int stateCount = 0; // amount of states in the waiting list
int searchCost = 0; // a counter to measure the number of search iterations
state queue[1000]   = {};   // This is the FIFO waiting queue - we put all states yet to be examined in here
state visited[1000] = {};   // This is the visited states list - we put all states we have already examined in here

// function prototypes
void addToFringe(char,int,int);
int addToVisited(state s);
int equalStates(state,state);
void generateSuccessors(state,int);
int hasBeenVisited(state);
int isGoalState(state);
void printSolution(state);
state pop();
void push(state);

// main program - this is where the search happens
int main() {
    state initialState = {'A',3,-1}; 	// DONE: set initial state to start from
    state s; 					// variable to hold the current state that we want to explore during search
    int parentIndex = 0;			// array index of the current state in the "visited" list
    printf("*** WELCOME TO ROBOSEARCH (BFS)***\n");
	
	// Map and problem description
	printf("\nThis is our task environment:\n\n");
    printf("A3 B3 C3\n\n");
    printf("A2 B2 C2\n\n");
    printf("A1 B1 C1\n\n");
    printf("We start from A3. Our goal is C2. Find the shortest path(s)!"); 
           	
    // Search - we are trying to explore states as long as there are any left in the queue
    printf("\n\nI'm searching...\n");
    push(initialState);				// add initial state to the "waiting" queue
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
     rear++;					// increase rear index 
     queue[rear] = s; 				// store s
     stateCount++;				// increase the count of states in the queue
}

// pop retrieves a state from the front of the queue
state pop() {						
     if(stateCount > 0) {			// check if there are items in the queue
        state s = queue[front];		// get state at front index
        front++;				// increase front index to point at the next state
        stateCount--; 				// decrement state counter
        return s;       			// pass state back to the point of call
     }
}

// Takes a single state and that state's storage index in the visited list as input
// It then generates all valid successor states (children) of this state
// The contents of the successor function depend largely on the problem we are trying to solve

void generateSuccessors(state s, int p) {
     // DONE: CREATE YOUR SUCCESSOR FUNCTION HERE
     // HORIZONTAL MOVEMENT 
     if(s.a == 'A' || s.a == 'B') { // move right
       addToFringe(s.a+1,s.b,p);
     }
     if(s.a == 'C' || s.a == 'B') { // move left
       addToFringe(s.a-1,s.b,p);
     }
     // VERTICAL MOVEMENT 
     if(s.b == 1 || s.b == 2) { // move up
       addToFringe(s.a,s.b+1,p);
     }
     if(s.b == 2 || s.b == 3) { // move down
       addToFringe(s.a,s.b-1,p);
     }
} 

// Takes a state as input and checks if this state is the goal state
// Returns 1 if this is so, and 0 if the state is not the goal
int isGoalState(state s) {
    // DONE: YOUR GOAL TEST HERE
    if(s.a == 'C' && s.b == 2)  // We are looking for room C2
        return 1;
    else
        return 0;
}


// OUTPUT 

// printSolution calls itself recursively to backtrack to the root and print each state
// in sequence. 
void printSolution(state s) {		
     if(s.p != -1)			// Check if we reached the root state
         printSolution(visited[s.p]);	// Recursive call to the parent of s
     printf(" %c%d ", s.a, s.b);	// DONE: insert your state rep format - to print state info
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
    if(s1.a == s2.a && s1.b == s2.b)   // DONE: insert your state rep format - DEVISE AN EXPRESSION TO EVALUATE EQUALITY BETWEEN NODES
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

void addToFringe(char a, int b, int p) {
	state s = {a,b,p};
    if(!hasBeenVisited(s))		// check if s was visited before
        push(s);			// if not, then add to queue
    return;
}
