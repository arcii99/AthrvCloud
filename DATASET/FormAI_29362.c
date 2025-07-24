//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10
#define MAX_DISTANCE 100

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    int id;
    point location;
    double battery_level;
    int altitude;
} drone;

int main() {
    drone drones[MAX_DRONES];
    int num_drones = 0;
    int active_drone = -1;

    // Initialize drones
    for (int i = 0; i < MAX_DRONES; i++) {
        drones[i].id = i + 1;
        drones[i].location.x = rand() % MAX_DISTANCE;
        drones[i].location.y = rand() % MAX_DISTANCE;
        drones[i].battery_level = 100.0;
        drones[i].altitude = 0;
        num_drones++;
    }

    // Choose active drone
    while (active_drone < 0 || active_drone >= num_drones) {
        printf("Enter drone ID (1-%d): ", num_drones);
        scanf("%d", &active_drone);
        active_drone--;
    }

    // Main loop
    int command = -1;
    while (command != 0) {
        // Print drone info
        printf("\nActive drone: #%d, location (%d,%d), battery %.1f%%, altitude %d\n",
            drones[active_drone].id, drones[active_drone].location.x, drones[active_drone].location.y,
            drones[active_drone].battery_level, drones[active_drone].altitude);

        // Prompt user for command
        printf("Enter command (1: move, 2: ascend, 3: descend, 4: land, 5: switch drone, 0: exit): ");
        scanf("%d", &command);

        switch (command) {
            case 1: // Move
                point new_location;
                printf("Enter new location (x,y): ");
                scanf("%d,%d", &new_location.x, &new_location.y);
                double distance = sqrt(pow(new_location.x - drones[active_drone].location.x, 2)
                    + pow(new_location.y - drones[active_drone].location.y, 2));
                if (distance > MAX_DISTANCE) {
                    printf("Error: destination out of range\n");
                    break;
                }
                double energy_cost = distance / 10.0;
                if (energy_cost > drones[active_drone].battery_level) {
                    printf("Error: not enough battery\n");
                    break;
                }
                drones[active_drone].location = new_location;
                drones[active_drone].battery_level -= energy_cost;
                printf("Drone moved to (%d,%d), energy consumption: %.1f%% of battery\n",
                    new_location.x, new_location.y, energy_cost);
                break;
            case 2: // Ascend
                int altitude_increase;
                printf("Enter altitude increase: ");
                scanf("%d", &altitude_increase);
                drones[active_drone].altitude += altitude_increase;
                drones[active_drone].battery_level -= altitude_increase / 10.0;
                printf("Drone ascended to altitude %d, energy consumption: %.1f%% of battery\n",
                    drones[active_drone].altitude, altitude_increase / 10.0);
                break;
            case 3: // Descend
                int altitude_decrease;
                printf("Enter altitude decrease: ");
                scanf("%d", &altitude_decrease);
                drones[active_drone].altitude -= altitude_decrease;
                if (drones[active_drone].altitude < 0) {
                    drones[active_drone].altitude = 0;
                    printf("Error: cannot descend below ground level\n");
                    break;
                }
                drones[active_drone].battery_level -= altitude_decrease / 10.0;
                printf("Drone descended to altitude %d, energy consumption: %.1f%% of battery\n",
                    drones[active_drone].altitude, altitude_decrease / 10.0);
                break;
            case 4: // Land
                drones[active_drone].altitude = 0;
                drones[active_drone].battery_level -= 10.0;
                printf("Drone landed, energy consumption: 10%% of battery\n");
                break;
            case 5: // Switch drone
                active_drone = -1;
                while (active_drone < 0 || active_drone >= num_drones) {
                    printf("Enter drone ID (1-%d): ", num_drones);
                    scanf("%d", &active_drone);
                    active_drone--;
                }
                break;
            case 0: // Exit
                break;
            default:
                printf("Error: invalid command\n");
        }
    }

    return 0;
}