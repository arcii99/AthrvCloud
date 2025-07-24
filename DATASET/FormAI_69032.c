//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIFI_STRENGTH 100 // Maximum Wi-Fi strength value

float average_strength(int strength[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += strength[i];
    }
    return (float)sum / n;
}

int main() {
    int strength[5]; // Store the five Wi-Fi strength samples
    char ssid[20]; // Store the Wi-Fi network name
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    printf("Please enter the name of the Wi-Fi network:\n");
    scanf("%s", ssid);
    printf("Thank you! Please ensure that you are connected to '%s'.\n", ssid);
    printf("Please wait while we collect Wi-Fi signal strength data...\n\n");

    for (int i = 1; i <= 5; i++) {
        printf("Collecting sample %d...\n", i);
        strength[i-1] = rand() % MAX_WIFI_STRENGTH + 1;
        printf("Wi-Fi signal strength: %d\n\n", strength[i-1]);
    }

    float avg_strength = average_strength(strength, 5);
    printf("Average Wi-Fi signal strength: %.2f\n", avg_strength);

    // Output signal strength rating based on average value
    if (avg_strength >= 90) {
        printf("Signal strength rating: Excellent!\n");
    } else if (avg_strength >= 70) {
        printf("Signal strength rating: Good\n");
    } else if (avg_strength >= 50) {
        printf("Signal strength rating: Fair\n");
    } else if (avg_strength >= 30) {
        printf("Signal strength rating: Poor\n");
    } else {
        printf("Signal strength rating: Very poor\n");
    }
    return 0;
}