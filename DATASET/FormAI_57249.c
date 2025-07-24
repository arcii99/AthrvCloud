//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define NO_OF_LANES 4

pthread_mutex_t mutex;

bool traffic_lights[NO_OF_LANES][3];    // each lane has three traffic lights: red, yellow, and green

void switch_traffic_lights(int lane, int current_light) {
    traffic_lights[lane][current_light] = false;
    current_light = (current_light + 1) % 3;
    traffic_lights[lane][current_light] = true;
}

void* traffic_light_controller(void *arg) {
    int lane = *(int*)arg;
    int current_light = RED;
    
    while(true) {
        usleep(2000000);    // light stays RED for 2 seconds
        pthread_mutex_lock(&mutex);
        switch_traffic_lights(lane, current_light);
        pthread_mutex_unlock(&mutex);
        
        if(current_light == RED) {  // light is RED, change to GREEN after 2 seconds
            usleep(2000000 + rand() % 1000000);
            current_light = GREEN;
        } else if(current_light == GREEN) {   // light is GREEN, change to YELLOW after 10 seconds
            usleep(10000000 + rand() % 2000000);  
            current_light = YELLOW;
        } else if(current_light == YELLOW) {  // light is YELLOW, change to RED after 2 seconds
            usleep(2000000 + rand() % 1000000);  
            current_light = RED;
        }
    }    
}

void print_traffic_lights() {
    for(int i=0; i<NO_OF_LANES; i++) {
        printf("Lane %d:   ", i+1);
        if(traffic_lights[i][RED]) printf("RED    ");
        else printf("       ");
        if(traffic_lights[i][YELLOW]) printf("YELLOW    ");
        else printf("          ");
        if(traffic_lights[i][GREEN]) printf("GREEN    ");
        else printf("        ");
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    
    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[NO_OF_LANES];
    int lane_args[NO_OF_LANES];
    
    for(int i=0; i<NO_OF_LANES; i++) {
        lane_args[i] = i;
        traffic_lights[i][RED] = true;
        pthread_create(&threads[i], NULL, traffic_light_controller, &lane_args[i]);
    }
    
    while(true) {
        printf("\033c");    // clears the console
        printf("TRAFFIC LIGHTS\n");
        print_traffic_lights();
        sleep(1);
    }
    
    return 0;
}