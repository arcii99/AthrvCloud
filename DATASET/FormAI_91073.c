//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Ask user for input
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a year between 1900 and 2021: ");

    int year;
    scanf("%d", &year);

    // Check if input is valid
    if (year < 1900 || year > 2021) {
        printf("Invalid input. Please enter a year between 1900 and 2021.\n");
        printf("Exiting the program...\n");
        return 0;
    }

    // Determine the era based on the year
    char* era;

    if (year >= 1900 && year <= 1919) {
        era = "the early 1900s";
    } else if (year >= 1920 && year <= 1949) {
        era = "the Roaring Twenties";
    } else if (year >= 1950 && year <= 1979) {
        era = "the era of free love";
    } else if (year >= 1980 && year <= 2009) {
        era = "the age of computers";
    } else {
        era = "modern times";
    }

    // Create a time travel destination based on the era
    char* destination;

    if (era == "the early 1900s") {
        destination = "New York City in 1910";
    } else if (era == "the Roaring Twenties") {
        destination = "Chicago in 1925";
    } else if (era == "the era of free love") {
        destination = "San Francisco in 1967";
    } else if (era == "the age of computers") {
        destination = "Silicon Valley in 1995";
    } else {
        destination = "Tokyo in 2021";
    }

    // Calculate the number of years the user will travel
    int years_diff = abs(year - 2021);

    // Display the time travel information to the user
    printf("You have chosen to travel back in time to %s!\n", era);
    printf("Your destination is %s.\n", destination);
    printf("You will be traveling back %d years in time.\n", years_diff);

    return 0;
}