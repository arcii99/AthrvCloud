//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10
#define MAX_CHANNELS 4

typedef struct Drone {
    int id;
    int channel;
    int battery;
} Drone;

Drone drones[MAX_DRONES];

int num_drones = 0;

void initialize_drones() {
    for (int i = 0; i < MAX_DRONES; i++) {
        drones[i].id = -1;
        drones[i].channel = -1;
        drones[i].battery = -1;
    }
}

void add_drone(int id, int channel, int battery) {
    drones[num_drones].id = id;
    drones[num_drones].channel = channel;
    drones[num_drones].battery = battery;
    num_drones++;
}

Drone* find_drone(int id) {
    for (int i = 0; i < num_drones; i++) {
        if (drones[i].id == id) {
            return &drones[i];
        }
    }
    return NULL;
}

void show_all_drones() {
    printf("ID   Channel   Battery\n");
    printf("--   -------   -------\n");
    for (int i = 0; i < num_drones; i++) {
        printf("%02d   %02d        %02d%%\n", drones[i].id, drones[i].channel, drones[i].battery);
    }
}

void control_drone(int id, char action) {
    Drone* drone = find_drone(id);
    if (drone == NULL) {
        printf("Drone not found!\n");
    } else {
        switch (action) {
            case 'U':
                if (drone->battery + 10 <= 100) {
                    drone->battery += 10;
                    printf("Battery level of drone %02d is now %02d%%\n", drone->id, drone->battery);
                } else {
                    printf("Battery level is already at maximum!\n");
                }
                break;
            case 'D':
                if (drone->battery - 10 >= 0) {
                    drone->battery -= 10;
                    printf("Battery level of drone %02d is now %02d%%\n", drone->id, drone->battery);
                } else {
                    printf("Battery level is already at minimum!\n");
                }
                break;
            default:
                printf("Invalid action!\n");
                break;
        }
    }
}

int main() {
    initialize_drones();
    
    // add drones
    add_drone(1, 1, 80);
    add_drone(2, 2, 90);
    add_drone(3, 1, 50);
    
    // show all drones
    show_all_drones();
    
    // control drone 2
    control_drone(2, 'U');
    control_drone(2, 'U');
    control_drone(2, 'U');
    control_drone(2, 'D');
    
    // show all drones
    show_all_drones();
    
    return 0;
}