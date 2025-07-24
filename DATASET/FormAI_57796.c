//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_DEVICES 100

typedef struct {
    char name[20];
    char ip[20];
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int count;
} NetworkMap;

void addDevice(NetworkMap *map, char *name, char *ip) {
    if (map->count < MAX_DEVICES) {
        strcpy(map->devices[map->count].name, name);
        strcpy(map->devices[map->count].ip, ip);
        map->count++;
    }
}

void printMap(NetworkMap *map) {
    printf("-----------------------\n");
    printf("|    Network Map      |\n");
    printf("-----------------------\n");
    printf("|   Name      |  IP   |\n");
    printf("-----------------------\n");

    for (int i = 0; i < map->count; i++) {
        printf("|%12s|%7s|\n", map->devices[i].name, map->devices[i].ip);
    }

    printf("-----------------------\n");
}

int main() {
    NetworkMap map = {0};

    addDevice(&map, "Router", "192.168.0.1");

    addDevice(&map, "Switch 1", "192.168.0.2");
    addDevice(&map, "Switch 2", "192.168.0.3");

    addDevice(&map, "PC 1", "192.168.0.4");
    addDevice(&map, "PC 2", "192.168.0.5");
    addDevice(&map, "PC 3", "192.168.0.6");

    addDevice(&map, "Printer", "192.168.0.7");

    printMap(&map);

    return 0;
}