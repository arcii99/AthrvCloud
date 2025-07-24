//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

// Variables for the traffic light
int curr_state;
pthread_mutex_t state_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t state_cv = PTHREAD_COND_INITIALIZER;

// Function to change the traffic light state
void change_state(int new_state) {
    pthread_mutex_lock(&state_mutex);
    curr_state = new_state;
    pthread_cond_broadcast(&state_cv);
    pthread_mutex_unlock(&state_mutex);
}

// Thread function for red light
void *red_light(void *arg) {
    while (1) {
        pthread_mutex_lock(&state_mutex);
        while (curr_state != RED) {
            pthread_cond_wait(&state_cv, &state_mutex);
        }
        pthread_mutex_unlock(&state_mutex);
        
        // Print messages and wait for next state
        printf("Red light is on. Stop!\n");
        sleep(3);
        change_state(GREEN);
    }
    return NULL;
}

// Thread function for green light
void *green_light(void *arg) {
    while (1) {
        pthread_mutex_lock(&state_mutex);
        while (curr_state != GREEN) {
            pthread_cond_wait(&state_cv, &state_mutex);
        }
        pthread_mutex_unlock(&state_mutex);
        
        // Print messages and wait for next state
        printf("Green light is on. Go!\n");
        sleep(5);
        change_state(YELLOW);
    }
    return NULL;
}

// Thread function for yellow light
void *yellow_light(void *arg) {
    while (1) {
        pthread_mutex_lock(&state_mutex);
        while (curr_state != YELLOW) {
            pthread_cond_wait(&state_cv, &state_mutex);
        }
        pthread_mutex_unlock(&state_mutex);
        
        // Print messages and wait for next state
        printf("Yellow light is on. Be ready to stop!\n");
        sleep(2);
        change_state(RED);
    }
    return NULL;
}

int main() {
    // Initialize current state to red
    curr_state = RED;
    
    // Create threads for all lights
    pthread_t red_thread, yellow_thread, green_thread;
    pthread_create(&red_thread, NULL, red_light, NULL);
    pthread_create(&yellow_thread, NULL, yellow_light, NULL);
    pthread_create(&green_thread, NULL, green_light, NULL);

    // Wait for all threads to finish
    pthread_join(red_thread, NULL);
    pthread_join(yellow_thread, NULL);
    pthread_join(green_thread, NULL);
    
    // Exit program
    return 0;
}