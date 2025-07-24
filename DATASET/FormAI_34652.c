//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_READINGS 10

int main(void) {
    char ssid[20];
    int signal_strength;
    int readings[NUM_OF_READINGS];
    int reading_count = 0;
    int total_signal_strength = 0;
    float average_signal_strength;

    printf("Enter the SSID of the WiFi network:\n");
    fgets(ssid, 20, stdin);

    printf("Scanning for WiFi signal strength...\n");

    // Generate random signal strength readings
    for(int i = 0; i < NUM_OF_READINGS; i++) {
        readings[i] = rand() % 101; // range is from 0 to 100
        total_signal_strength += readings[i];
        reading_count++;
    }

    // Calculate average signal strength
    average_signal_strength = (float) total_signal_strength / reading_count;

    // Print the results
    printf("Signal strength for network %s:\n", ssid);
    printf("-------------------------------\n");

    printf("Readings over the past %d seconds:\n", NUM_OF_READINGS);
    for(int i = 0; i < NUM_OF_READINGS; i++) {
        printf("%d ", readings[i]);
    }
    printf("\n");

    printf("Average signal strength: %.2f\n", average_signal_strength);
    printf("Signal strength quality: ");

    // Print quality of signal strength
    if(average_signal_strength >= 90.0) {
        printf("Excellent\n");
    } else if(average_signal_strength >= 70.0) {
        printf("Good\n");
    } else if(average_signal_strength >= 50.0) {
        printf("Fair\n");
    } else {
        printf("Poor\n");
    }

    return 0;
}