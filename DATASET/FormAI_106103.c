//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int year = 2021; // initialize the current year
    int i, j;

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Enter a year to travel to: ");
    scanf("%d", &j);

    printf("\nTravelling to the year %d...\n\n", j);

    for(i = year; i <= j; i++) {
        int rand_event = rand() % 100; // random number between 0 and 99

        if(rand_event < 10) {
            printf("%4d: World War III breaks out!\n", i);
        }
        else if(rand_event < 20) {
            printf("%4d: Alien invasion!\n", i);
        }
        else if(rand_event < 30) {
            printf("%4d: Time paradox creates alternate reality!\n", i);
        }
        else if(rand_event < 40) {
            printf("%4d: Zombie apocalypse!\n", i);
        }
        else if(rand_event < 50) {
            printf("%4d: Robot uprising!\n", i);
        }
        else if(rand_event < 60) {
            printf("%4d: Time travel discovered!\n", i);
        }
        else if(rand_event < 70) {
            printf("%4d: Peaceful year.\n", i);
        }
        else {
            printf("%4d: Unknown event.\n", i);
        }
    }

    printf("\nArrived at the year %d.\n", j);
    printf("Thank you for using the Time Travel Simulator!\n");

    return 0;
}