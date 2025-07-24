//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_EDGES 1000

typedef struct{
    char name[20];
    char ip[20];
} Device;

typedef struct{
    int start;
    int end;
    int weight;
} Edge;

Device devices[MAX_DEVICES];
Edge edges[MAX_EDGES];

int numDevices = 0;
int numEdges = 0;

void addDevice(char *name, char *ip){
    strcpy(devices[numDevices].name, name);
    strcpy(devices[numDevices].ip, ip);
    numDevices++;
}

void addEdge(int start, int end, int weight){
    edges[numEdges].start = start;
    edges[numEdges].end = end;
    edges[numEdges].weight = weight;
    numEdges++;
}

void printDevices(){
    int i;
    for(i = 0; i < numDevices; i++){
        printf("Device %d: %s - %s\n", i+1, devices[i].name, devices[i].ip);
    }
}

void printEdges(){
    int i;
    for(i = 0; i < numEdges; i++){
        printf("Edge %d: %d -> %d (%d)\n", i+1, edges[i].start+1, edges[i].end+1, edges[i].weight);
    }
}

int main(){

    addDevice("Router1", "192.168.0.1");
    addDevice("Switch1", "192.168.0.2");
    addDevice("PC1", "192.168.0.3");
    addDevice("PC2", "192.168.0.4");

    addEdge(0, 1, 5);
    addEdge(0, 2, 10);
    addEdge(1, 2, 15);
    addEdge(2, 3, 20);

    printf("Devices:\n");
    printDevices();

    printf("\nEdges:\n");
    printEdges();

    return 0;
}