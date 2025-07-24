//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>

/*Struct to represent drone*/
typedef struct Drone {
    int id;
    int x_pos;
    int y_pos;
    int z_pos;
    int battery;
    char direction;
} Drone;

/*Function to update drone position*/
void update_position(Drone *drone, char move_dir, int move_dist) {
    switch(move_dir) {
        case 'U':
            drone->z_pos += move_dist;
            break;
        case 'D':
            drone->z_pos -= move_dist;
            break;
        case 'F':
            if(drone->direction == 'N') {
                drone->y_pos += move_dist;
            } else if(drone->direction == 'S') {
                drone->y_pos -= move_dist;
            } else if(drone->direction == 'E') {
                drone->x_pos += move_dist;
            } else {
                drone->x_pos -= move_dist;
            }
            break;
        case 'B':
            if(drone->direction == 'N') {
                drone->y_pos -= move_dist;
            } else if(drone->direction == 'S') {
                drone->y_pos += move_dist;
            } else if(drone->direction == 'E') {
                drone->x_pos -= move_dist;
            } else {
                drone->x_pos += move_dist;
            }
            break;
    }
}

/*Function to rotate the drone*/
void rotate_drone(Drone *drone, char new_dir) {
    drone->direction = new_dir;
}

int main() {
    Drone my_drone = {1, 0, 0, 0, 100, 'N'};
    
    printf("Current drone position: (%d,%d,%d)\n", my_drone.x_pos, my_drone.y_pos, my_drone.z_pos);
    printf("Current drone battery: %d%%\n", my_drone.battery);
    
    /*Perform some actions*/
    update_position(&my_drone, 'F', 5);
    rotate_drone(&my_drone, 'W');
    update_position(&my_drone, 'B', 3);
    update_position(&my_drone, 'U', 2);
    
    printf("Current drone position: (%d,%d,%d)\n", my_drone.x_pos, my_drone.y_pos, my_drone.z_pos);
    printf("Current drone battery: %d%%\n", my_drone.battery);

    return 0;
}