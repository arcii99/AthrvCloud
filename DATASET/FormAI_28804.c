//FormAI DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function to simulate Lights control
void* light_control(void* arg){
    int* room = (int*)arg;
    printf("Switching ON lights in room %d\n", *room);
    sleep(2); // Sleep for 2 seconds
    printf("Switching OFF lights in room %d\n", *room);
    return NULL;
}

// Thread function to simulate thermostat control
void* thermostat_control(void* arg){
    int* room = (int*)arg;
    printf("Setting temperature to 22°C in room %d\n", *room);
    sleep(3); // Sleep for 3 seconds
    printf("Setting temperature to 18°C in room %d\n", *room);
    return NULL;
}

int main(){
    int room1 = 101, room2 = 102;
    pthread_t light_thread1, light_thread2, thermostat_thread1, thermostat_thread2;
    
    // Create threads for Room 1
    pthread_create(&light_thread1, NULL, light_control, &room1);
    pthread_create(&thermostat_thread1, NULL, thermostat_control, &room1);
    
    // Create threads for Room 2
    pthread_create(&light_thread2, NULL, light_control, &room2);
    pthread_create(&thermostat_thread2, NULL, thermostat_control, &room2);
    
    // Wait for threads to complete
    pthread_join(light_thread1, NULL);
    pthread_join(thermostat_thread1, NULL);
    pthread_join(light_thread2, NULL);
    pthread_join(thermostat_thread2, NULL);
    
    return 0;
}