//FormAI DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

// struct for smart home devices
typedef struct {
    bool light_state; // true means ON, false means OFF
    int temperature; // in degrees Celsius
    bool door_locked; // true means locked, false means unlocked
} Smart_Home;

Smart_Home living_room = {false, 23, false}; // initialize living room devices
Smart_Home bedroom = {false, 20, true}; // initialize bedroom devices

void* living_room_light(void* arg) {
    while (true) {
        if (living_room.light_state) {
            printf("Living room light is ON\n");
        } else {
            printf("Living room light is OFF\n");
        }
        usleep(100000); // sleep for 100ms
    }
}

void* living_room_temperature(void* arg) {
    while (true) {
        printf("Living room temperature is %d degrees Celsius\n", living_room.temperature);
        usleep(500000); // sleep for 500ms
    }
}

void* living_room_door(void* arg) {
    while (true) {
        if (living_room.door_locked) {
            printf("Living room door is locked\n");
        } else {
            printf("Living room door is unlocked\n");
        }
        usleep(200000); // sleep for 200ms
    }
}

void* bedroom_light(void* arg) {
    while (true) {
        if (bedroom.light_state) {
            printf("Bedroom light is ON\n");
        } else {
            printf("Bedroom light is OFF\n");
        }
        usleep(100000); // sleep for 100ms
    }
}

void* bedroom_temperature(void* arg) {
    while (true) {
        printf("Bedroom temperature is %d degrees Celsius\n", bedroom.temperature);
        usleep(500000); // sleep for 500ms
    }
}

void* bedroom_door(void* arg) {
    while (true) {
        if (bedroom.door_locked) {
            printf("Bedroom door is locked\n");
        } else {
            printf("Bedroom door is unlocked\n");
        }
        usleep(200000); // sleep for 200ms
    }
}

int main() {
    pthread_t living_room_light_thread, living_room_temperature_thread, living_room_door_thread,
              bedroom_light_thread, bedroom_temperature_thread, bedroom_door_thread;
    
    pthread_create(&living_room_light_thread, NULL, living_room_light, NULL);
    pthread_create(&living_room_temperature_thread, NULL, living_room_temperature, NULL);
    pthread_create(&living_room_door_thread, NULL, living_room_door, NULL);
    pthread_create(&bedroom_light_thread, NULL, bedroom_light, NULL);
    pthread_create(&bedroom_temperature_thread, NULL, bedroom_temperature, NULL);
    pthread_create(&bedroom_door_thread, NULL, bedroom_door, NULL);
    
    // simulate changing smart home devices state
    while (true) {
        living_room.light_state = !living_room.light_state; // toggle light state
        living_room.temperature += 1; // increase room temperature by 1 degree
        bedroom.light_state = !bedroom.light_state; // toggle light state
        bedroom.door_locked = !bedroom.door_locked; // toggle door lock
        usleep(1000000); // sleep for 1s
    }
    
    return 0;
}