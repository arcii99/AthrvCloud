//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// define signal handlers
void handle_red(int sig);
void handle_yellow(int sig);
void handle_green(int sig);

// global variables
int is_running = 1;
int curr_state = 0; // 0 - Red, 1 - Yellow, 2 - Green
int green_time = 10; // time for green light
int yellow_time = 5; // time for yellow light
int red_time = 15; // time for red light

int main(void) {
    // setup signal handlers for each light
    signal(SIGUSR1, handle_red);
    signal(SIGUSR2, handle_yellow);
    signal(SIGINT, handle_green);
    
    printf("Starting Traffic Light Controller...\n");
    
    while(is_running) {
        // toggle the current state of the light
        if(curr_state == 0) {
            kill(getpid(), SIGUSR1);
        } else if(curr_state == 1) {
            kill(getpid(), SIGUSR2);
        } else if(curr_state == 2) {
            kill(getpid(), SIGINT);
        }
        
        // wait for the specified time
        if(curr_state == 0) {
            sleep(red_time);
        } else if(curr_state == 1) {
            sleep(yellow_time);
        } else if(curr_state == 2) {
            sleep(green_time);
        }
    }
    
    printf("Traffic Light Controller terminated.\n");
    return 0;
}

void handle_red(int sig) {
    // turn off yellow and green lights
    printf("Red light is on.\n");
    curr_state = 0;
}

void handle_yellow(int sig) {
    // turn off red and green lights
    printf("Yellow light is on.\n");
    curr_state = 1;
}

void handle_green(int sig) {
    // turn off red and yellow lights
    printf("Green light is on.\n");
    curr_state = 2;
}