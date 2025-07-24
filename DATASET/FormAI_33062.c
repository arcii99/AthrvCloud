//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0
#define NUM_OF_READINGS 10

int generateRandomSignalStrength() {
    return (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
}

bool isValidInput(char *input) {
    int inputLength = strlen(input);

    for (int i = 0; i < inputLength; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

void printSignalStrengths(int signalStrengths[]) {
    printf("Signal Strengths:\n");

    for (int i = 0; i < NUM_OF_READINGS; i++) {
        printf("%d\n", signalStrengths[i]);
    }
}

int calculateAverageSignalStrength(int signalStrengths[]) {
    int sum = 0;

    for (int i = 0; i < NUM_OF_READINGS; i++) {
        sum += signalStrengths[i];
    }

    return sum / NUM_OF_READINGS;
}

int main() {
    srand(time(NULL));

    int signalStrengths[NUM_OF_READINGS];

    for (int i = 0; i < NUM_OF_READINGS; i++) {
        signalStrengths[i] = generateRandomSignalStrength();
    }

    printSignalStrengths(signalStrengths);

    char userInput[4];
    int inputSignalStrength;

    do {
        printf("Enter the signal strength you are looking for (0-100): ");
        fgets(userInput, 4, stdin);
    } while (!isValidInput(userInput));

    inputSignalStrength = atoi(userInput);

    int closestReading = 0;
    int minDifference = MAX_SIGNAL_STRENGTH + 1;

    for (int i = 0; i < NUM_OF_READINGS; i++) {
        int difference = abs(signalStrengths[i] - inputSignalStrength);

        if (difference < minDifference) {
            closestReading = signalStrengths[i];
            minDifference = difference;
        }
    }

    printf("Average signal strength: %d\n", calculateAverageSignalStrength(signalStrengths));
    printf("Closest signal strength reading: %d\n", closestReading);

    return 0;
}