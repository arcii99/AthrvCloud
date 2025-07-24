//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

//Function to calculate time travel
double timeTravel(double time, double speed) {
    return time / sqrt(1- pow((speed/299792458),2));
}

int main() {
    int choice, year, isFuture, isPast, isPresent;
    double time, speed;
    const char* direction;

    printf("Welcome to the Time Travel Simulator!\n");
    
    do {
        printf("\nChoose the direction of time travel:\n");
        printf("1. Past\n");
        printf("2. Future\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                isPast = TRUE;
                isFuture = FALSE;
                isPresent = FALSE;
                direction = "past";
                break;
            case 2:
                isPast = FALSE;
                isFuture = TRUE;
                isPresent = FALSE;
                direction = "future";
                break;
            case 3:
                printf("\nExiting the program...");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.");
                continue;
        }

        printf("\n%s Time Travel selected!\n", direction);

        //Prompt user for the year and speed of travel
        printf("\nEnter the year you wish to travel to: ");
        scanf("%d", &year);
        printf("Enter the speed of travel(m/s): ");
        scanf("%lf", &speed);

        //Calculate the time travel required
        if(isPast) {
            time = year - 2021;
        } else {
            time = year - 2021;
        }
        double timeTravelled = timeTravel(time, speed);
        
        //Print the results of the time travel
        printf("\n%s time travel to year: %d at speed %.2lf m/s\n", direction, year, speed);
        printf("Time Travelled: %.2lf years or %.2lf seconds\n", timeTravelled, timeTravelled * 31536000);
    } while(choice != 3);

    return 0;
}