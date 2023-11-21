

#include <unistd.h>
#include "System.h"
#include "Queue.h"
#include "Stack.h"
#include "BFS-DFS.h"

int Distance[MAX_ROOM_NUM];
int RoomFrom[MAX_ROOM_NUM];
bool visited[MAX_ROOM_NUM];

// BFS algorithm implementation
void breadthFirstSearch(Building* pBuilding, int startStateIdx, bool verbose)
{
    // Initialize 3 arrays: Distance, RoomFrom, visited
    int totalRooms = pBuilding->nNodeNum;
    for(int i=0; i<totalRooms; i++){
        Distance[i] = 999;
        RoomFrom[i] = -1;
        visited[i] = false;
    }
    
    Distance[startStateIdx] = 0;
    visited[startStateIdx] = true;

    // Initialize queue for BFS
    Queue queue;
    queueInit(&queue);
    queuePush(&queue, startStateIdx);
    if(verbose){
        printf("\nPush %d in queue\n", startStateIdx);
        queuePrint(queue);
    }
    
    // Start BFS
    while(!queueEmpty(queue)){
        ElemType popRoomIdx = queuePop(&queue);

        if(verbose){
            printf("\nPop the head element: %d,  ", popRoomIdx);
            displayCurrentLocation(pBuilding, popRoomIdx);
            printf("——————————————————————————————————————————————\n");
            queuePrint(queue);
            // sleep(1); // you can comment this line if you want
        }
        
        if(popRoomIdx == 78)
            break;
        // The first Edge of each Room
        Action* pCurEdge = pBuilding->pRoomList[popRoomIdx].pFirstEdge;

        // Traverse the Edge list of the Room
        // Push all the possible and unvisited actions in the queue
        while(pCurEdge){
            int curVisitRoomIdx = pCurEdge->nAdjNodeIdx;
            if(!visited[curVisitRoomIdx]){ // If the current node has been visited
                RoomFrom[curVisitRoomIdx] = popRoomIdx;
                Distance[curVisitRoomIdx] = Distance[popRoomIdx]+1;
                visited[curVisitRoomIdx]  = true;

                queuePush(&queue, curVisitRoomIdx);

                if(verbose){
                    printf("\nPush %d in queue\n", curVisitRoomIdx);
                    queuePrint(queue);
                    // sleep(1); // you can comment this line if you want
                }
            }
            pCurEdge = pCurEdge->pNextEdge;
        }
    }
    if(verbose){
        printf("\n\nChecking informations:\n\n");
        int chargerIdx = getRoomIdx(pBuilding, "Charger");
        for(int i=0; i<totalRooms; i++)
            printf("visited[%d]: %s, Distance[%d]: %d, RoomFrom[%d]: %d\n", 
                i, visited[i] == true ? "true" : "false", 
                i, Distance[i], 
                i, RoomFrom[i]);
    }
}

// DFS algorithm implementation
void depthFirstSearch(Building* pBuilding, int startStateIdx, bool verbose)
{
    // Initialize 3 arrays: Distance, RoomFrom, visited
    int totalRooms = pBuilding->nNodeNum;
    for(int i=0; i<totalRooms; i++){
        Distance[i] = 999;
        RoomFrom[i] = -1;
        visited[i] = false;
    }
    Distance[startStateIdx] = 0;
    visited[startStateIdx] = true;

    // Initialize stack for BFS
    Stack* pStack = stackInit();
    stackPush(pStack, startStateIdx);

    if(verbose){
        printf("\nPush %d in stack\n", startStateIdx);
        stackPrint(*pStack);
        // sleep(1); // you can comment this line if you want
    }
    
    while(!stackEmpty(*pStack))
    {
        ElemType popRoomIdx = stackPop(pStack);

        if(verbose){
            printf("\nPop the top element: %d, ", 
            popRoomIdx);
            displayCurrentLocation(pBuilding, popRoomIdx);
            printf("——————————————————————————————————————————————\n");
            stackPrint(*pStack);
            sleep(1); // you can comment this line if you want
        }
        if(popRoomIdx == 78)
            break;
        
        Action* pCurEdge = pBuilding->pRoomList[popRoomIdx].pFirstEdge;
        while(pCurEdge)
        {
            int curVisitRoomIdx = pCurEdge->nAdjNodeIdx;
            if(!visited[curVisitRoomIdx]){
                RoomFrom[curVisitRoomIdx] = popRoomIdx;
                Distance[curVisitRoomIdx] = Distance[popRoomIdx]+1;
                visited[curVisitRoomIdx]  = true;

                stackPush(pStack, curVisitRoomIdx);
                
                if(verbose){
                    printf("\nPush %d in stack\n", curVisitRoomIdx);
                    stackPrint(*pStack);
                    // sleep(1); // you can comment this line if you want
                }
            }
            pCurEdge = pCurEdge->pNextEdge;
        }
    }
}

// Display the current location of HOOVI
void displayCurrentLocation(Building* pBuilding, int popRoomIdx)
{
    printf("HOOVI is now at %s\n", 
        pBuilding->pRoomList[popRoomIdx].sState);
}

// Track the path from starting point to charger room
void tracePathBack(Building* pBuilding, int startRoomIdx)
{
    int chargerIdx = getRoomIdx(pBuilding, "Charger");
    int minDis = Distance[chargerIdx];
    printf("From Room %s to %s Room: \n", 
        pBuilding->pRoomList[startRoomIdx].sState,
        pBuilding->pRoomList[chargerIdx].sState);
    printf("————————————————————————————————\n");
    printf("%5s| The shortest distance: %d\n", "", minDis);

    printf("%5s| The shortest path: ", "");
    Stack* pStack = stackInit();
    stackPush(pStack, chargerIdx);
    int roomFromIdx = RoomFrom[chargerIdx];

    while(roomFromIdx != -1){
        stackPush(pStack, roomFromIdx);
        roomFromIdx = RoomFrom[roomFromIdx];

    }

    int size = stackSize(*pStack);
    for(int i=0; i<size-1; i++)
        printf("%s -> ", pBuilding->pRoomList[stackPop(pStack)].sState);
    printf("%s\n\n", pBuilding->pRoomList[stackPop(pStack)].sState);
}
