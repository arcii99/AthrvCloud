//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Declarations
int calculateYear(int year);
void apocalypse();
void postApocalypse(int year);
void travelThroughTime(int year);

int main() {
    printf("Welcome to the Time Travel Simulator!\n\n");
    travelThroughTime(2021);
    printf("\nThank you for using the Time Travel Simulator!\n");
    return 0;
}

int calculateYear(int year) {
    // Calculate the new year to time travel to
    int newYear = year - (rand() % 1000) - 500;
    printf("\nTravelling to the year %d...\n", newYear);
    return newYear;
}

void apocalypse() {
    // Show the description of the apocalypse
    printf("\nOh no! You've travelled to a time in the future where the world has ended due to a deadly virus!\n"
           "The streets are empty and all you see are ruins.\n"
           "You must find a way to survive in this post-apocalyptic world!\n\n");
}

void postApocalypse(int year) {
    // Show the description of the post-apocalyptic world
    printf("Welcome to the year %d, a time in the future where the world has ended due to a deadly virus.\n"
           "The streets are empty and all you see are ruins.\n"
           "You must find a way to survive in this post-apocalyptic world!\n\n", year);
}

void travelThroughTime(int year) {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Travel through time to a random year
    year = calculateYear(year);
    
    // Check if the year is after the apocalypse
    if (year > 2150) {
        // Show the post-apocalyptic world description
        postApocalypse(year);
    } else {
        // Show the apocalypse description
        apocalypse();
        // Loop through time until after the apocalypse
        while (year <= 2150) {
            year = calculateYear(year);
            // Show the apocalypse description
            apocalypse();
        }
        // Show the post-apocalyptic world description
        postApocalypse(year);
    }
}