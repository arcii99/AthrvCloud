//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main()
{
    int num_of_cars = 0;
    bool green = false;
    bool yellow = false;
    bool red = true;

    printf("Traffic Light Controller\n");
    printf("------------------------\n\n");

    while (true) {
        printf("Number of cars waiting at the red light: %d\n", num_of_cars);

        if (red) {
            printf("The red light is on. Cars should stop.\n");

            if (num_of_cars > 0) {
                printf("The green light is turning on.\n\n");

                green = true;
                yellow = false;
                red = false;

                num_of_cars--;

                sleep(2);   // simulate time for green light

                printf("The green light is turning off.\n\n");

                green = false;
                yellow = true;
                red = false;

                sleep(1);   // simulate time for yellow light
            }
            
            else {
                printf("There are no cars waiting. Waiting for cars...\n\n");

                sleep(2);   // simulate time waiting for cars
            }
        }

        else if (green) {
            printf("The green light is on. Cars may proceed.\n");

            sleep(5);   // simulate time for green light

            green = false;
            yellow = true;
            red = false;

            printf("The green light is turning off.\n\n");

            sleep(1);   // simulate time for yellow light
        }

        else if (yellow) {
            printf("The yellow light is on. Cars should stop if possible.\n");

            sleep(2);   // simulate time for yellow light

            green = false;
            yellow = false;
            red = true;

            printf("The yellow light is turning off.\n\n");

            sleep(1);   // simulate time before red light turns on again
        }

        printf("-----------------------------------------------\n\n");
        
        // randomly add cars to queue
        if (rand() % 2 == 0) {
            num_of_cars++;
            printf("A car has arrived at the red light.\n");
        }
    }

    return 0;
}