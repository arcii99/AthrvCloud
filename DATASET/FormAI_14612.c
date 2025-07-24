//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// Initialize the traffic lights
int current_light = RED_LIGHT;

// Create the pthreads to control the traffic lights
pthread_t red_light_thread;
pthread_t yellow_light_thread;
pthread_t green_light_thread;

// Create the condition variables and mutexes for threading
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t green_light = PTHREAD_COND_INITIALIZER;
pthread_cond_t yellow_light = PTHREAD_COND_INITIALIZER;
pthread_cond_t red_light = PTHREAD_COND_INITIALIZER;

void *red_light_controller(void *arg) {
    while (true) {
        // Lock the mutex
        pthread_mutex_lock(&mutex);
        
        // Wait for the green light condition to be signaled
        pthread_cond_wait(&green_light, &mutex);
        
        // Change the light to yellow
        current_light = YELLOW_LIGHT;
        
        // Wait for the yellow light condition to be signaled
        pthread_cond_wait(&yellow_light, &mutex);
        
        // Change the light to red
        current_light = RED_LIGHT;
        printf("Red light is on\n");
        
        // Signal the red light condition
        pthread_cond_signal(&red_light);
        
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }
}

void *yellow_light_controller(void *arg) {
    while (true) {
        // Lock the mutex
        pthread_mutex_lock(&mutex);
        
        // Wait for the yellow light condition to be signaled
        pthread_cond_wait(&yellow_light, &mutex);
        
        // Change the light to red
        current_light = RED_LIGHT;
        printf("Red light is on\n");
        
        // Signal the red light condition
        pthread_cond_signal(&red_light);
        
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }
}

void *green_light_controller(void *arg) {
    while (true) {
        // Lock the mutex
        pthread_mutex_lock(&mutex);
        
        // Change the light to green
        current_light = GREEN_LIGHT;
        printf("Green light is on\n");
        
        // Signal the green light condition
        pthread_cond_signal(&green_light);
        
        // Wait for the red light condition to be signaled
        pthread_cond_wait(&red_light, &mutex);
        
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }
}

int main(void) {
    // Create the threads
    pthread_create(&red_light_thread, NULL, red_light_controller, NULL);
    pthread_create(&yellow_light_thread, NULL, yellow_light_controller, NULL);
    pthread_create(&green_light_thread, NULL, green_light_controller, NULL);
    
    // Loop forever and change the lights every 5 seconds
    while (true) {
        sleep(5);
        
        switch (current_light) {
            case RED_LIGHT:
                pthread_mutex_lock(&mutex);
                pthread_cond_signal(&green_light);
                pthread_mutex_unlock(&mutex);
                break;
            case YELLOW_LIGHT:
                pthread_mutex_lock(&mutex);
                pthread_cond_signal(&yellow_light);
                pthread_mutex_unlock(&mutex);
                break;
            case GREEN_LIGHT:
                pthread_mutex_lock(&mutex);
                pthread_cond_signal(&red_light);
                pthread_mutex_unlock(&mutex);
                break;
        }
    }
    
    return 0;
}