//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_IP_LENGTH 15
#define MAX_NAME_LENGTH 50
#define MAX_DEVICES 50

struct device {
    char name[MAX_NAME_LENGTH];
    char ip[MAX_IP_LENGTH];
    int port;
    bool isUp;
};

struct edge {
    int from;
    int to;
};

struct graph {
    struct device devices[MAX_DEVICES];
    struct edge edges[MAX_DEVICES];
    int numDevices, numEdges;
};

int findDeviceIndex(struct graph *g, char *ip) {
    int i;
    for (i = 0; i < g->numDevices; i++) {
        if (strcmp(g->devices[i].ip, ip) == 0)
            return i;
    }
    
    return -1;
}

void addDevice(struct graph *g, char *name, char *ip, int port) {
    struct device newDevice;
    strncpy(newDevice.name, name, MAX_NAME_LENGTH);
    strncpy(newDevice.ip, ip, MAX_IP_LENGTH);
    newDevice.port = port;
    newDevice.isUp = true;
    
    g->devices[g->numDevices++] = newDevice;
}

void addConnection(struct graph *g, char *ip1, char *ip2) {
    int index1 = findDeviceIndex(g, ip1);
    int index2 = findDeviceIndex(g, ip2);
    
    if (index1 == -1 || index2 == -1) {
        printf("ERROR: Devices not found!\n");
        return;
    }
    
    struct edge newEdge;
    newEdge.from = index1;
    newEdge.to = index2;
    
    g->edges[g->numEdges++] = newEdge;
}

void printGraph(struct graph *g) {
    int i, j;
    printf("Network devices:\n");
    for (i = 0; i < g->numDevices; i++) {
        printf("%d. %s (%s:%d) [%s]\n", i + 1, g->devices[i].name, g->devices[i].ip, g->devices[i].port, g->devices[i].isUp ? "UP" : "DOWN");
    }
    
    printf("\nNetwork map:\n");
    for (i = 0; i < g->numDevices; i++) {
        for (j = 0; j < g->numEdges; j++) {
            if (g->edges[j].from == i) {
                printf("  %s (%s:%d) -> %s (%s:%d)\n", g->devices[i].name, g->devices[i].ip, g->devices[i].port, g->devices[g->edges[j].to].name, g->devices[g->edges[j].to].ip, g->devices[g->edges[j].to].port);
            }
        }
    }
}

int main() {
    struct graph network = {0};
    
    addDevice(&network, "Router", "192.168.0.1", 80);
    addDevice(&network, "Desktop", "192.168.0.2", 22);
    addDevice(&network, "Server", "192.168.0.3", 443);
    addDevice(&network, "Laptop", "192.168.0.4", 3389);
    addConnection(&network, "192.168.0.1", "192.168.0.2");
    addConnection(&network, "192.168.0.1", "192.168.0.3");
    addConnection(&network, "192.168.0.3", "192.168.0.4");
    
    printGraph(&network);
    
    return 0;
}