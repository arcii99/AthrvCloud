//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int current_state = RED;

void sig_handler(int signum) {
    if (current_state == RED) {
        current_state = GREEN;
        printf("Green light is now on.\n");
    }
    else if (current_state == YELLOW) {
        current_state = RED;
        printf("Red light is now on.\n");
    }
    else if (current_state == GREEN) {
        current_state = YELLOW;
        printf("Yellow light is now on.\n");
    }
    alarm(5);
}

int main() {
    signal(SIGALRM, sig_handler);
    alarm(5);
    
    while(1) {
        if (current_state == RED) {
            printf("Red light is on.\n");
            sleep(1);
        }
        else if (current_state == YELLOW) {
            printf("Yellow light is on.\n");
            sleep(1);
        }
        else if (current_state == GREEN) {
            printf("Green light is on.\n");
            sleep(1);
        }
    }
    
    return 0;
}