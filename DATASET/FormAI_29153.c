//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("This program will teleport your body to a random point in time, but be careful, you can't control where or when!\n\n");

    time_t t;
    srand((unsigned) time(&t)); // initialize random seed based on current time

    int year = rand() % 2021; // get random year up to current year
    int month = rand() % 12 + 1; // get random month 1-12
    int day = rand() % 31 + 1; // get random day 1-31
    int hour = rand() % 24; // get random hour 0-23
    int minute = rand() % 60; // get random minute 0-59
    int second = rand() % 60; // get random second 0-59

    printf("Teleporting in 3... 2... 1... *zap*\n\n");
    printf("You have arrived on %d/%d/%d at %02d:%02d:%02d!\n\n", month, day, year, hour, minute, second);

    if (year >= 1945 && year <= 1991) {
        printf("You have landed smack dab in the middle of the Cold War! Keep your head down and try not to get nuked.\n");
    } else if (year >= 1776 && year <= 1783) {
        printf("Congratulations, you have been teleported to the American Revolution! Time to choose a side and help fight for independence.\n");
    } else if (year >= 1960 && year <= 1980) {
        printf("Welcome to the disco era! Time to hit the dance floor and show off your moves.\n");
    } else {
        printf("Looks like you've landed in an unknown time period. Better keep your wits about you and try to find your way home!\n");
    }

    printf("\nThanks for trusting the Time Travel Simulator with your life (and location)! Safe travels back to the present.\n");

    return 0;
}