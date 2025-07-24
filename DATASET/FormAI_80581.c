//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int prob = 0;
    srand(time(NULL)); // Seed the random number generator based on current time

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Get user input for number of detected UFOs
    int ufoCount;
    printf("How many unidentified flying objects have been detected? ");
    scanf("%d", &ufoCount);

    // Generate a random number between 1 and 100 to determine probability of alien invasion
    prob = rand() % 100 + 1;

    // Print out the probability of alien invasion based on the number of detected UFOs
    if (ufoCount == 0) {
        printf("The probability of an alien invasion is 0%%. No UFOs have been detected.\n");
    } else if (ufoCount > 0 && ufoCount <= 3) {
        printf("The probability of an alien invasion is %d%%. This is normal UFO activity.\n", prob);
    } else if (ufoCount > 3 && ufoCount <= 6) {
        printf("The probability of an alien invasion is %d%%. This is high UFO activity.\n", prob * 2);
    } else if (ufoCount > 6 && ufoCount <= 10) {
        printf("The probability of an alien invasion is %d%%. This is very high UFO activity.\n", prob * 3);
    } else {
        printf("The probability of an alien invasion is %d%%. You are being invaded by aliens!\n", prob * 5);
    }

    return 0;
}