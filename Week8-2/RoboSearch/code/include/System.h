#ifndef SYSTEM_H
#define SYSTEM_H

#include "Stack.h"
#include "BFS-DFS.h"
#include "State-Environment.h"

#define MAX_ROOM_NUM 100
#define BUFFER_SIZE 64 // Adjust as necessary for the longest line

// 1. Welcoming informations
void welcomeInformation();

// 2. Choose whether to shows detailed informations
bool verboseMode();

// 3. Goal test for the given tasks
void goalTest(Building* pBuilding, bool verbose);

// 4. Initialize the initial state of user's input
int initializeState(Building* Building);

// 5. Read the user input for the initial location of HOOVI
void userInput(Building* pBuilding);








#endif // SYSTEM_H


