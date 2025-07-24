//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 
#include <time.h>
  
#define MAX_DRONE_COUNT 10  
#define MAX_COMMAND_LENGTH 50
  
// Possible states of a drone  
typedef enum drone_state {  
    IDLE,  
    RUNNING,  
    EMERGENCY
} DroneState;  
  
// Structure to represent a drone  
typedef struct drone {  
    int id;  
    DroneState state;  
    float battery_level;  
    float gps_lat;  
    float gps_long;  
    time_t time_stamp;  
} Drone;  
  
// Function to initialize a drone with default values  
void initialize_drone(Drone *drone, int id) {  
    drone->id = id;  
    drone->state = IDLE;  
    drone->battery_level = 100.0f;  
    drone->gps_lat = 0.0f;  
    drone->gps_long = 0.0f;  
    drone->time_stamp = time(NULL);  
}  
  
// Function to update state of a drone based on battery level  
void update_drone_state(Drone *drone) {  
    if (drone->battery_level <= 0) {  
        drone->state = EMERGENCY;  
    } else if (drone->battery_level <= 20) {  
        drone->state = RUNNING;  
    } else {  
        drone->state = IDLE;  
    }  
}  
  
int main() {  
    // Initialize drones  
    Drone drones[MAX_DRONE_COUNT];  
    for (int i = 0; i < MAX_DRONE_COUNT; i++) {  
        initialize_drone(&drones[i], i);  
    }  
  
    // Start remote control loop  
    char command[MAX_COMMAND_LENGTH];  
    while (1) {  
        // Get user input  
        printf("Enter drone command: ");  
        fgets(command, MAX_COMMAND_LENGTH, stdin);  
        command[strcspn(command, "\n")] = '\0';  
  
        // Parse command  
        char *id_str = strtok(command, " ");  
        char *action_str = strtok(NULL, " ");  
        int id = atoi(id_str);  
        Drone *drone = &drones[id];  
  
        // Execute command  
        if (strcmp(action_str, "takeoff") == 0) {  
            if (drone->state != IDLE) {  
                printf("Drone %d is already in %d state.\n", id, drone->state);  
            } else {  
                drone->state = RUNNING;  
                printf("Drone %d has taken off.\n", id);  
            }  
        } else if (strcmp(action_str, "land") == 0) {  
            if (drone->state != RUNNING) {  
                printf("Drone %d is not running.\n", id);  
            } else {  
                drone->state = IDLE;  
                printf("Drone %d has landed.\n", id);  
            }  
        } else if (strcmp(action_str, "move") == 0) {  
            char *lat_str = strtok(NULL, " ");  
            char *long_str = strtok(NULL, " ");  
  
            if (drone->state != RUNNING) {  
                printf("Drone %d is not running.\n", id);  
            } else {  
                float lat = atof(lat_str);  
                float lng = atof(long_str);  
                drone->gps_lat = lat;  
                drone->gps_long = lng;  
                printf("Drone %d has moved to GPS location (%f, %f).\n", id, lat, lng);  
            }  
        } else if (strcmp(action_str, "emergency") == 0) {  
            drone->state = EMERGENCY;  
            printf("Drone %d is now in emergency state.\n", id);  
        } else if (strcmp(action_str, "status") == 0) {  
            // Update drone state and battery level  
            if (drone->state == RUNNING) {  
                float battery_drain = ((float) rand() / (float) RAND_MAX) * 5.0f + 1.0f;  
                drone->battery_level -= battery_drain;  
            }  
            update_drone_state(drone);  
  
            // Print drone status  
            printf("Drone %d status:\n", id);  
            printf("\tState: %d\n", drone->state);  
            printf("\tBattery Level: %f\n", drone->battery_level);  
            printf("\tGPS Location: (%f, %f)\n", drone->gps_lat, drone->gps_long);  
            printf("\tLast Update: %s", ctime(&drone->time_stamp));  
        } else if (strcmp(action_str, "exit") == 0) {  
            printf("Exiting remote control program.\n");  
            break;  
        } else {  
            printf("Invalid drone command.\n");  
        }  
    }  
  
    return 0;  
}