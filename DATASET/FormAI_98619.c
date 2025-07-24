//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Location {
    double latitude;
    double longitude;
};

struct Node {
    struct Location location;
    struct Node* next;
};

struct Node* head = NULL;

void insertLocation(double latitude, double longitude) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->location.latitude = latitude;
    newNode->location.longitude = longitude;
    newNode->next = head;
    head = newNode;
}

void printLocations() {
    struct Node* current = head;
    printf("Locations:\n");
    while (current != NULL) {
        printf("Latitude: %f, Longitude: %f\n", current->location.latitude, current->location.longitude);
        current = current->next;
    }
}

void simulateGPSNavigation() {
    double currentLatitude = 0;
    double currentLongitude = 0;
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        currentLatitude += (double) (rand() % 5) / 1000;
        currentLongitude += (double) (rand() % 5) / 1000;
        insertLocation(currentLatitude, currentLongitude);
    }
    printLocations();
}

int main() {
    simulateGPSNavigation();
    return 0;
}