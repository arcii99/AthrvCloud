//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DEVICES 10
#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate random signal strengths for each device
    int signal_strengths[NUM_DEVICES];
    for (int i = 0; i < NUM_DEVICES; i++) {
        signal_strengths[i] = (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
    }

    // Display the signal strengths
    printf("Signal Strengths:\n");
    for (int i = 0; i < NUM_DEVICES; i++) {
        printf("Device %d: %d\n", i + 1, signal_strengths[i]);
    }

    // Calculate the average signal strength
    int total_signal_strength = 0;
    for (int i = 0; i < NUM_DEVICES; i++) {
        total_signal_strength += signal_strengths[i];
    }
    int average_signal_strength = total_signal_strength / NUM_DEVICES;
    printf("\nAverage Signal Strength: %d\n", average_signal_strength);

    // Find the device with the strongest signal
    int strongest_device = 1;
    int strongest_signal = signal_strengths[0];
    for (int i = 1; i < NUM_DEVICES; i++) {
        if (signal_strengths[i] > strongest_signal) {
            strongest_device = i + 1;
            strongest_signal = signal_strengths[i];
        }
    }
    printf("\nStrongest Signal: Device %d (%d)\n", strongest_device, strongest_signal);

    // Find the device with the weakest signal
    int weakest_device = 1;
    int weakest_signal = signal_strengths[0];
    for (int i = 1; i < NUM_DEVICES; i++) {
        if (signal_strengths[i] < weakest_signal) {
            weakest_device = i + 1;
            weakest_signal = signal_strengths[i];
        }
    }
    printf("\nWeakest Signal: Device %d (%d)\n", weakest_device, weakest_signal);

    return 0;
}