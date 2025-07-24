//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int weather; // variable to store the random weather condition
    srand(time(0)); // seed for the random number generator
    
    printf("Welcome to the Weather Simulator!\n");
    printf("---------------------------------\n");

    while(1) {
        weather = rand() % 3; // generate a random number between 0-2
        
        if(weather == 0) {
            printf("Today's weather is sunny.\n");
        }
        else if(weather == 1) {
            printf("Today's weather is cloudy.\n");
        }
        else {
            printf("Today's weather is rainy.\n");
        }

        char choice;
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &choice);

        if(choice == 'n' || choice == 'N') {
            printf("Thank you for using the Weather Simulator!\n");
            break;
        }
    }

    return 0;
}