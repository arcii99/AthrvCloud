//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

void set_light(int light) {
    switch(light) {
        case GREEN:
            printf("Green light on.\n");
            break;
        case YELLOW:
            printf("Yellow light on.\n");
            break;
        case RED:
            printf("Red light on.\n");
            break;
        default:
            printf("Invalid light.\n");
            break;
    }
}

int main() {
    int light = GREEN;
    int counter = 0;
    bool paused = false;

    printf("***Traffic Light Controller***\n");

    while(counter < 10) {
        if(!paused) {
            set_light(light);
            switch(light) {
                case GREEN:
                    sleep(5);
                    light = YELLOW;
                    break;
                case YELLOW:
                    sleep(2);
                    light = RED;
                    break;
                case RED:
                    sleep(4);
                    light = GREEN;
                    break;
                default:
                    break;
            }
        }
        
        printf("Press any key to pause/resume, or 'q' to quit.\n");
        char ch = getchar();
        
        if(ch == 'q') {
            break;
        }
        else {
            paused = !paused;
        }

        counter++;
    }

    return 0;
}