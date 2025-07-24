//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 10
#define MAX_DELAY 5

void print_traffic_light(char color) {
    switch(color) {
        case 'G': printf("The light is green. All cars go!\n");
                  break;
        case 'Y': printf("The light is yellow. Get ready to stop!\n");
                  break;
        case 'R': printf("The light is red. All cars must stop!\n");
                  break;
    }
}

int main() {
    char light_color = 'G';
    int i, num_cars = 0, delay;
    srand(time(NULL));

    printf("Welcome to the Traffic Flow Simulation!\n");

    while(1) {
        printf("Press Enter to change the traffic light.\n");
        getchar();

        if(light_color == 'G') {
            light_color = 'Y';
        } else if(light_color == 'Y') {
            light_color = 'R';
        } else if(light_color == 'R') {
            light_color = 'G';
        }

        print_traffic_light(light_color);

        if(light_color == 'G') {
            num_cars += rand() % MAX_CARS; // add new cars
        }

        printf("Number of cars on the road: %d\n", num_cars);

        for(i = 1; i <= num_cars; i++) {
            printf("Car %d is moving...\n", i);

            delay = rand() % MAX_DELAY;

            if(delay > 3) {
                printf("Car %d has stopped at the red light.\n", i);
            } else {
                printf("Car %d has passed the green light.\n", i);
            }
        }

        printf("\n");
    }

    return 0;
}