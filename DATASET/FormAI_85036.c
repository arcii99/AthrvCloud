//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define GREEN 0
#define YELLOW 1
#define RED 2
#define BLINK 3

bool system_on = true;
int current_state = GREEN;
int timer = 0;

pthread_mutex_t mutex;

void* controller(void* args) {
    while(system_on) {
        pthread_mutex_lock(&mutex);

        switch(current_state) {
            case GREEN:
                printf("Green Light\n");
                sleep(5); // Green light for 5 seconds
                current_state = YELLOW;
                break;
            
            case YELLOW:
                printf("Yellow Light\n");
                sleep(2); // Yellow light for 2 seconds
                current_state = RED;
                break;
            
            case RED:
                printf("Red Light\n");
                sleep(5); // Red light for 5 seconds
                current_state = GREEN;
                break;
            
            case BLINK:
                printf("Blinking Yellow Light\n");
                sleep(1); // Blinking yellow light for 1 second
                break;
                
            default:
                break;
        }
        
        pthread_mutex_unlock(&mutex);
        
        if(current_state == RED) {
            timer++;
        }
        
        if(timer == 10) { // After every 10 cycles, switch to blinking yellow
            timer = 0;
            pthread_mutex_lock(&mutex);
            current_state = BLINK;
            pthread_mutex_unlock(&mutex);
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL, controller, NULL);
    
    char input;
    while(system_on) {
        printf("Enter 'Q' to quit\n");
        scanf("%c", &input);
        if(input == 'Q' || input == 'q') {
            system_on = false;
            pthread_mutex_lock(&mutex);
            current_state = GREEN;
            pthread_mutex_unlock(&mutex);
        } else {
            printf("Invalid input\n");
        }
    }
    
    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}