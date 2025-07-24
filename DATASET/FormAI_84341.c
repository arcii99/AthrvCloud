//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: standalone
#include <stdio.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main() {
    int current_state = RED;
    time_t start_time;
    
    while(1) {
        switch(current_state) {
            case RED:
                printf("Red Light - Stop\n");
                start_time = time(NULL);
                while(difftime(time(NULL), start_time) < 5) {} // wait for 5 seconds
                current_state = GREEN;
                break;
            
            case YELLOW:
                printf("Yellow Light - Get ready\n");
                start_time = time(NULL);
                while(difftime(time(NULL), start_time) < 2) {} // wait for 2 seconds
                current_state = RED;
                break;
                
            case GREEN:
                printf("Green Light - Go\n");
                start_time = time(NULL);
                while(difftime(time(NULL), start_time) < 10) {} // wait for 10 seconds
                current_state = YELLOW;
                break;
        }
    }
    return 0;
}