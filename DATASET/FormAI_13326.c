//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator

    printf("*** TIME TRAVEL SIMULATOR ***\n\n");

    // get user input for a year
    int year;
    printf("Enter a year you would like to travel to: ");
    scanf("%d", &year);

    // generate a random year to compare to user input
    int rand_year = rand() % 101 + 1920;

    if (year < 1920 || year > 2021) { // check if year is within valid range
        printf("\nInvalid year entered. Please try again.\n");
        return 0;
    }
    else {
        printf("\nTraveling to year %d...\n\n", year);
        printf("You have arrived in the year %d!\n\n", rand_year);
    }

    // generate a random event to occur during time travel
    int event = rand() % 4; // generate number between 0 and 3

    switch (event) {
        case 0:
            printf("While traveling in time, you encountered a group of dinosaurs!\n");
            break;
        case 1:
            printf("You accidentally changed a significant event in history!\n");
            break;
        case 2:
            printf("You met your future self while traveling through time!\n");
            break;
        case 3:
            printf("You traveled to a parallel universe instead of the intended time!\n");
            break;
    }

    return 0;
}