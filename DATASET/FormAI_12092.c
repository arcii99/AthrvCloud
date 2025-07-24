//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define structs to hold node and connection information
typedef struct Node{
    char *name;
    int x;
    int y;
} Node;

typedef struct Connection{
    Node *startNode;
    Node *endNode;
    int distance;
} Connection;

//Function to randomly generate node coordinates
void generateNodeCoordinates(Node *node){
    node->x = rand() % 100;
    node->y = rand() % 100;
}

int main(){
    //Seed random number generator
    srand(time(NULL));

    //Initialize node and connection arrays
    Node nodes[10];
    Connection connections[15];

    //Generate random node names and coordinates
    char *nodeNames[10] = {"Central Hub", "Security Station", "Data Center", "Maintenance Hub", "Executive Offices", "Research Labs", "Server Room", "Employee Lounge", "Marketing Hub", "IT Help Desk"};

    for(int i = 0; i < 10; i++){
        nodes[i].name = nodeNames[i];
        generateNodeCoordinates(&nodes[i]);
    }

    //Generate random connections between nodes
    int connectionCount = 0;
    for(int i = 0; i < 10; i++){
        for(int j = i + 1; j < 10; j++){
            if(rand() % 2 == 1){
                connections[connectionCount].startNode = &nodes[i];
                connections[connectionCount].endNode = &nodes[j];
                connections[connectionCount].distance = rand() % 50 + 50;
                connectionCount++;
            }
        }
    }

    //Print out network topology
    printf("####################################\n");
    printf("#                                  #\n");
    printf("#       CYBERPUNK NETWORK MAP      #\n");
    printf("#                                  #\n");
    printf("####################################\n\n");

    printf("NODES:\n\n");
    for(int i = 0; i < 10; i++){
        printf("%s (%d,%d)\n", nodes[i].name, nodes[i].x, nodes[i].y);
    }

    printf("\nCONNECTIONS:\n\n");
    for(int i = 0; i < connectionCount; i++){
        printf("%s (%d,%d) --> %s (%d,%d)  (%d units)\n", connections[i].startNode->name, connections[i].startNode->x, connections[i].startNode->y, connections[i].endNode->name, connections[i].endNode->x, connections[i].endNode->y, connections[i].distance);
    }

    return 0;
}