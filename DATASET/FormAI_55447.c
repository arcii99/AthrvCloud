//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_READINGS 10 // Number of Wi-Fi signal strength readings
#define MAX_SIGNAL 100 // Max Wi-Fi signal strength
#define MIN_SIGNAL 20 // Min Wi-Fi signal strength
#define THRESHOLD 70 // Wi-Fi signal strength for alarm

int main() {
    int readings[NUM_OF_READINGS];
    int sum = 0;
    float avg;
    srand(time(NULL)); // Seed for random numbers

    // Generate random Wi-Fi signal strength readings between MIN_SIGNAL and MAX_SIGNAL
    for (int i = 0; i < NUM_OF_READINGS; i++) {
        int reading = rand() % (MAX_SIGNAL - MIN_SIGNAL + 1) + MIN_SIGNAL;
        readings[i] = reading;
        sum += reading;
        printf("Reading %d: %d\n", i+1, reading);
    }

    // Calculate average Wi-Fi signal strength
    avg = (float)sum / NUM_OF_READINGS;
    printf("Average Wi-Fi signal strength: %.2f\n", avg);

    // Check if Wi-Fi signal strength is above threshold and sound alarm if necessary
    if (avg >= THRESHOLD) {
        printf("Wi-Fi signal strength above threshold! Alarm sounding...\n");
        // Code to sound alarm
    } else {
        printf("Wi-Fi signal strength below threshold. No alarm needed.\n");
    }

    return 0;
}