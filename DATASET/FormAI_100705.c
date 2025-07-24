//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multi-threaded
#include <stdio.h>  
#include <pthread.h>  
#include <stdlib.h> 

#define GREEN 1
#define YELLOW 2
#define RED 3

// Initialize traffic light state, default: red 
int trafficLight = RED;

// Condition variable to signal green light thread 
pthread_cond_t greenLight_cv = PTHREAD_COND_INITIALIZER;

// Mutex for trafficLight variable 
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function to handle green light 
void *greenLight(void *arg) {  
    while(1) {
        pthread_mutex_lock(&lock);
        while(trafficLight != GREEN) { 
            pthread_cond_wait(&greenLight_cv, &lock); 
        } 
        pthread_mutex_unlock(&lock); 
        
        printf("Green light is on. No Road Block.\n"); 
        sleep(3);
        
        pthread_mutex_lock(&lock); 
        printf("Green light is turning off.\n"); 
        trafficLight = YELLOW; 
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL); 
} 

// Function to handle yellow light 
void *yellowLight(void *arg) {  
    while(1) {
        pthread_mutex_lock(&lock);
        while(trafficLight != YELLOW) { 
            pthread_cond_wait(&greenLight_cv, &lock); 
        } 
        pthread_mutex_unlock(&lock);

        printf("Yellow light is on. Get ready to stop.\n"); 
        sleep(2);
        
        pthread_mutex_lock(&lock); 
        printf("Yellow light is turning off.\n"); 
        trafficLight = RED; 
        pthread_mutex_unlock(&lock);

        pthread_cond_signal(&greenLight_cv); 
    }
    pthread_exit(NULL); 
} 

// Function to handle red light 
void *redLight(void *arg) {  
    while(1) {
        pthread_mutex_lock(&lock); 
        while(trafficLight != RED) { 
            pthread_cond_wait(&greenLight_cv, &lock); 
        } 
        pthread_mutex_unlock(&lock);
        
        printf("Red light is on. Stop the traffic.\n"); 
        sleep(3);
        
        pthread_mutex_lock(&lock); 
        printf("Red light is turning off.\n"); 
        trafficLight = GREEN; 
        pthread_mutex_unlock(&lock);

        pthread_cond_signal(&greenLight_cv); 
    }
    pthread_exit(NULL); 
} 

int main() { 
    pthread_t green_thread, yellow_thread, red_thread;
    
    // Creating the threads  
    pthread_create(&green_thread, NULL, greenLight, NULL);  
    pthread_create(&yellow_thread, NULL, yellowLight, NULL);  
    pthread_create(&red_thread, NULL, redLight, NULL);  
          
    // Wait for the threads to finish 
    pthread_join(green_thread, NULL); 
    pthread_join(yellow_thread, NULL);  
    pthread_join(red_thread, NULL);  
    
    return 0;
}