//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char type[20];
    int range;
    int price;
} Drone;

Drone drones[MAX_DRONES];

void initializeDrones() {
    strcpy(drones[0].type, "Quadcopter");
    drones[0].range = 1000;
    drones[0].price = 500;

    strcpy(drones[1].type, "Hexacopter");
    drones[1].range = 1200;
    drones[1].price = 800;

    // add more drones here
}

int main() {
    initializeDrones();

    char command[MAX_COMMAND_LENGTH];
    char* token;
    int selectedDroneIndex = 0;

    while (1) {
        printf("Enter a command:\n");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        token = strtok(command, " ");
        if (strcmp(token, "list") == 0) {
            printf("Available drones:\n");
            for (int i = 0; i < MAX_DRONES; i++) {
                if (strlen(drones[i].type) > 0) {
                    printf("%d: %s (%d meters, $%d)\n", i+1, drones[i].type, drones[i].range, drones[i].price);
                }
            }
        } else if (strcmp(token, "select") == 0) {
            token = strtok(NULL, " ");
            int index = atoi(token) - 1;
            if (index >= 0 && index < MAX_DRONES && strlen(drones[index].type) > 0) {
                selectedDroneIndex = index;
                printf("Selected drone: %s\n", drones[selectedDroneIndex].type);
            } else {
                printf("Invalid drone index\n");
            }
        } else if (strcmp(token, "fly") == 0) {
            token = strtok(NULL, " ");
            int distance = atoi(token);
            if (distance <= drones[selectedDroneIndex].range) {
                printf("%s is flying %d meters\n", drones[selectedDroneIndex].type, distance);
            } else {
                printf("%s cannot fly that far\n", drones[selectedDroneIndex].type);
            }
        } else if (strcmp(token, "buy") == 0) {
            token = strtok(NULL, " ");
            int price = atoi(token);
            if (price >= drones[selectedDroneIndex].price) {
                printf("%s purchased for $%d\n", drones[selectedDroneIndex].type, drones[selectedDroneIndex].price);
            } else {
                printf("Not enough money to buy %s\n", drones[selectedDroneIndex].type);
            }
        } else if (strcmp(token, "exit") == 0) {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}