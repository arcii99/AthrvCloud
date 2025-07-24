//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define RSSI_REFRESH_INTERVAL 1000
#define NUMBER_OF_TRIALS 10

// Structs
typedef struct {
    int x;
    int y;
} coordinates;

// Function prototypes
double calculate_distance(int signal_strength);
double calculate_signal_strength(int frequency, double distance);

int main() {
    // Initialize variables
    int wifi_frequency, wifi_signal_strength;
    coordinates device_location;

    // Get user input
    printf("Enter your device's location (x, y): ");
    scanf("%d %d", &device_location.x, &device_location.y);
    printf("Enter the Wi-Fi frequency (in MHz): ");
    scanf("%d", &wifi_frequency);

    // Run trials to get an average signal strength
    double sum_signal_strength = 0;
    for (int i=0; i<NUMBER_OF_TRIALS; i++) {
        system("iw dev wlan0 scan essid MyNetwork >/dev/null 2>&1");
        FILE *fp = popen("iw dev wlan0 scan | grep 'freq:' | awk '{print $3}'", "r");
        fscanf(fp, "%d", &wifi_frequency);
        pclose(fp);

        fp = popen("iw dev wlan0 scan | grep 'signal:' | awk '{print $4}'", "r");
        fscanf(fp, "%d", &wifi_signal_strength);
        pclose(fp);

        double distance = calculate_distance(wifi_signal_strength);
        double signal_strength = calculate_signal_strength(wifi_frequency, distance);

        sum_signal_strength += signal_strength;
        printf("Trial %d: Signal Strength = %0.2f dBm\n", i+1, signal_strength);
        usleep(RSSI_REFRESH_INTERVAL);
    }

    double avg_signal_strength = sum_signal_strength / NUMBER_OF_TRIALS;
    printf("Average Signal Strength = %0.2f dBm\n", avg_signal_strength);
    return 0;
}

double calculate_distance(int signal_strength) {
    double exp = (27.55 - (20 * log10(2412)) + abs(signal_strength)) / 20.0;
    return pow(10.0, exp);
}

double calculate_signal_strength(int frequency, double distance) {
    double exp = (27.55 - (20 * log10(frequency)) + (20 * log10(distance)));
    return exp;
}