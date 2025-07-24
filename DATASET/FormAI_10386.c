//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: happy
#include <stdio.h>

int main() {
    int time = 0;
    int green_time = 20;
    int yellow_time = 5;
    int red_time = 20;

    while (time < 60) {
        if (time < green_time) {
            printf("The traffic light is green\n");
        } else if (time >= green_time && time < green_time + yellow_time) {
            printf("The traffic light is yellow\n");
        } else {
            printf("The traffic light is red\n");
        }

        time++;

        if (time == green_time + yellow_time + red_time) {
            time = 0;
        }
    }

    return 0;
}