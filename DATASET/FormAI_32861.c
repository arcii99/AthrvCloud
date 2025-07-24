//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_RANGE 1000

typedef enum {
    DISCONNECTED,
    CONNECTED,
    PAIRED
} connection_status_t;

typedef struct {
    uint16_t latitude;
    uint16_t longitude;
} coordinates_t;

typedef struct {
    uint8_t left;
    uint8_t right;
} motor_speed_t;

typedef struct {
    bool power_status;
    coordinates_t location;
    motor_speed_t motor_speed;
    connection_status_t connection_status;
} drone_t;

void connect(drone_t* drone) {
    if (drone == NULL) {
        printf("Error - Invalid Drone\n");
        return;
    }
    
    if (drone->connection_status == PAIRED) {
        printf("Drone is already paired\n");
        return;
    }
    
    drone->connection_status = CONNECTED;
    printf("Drone is connected\n");
}

void pair(drone_t* drone) {
    if (drone == NULL) {
        printf("Error - Invalid Drone\n");
        return;
    }
    
    if (drone->connection_status == PAIRED) {
        printf("Drone is already paired\n");
        return;
    }
    
    if (drone->connection_status != CONNECTED) {
        printf("Error - Drone is not connected\n");
        return;
    }
    
    int r = rand() % MAX_RANGE;
    if (r >= MAX_RANGE / 2) {
        printf("Drone pairing failed\n");
        drone->connection_status = DISCONNECTED;
    } else {
        printf("Drone is now paired\n");
        drone->connection_status = PAIRED;
    }
}

void takeoff(drone_t* drone) {
    if (drone == NULL) {
        printf("Error - Invalid Drone\n");
        return;
    }
    
    if (drone->connection_status != PAIRED) {
        printf("Error - Drone is not paired\n");
        return;
    }
    
    printf("Drone is now taking off\n");
}

void land(drone_t* drone) {
    if (drone == NULL) {
        printf("Error - Invalid Drone\n");
        return;
    }
    
    if (drone->connection_status != PAIRED) {
        printf("Error - Drone is not paired\n");
        return;
    }
    
    printf("Drone is now landing\n");
}

void update_location(drone_t* drone, uint16_t new_latitude, uint16_t new_longitude) {
    if (drone == NULL) {
        printf("Error - Invalid Drone\n");
        return;
    }
    
    if (drone->connection_status != PAIRED) {
        printf("Error - Drone is not paired\n");
        return;
    }
    
    drone->location.latitude = new_latitude;
    drone->location.longitude = new_longitude;
}

void update_motor_speed(drone_t* drone, uint8_t new_left_speed, uint8_t new_right_speed) {
    if (drone == NULL) {
        printf("Error - Invalid Drone\n");
        return;
    }
    
    if (drone->connection_status != PAIRED) {
        printf("Error - Drone is not paired\n");
        return;
    }
    
    drone->motor_speed.left = new_left_speed;
    drone->motor_speed.right = new_right_speed;
}

int main() {
    drone_t drone = {
        .power_status = true,
        .location = {0, 0},
        .motor_speed = {0, 0},
        .connection_status = DISCONNECTED
    };
    
    connect(&drone);
    pair(&drone);
    
    update_motor_speed(&drone, 50, 50);
    takeoff(&drone);
    update_location(&drone, 100, 200);
    update_motor_speed(&drone, 60, 40);
    update_location(&drone, 150, 300);
    update_motor_speed(&drone, 90, 90);
    land(&drone);
    
    return 0;
}