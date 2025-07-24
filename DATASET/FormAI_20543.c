//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Future Time Travel Simulator!\n");

    int year;
    printf("Please enter the year you wish to travel to: ");
    scanf("%d", &year);

    if (year > 2021) {
        printf("You have entered a valid year. Preparing for time travel to %d...\n", year);
        printf("Initializing time machine...\n");
        printf("Preparing for launch...\n\n");

        // code for time travel to the chosen year
        // ...
        
        printf("Arriving at year %d...\n", year);
        printf("Welcome to the future!\n");
        printf("This is what the city looks like in %d:\n", year);

        // code for displaying a 3D hologram of the future city
        // ...

        // asking the user if they want to explore the future city
        char answer;
        printf("Do you want to explore the city? (y/n) ");
        scanf(" %c", &answer);

        if (answer == 'y') {
            // code for exploring the future city
            // ...
            
            printf("Thank you for exploring the future city with us!\n");
        } else {
            printf("You can always explore the city later.\n");
        }

        printf("Preparing to return to the present...\n");
        printf("Goodbye!\n");
    } else {
        printf("Invalid year. Please enter a year in the future.\n");
    }

    return 0;
}