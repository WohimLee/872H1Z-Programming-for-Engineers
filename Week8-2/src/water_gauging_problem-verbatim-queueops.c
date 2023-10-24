/*
Breadth-First Search (BFS)

VERBATIM VERSION

This program implements BFS for the water gauging problem
that we discussed in the lab

Starting with two empty buckets of 3l and 4l capacity
and an unlimited supply of water
how can measure exactly 2 litres?

This version of the program executes the search step by step
with extensive state output and requires the user to press a key
between iterations
*/


#include <stdio.h>
#include <stdlib.h>

// our custom data type representing a state
typedef struct{
   int a; // 3l bucket quantity
   int b; // 4l bucket quantity
   int p; // parent index
} state;

// variables at global scope
int vfront = -1; // next pos in the visited list
int front = 0; // front pos of the queue
int rear = -1; // rear pos of the queue
int stateCount = 0; // amount of states in the waiting list
int searchCost = 0; // a counter to measure the number of search iterations
state queue[1000]   = {0,0};   // This is the FIFO waiting queue - we put all states yet to be examined in here
state visited[1000] = {0,0};   // visited states list - we put all states we have already examined in here

// function prototypes
void addToFringe(state);
int equalStates(state,state);
void generateSuccessors(state,int);
int hasBeenVisited(state);
int isGoalState(state);
void printSolution(state);
state pop();
void push(state);

// main program - this is where the search happens
main() {
    state initialState = {0,0,-1}; 	// set initial state to start from
    state s; 						// variable to hold the current state that we want to explore during search
    int parentIndex = 0;			// array index of the current state in the "visited" list
    printf("*** WELCOME TO WATER SEARCH ***\n\n");
    printf("Pushing initial state onto WAITING\n",initialState.a,initialState.b);
    push(initialState);				// add initial state to the "waiting" queue
    getchar();
	
    // Search - we are trying to explore states as long as there are any left in the queue
    printf("Starting search...\n\n");
    while(stateCount > 0) {
        printf("Getting the first element from WAITING:\n",s.a,s.b);
		// GET NEXT STATE
        s = pop();						// get a state from the queue
        printf("\nAdding [%d,%d] to VISITED:\n",s.a,s.b);
        parentIndex = addToVisited(s);	// add this state to the visited list and retrieve storage index
        getchar();
        // GOAL TEST
        if(isGoalState(s)) {
           // if the current state is the goal, then print the solution
           printf("\n[%d,%d] is the goal state!\n",s.a,s.b);
           printf("\nI found a solution after exploring %d possible states:\n", searchCost);
           printSolution(s);
		   // Wait for key press
           getchar();
           printf("\nI keep searching...\n");
        }
        // if current state s is not the goal, then run successor function
        else {
            printf("\n[%d,%d] is not the goal - I need to run the successor function...\n",s.a,s.b);
            generateSuccessors(s, parentIndex);   // generate the children of s, and make them remember s as their parent
            getchar();
        }
        // increment search iterations counter
        searchCost++;
    }
    printf("\n\nThere are no more states in WAITING - no further solutions found.");
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
     printf("  The current REAR index in WAITING is %d:",rear);	
     rear++;						// increase rear index 
     printf("  increasing REAR to %d.\n",rear);
     queue[rear] = s; 				// store s
     printf("  Storing [%d,%d] at index %d -", s.a, s.b,rear);
     stateCount++;					// increase the count of states in the queue
     printf("  there are now %d state(s) waiting for exploration.\n",stateCount);
}

// pop retrieves a state from the front of the queue
state pop() {						
     if(stateCount > 0) {			// check if there are items in the queue
        printf("  The current FRONT index in WAITING is %d.\n",front);	
        state s = queue[front];		// get state at front index
        printf("  Loading [%d,%d] from index %d.\n",s.a,s.b,front);	
        front++;					// increase front index to point at the next state
        printf("  Increasing FRONT to %d.\n",front);
        stateCount--; 				// decrement state counter
        printf("  There are now %d state(s) waiting for exploration.\n",stateCount);
        return s;       			// pass state back to the point of call
     }
}

// Takes a single state and that state's storage index in the visited list as input
// It then generates all valid successor states (children) of this state
// The contents of the successor function depend largely on the problem we are trying to solve
// Here, we have defined the possible actions and outcomes of the 3l-4l water gauging problem
void generateSuccessors(state s, int p) { 
    int amount = 0;
    // fill a: a can hold an amount of 3
    if(s.a < 3) { // only fill if not already full
       state newState = {3,s.b,p};
       //printf("I could fill A - ");
       addToFringe(newState);
    }
    // fill b: b can hold an amount of 4
    if(s.b < 4) { // only fill if not already full
       state newState = {s.a,4,p};
       //printf("I could fill B - ");
       addToFringe(newState);
    }
    // empty a
    if(s.a > 0) { // only empty out if not already empty
       state newState = {0,s.b,p};
      // printf("I could empty A - ");
       addToFringe(newState);
    }
    //empty b
    if(s.b > 0) { // only empty out if not already empty
       state newState = {s.a,0,p};
       //printf("I could empty B - ");
       addToFringe(newState);
    }
    // pour a->b
    if(s.a > 0 && s.b < 4) { // only pour if sth in a and b not full
        if(s.a < 4-s.b)      // compute amount to pour, which is either
            amount = s.a;    // the amount we want to transfer 
        else
            amount = 4-s.b;  // or the amount of space we have at the target
       state newState = {s.a-amount, s.b+amount, p};
       //printf("I could pour %d litres from A to B - ", amount);
       addToFringe(newState);   
    }
    // pour b->a
    if(s.b > 0 && s.a < 3) { // only pour if sth in b and a not full
        if(s.b < 3-s.a)      // compute amount to pour, which is either
            amount = s.b;    // the amount we want to transfer 
        else
            amount = 3-s.a;  // or the amount of space we have at the target
       state newState = {s.a+amount,s.b-amount, p};
       //printf("I could pour %d litres from B to A - ", amount);
       addToFringe(newState);
    }
}

// Takes a state as input and checks if this state is the goal state
// Returns 1 if this is so, and 0 if the state is not the goal
int isGoalState(state s) {
    if(s.a == 2 || s.b == 2) {  // for our problem, we need one quantity of 2litres
        return 1;
    }
    else
        return 0;
}


// OUTPUT 

// printSolution calls itself recursively to backtrack to the root and print each state
// in sequence. 
void printSolution(state s) {		
     if(s.p != -1)						// check if we reached the root state
         printSolution(visited[s.p]);	// recursive call to the parent of s
     printf("[%d,%d]", s.a, s.b);		// print state info
     if(!isGoalState(s))				// print arrows if not the goal (i.e., last) state
         printf("->"); 
     return;
}

// UTILITY FUNCTIONS

// addToVisited takes a state as an argument and adds it to the visited list
// returns the position in the list  at which the state was stored 
// (we need this information for maintaining parent links)
int addToVisited(state s) {
    printf("  The current list index in VISITED is %d:",vfront);	
    vfront++;				// increase list index
    printf("  increasing this to %d.\n",vfront);
    visited[vfront] = s;	// add state at index
    printf("  Storing [%d,%d] at list index %d.\n", s.a, s.b,vfront);
    printf("  Returning %d as the parent index for this state.",vfront);
    return vfront;			// return storage index for s
}     

// equalStates takes two states as input and compares their internal variables a and b 
// if both a and both b values are equal, this function will return 1, otherwise 0;
int equalStates(state s1, state s2) {
    if(s1.a == s2.a && s1.b == s2.b)   
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
        if(equalStates(visited[i],s)) {
             //printf("but we have already visited [%d,%d]!\n",s.a,s.b);
             return 1;
        }
    }   
    return 0;
}

// addToFringe takes a state as input and checks if this state has not been explored yet 
// If the state was not previously visited, then we recognise the state 
// to be "at the fringe" of its parent and add it to the waiting queue
// otherwise, the function returns to the point of call without doing anything 

void addToFringe(state s) {
    if(!hasBeenVisited(s)){		// check if s was visited before
        push(s);			    // if not, then add to queue
    }	                        
    return;
}
