//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 20
#define MAX_ADDR_LENGTH 17

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDR_LENGTH];
} Device;

void scanDevices(Device *devices, int *numDevices);
void printDevices(Device *devices, int numDevices);
void getRandomDevice(Device *devices, int numDevices);

int main() {
    Device devices[MAX_DEVICES];
    int numDevices = 0;

    srand(time(NULL)); // seed random number generator

    scanDevices(devices, &numDevices);
    printf("Scanning for wireless network devices...\n");
    printf("Found %d devices!\n", numDevices);

    printDevices(devices, numDevices);

    getRandomDevice(devices, numDevices);

    return 0;
}

// Scans for wireless network devices and stores them in the devices array
void scanDevices(Device *devices, int *numDevices) {
    // Simulate scanning by randomly generating device names and addresses
    char names[MAX_DEVICES][MAX_NAME_LENGTH] = {"iPhone", "Samsung", "LG", "Sony", "Google", "Nokia", "Motorola"};
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (rand() % 2 == 0) {
            strncpy(devices[*numDevices].name, names[rand() % 7], MAX_ADDR_LENGTH);
            snprintf(devices[*numDevices].address, sizeof(devices[*numDevices].address), "192.168.%d.%d", rand() % 256, rand() % 256);
            (*numDevices)++;
        }
    }
}

// Prints the names and addresses of the devices in the devices array
void printDevices(Device *devices, int numDevices) {
    printf("List of devices:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("%s:\t%s\n", devices[i].name, devices[i].address);
    }
}

// Selects a random device from the devices array and prints its name and address
void getRandomDevice(Device *devices, int numDevices) {
    int index = rand() % numDevices;
    printf("Selected device:\n%s:\t%s\n", devices[index].name, devices[index].address);
}