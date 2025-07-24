//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mathematical
#include <stdio.h>

int main() {
    int droneCoordinates[2] = {0, 0};
    int remoteCoordinates[2] = {10, 10};

    printf("Enter the number of instructions: ");
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter instruction %d: ", i);
        char instruction;
        scanf(" %c", &instruction);

        if (instruction == 'U') {
            droneCoordinates[1]++;
        } else if (instruction == 'D') {
            droneCoordinates[1]--;
        } else if (instruction == 'L') {
            droneCoordinates[0]--;
        } else if (instruction == 'R') {
            droneCoordinates[0]++;
        }

        printf("Drone coordinates: (%d, %d)\n", droneCoordinates[0], droneCoordinates[1]);

        int error[2] = {remoteCoordinates[0] - droneCoordinates[0], remoteCoordinates[1] - droneCoordinates[1]};
        double errorMagnitude = sqrt((error[0] * error[0]) + (error[1] * error[1]));
        printf("Error magnitude: %f\n\n", errorMagnitude);
    }

    return 0;
}