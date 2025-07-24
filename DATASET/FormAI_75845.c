//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MIN_RSSI -100
#define MAX_RSSI 0

void print_signal_strength(int signal_strength) {
    if(signal_strength < -80) {
        printf("\033[0;31m"); // red color
        printf("Signal strength: %d (Weak)\n", signal_strength);
        printf("\033[0m"); // reset color
    } else if(signal_strength < -60) {
        printf("\033[1;33m"); // yellow color
        printf("Signal strength: %d (Fair)\n", signal_strength);
        printf("\033[0m"); // reset color
    } else {
        printf("\033[0;32m"); // green color
        printf("Signal strength: %d (Strong)\n", signal_strength);
        printf("\033[0m"); // reset color
    }
}

int main() {
    char ssid[MAX_SIZE];
    int signal_strength = 0;

    printf("Enter SSID: ");
    fgets(ssid, MAX_SIZE, stdin); // read input from user
    ssid[strcspn(ssid, "\n")] = 0; // remove newline character

    printf("Enter signal strength (in dBm): ");
    scanf("%d", &signal_strength);

    if(signal_strength < MIN_RSSI || signal_strength > MAX_RSSI) {
        printf("Invalid signal strength. Please enter a value between -100 and 0 dBm.\n");
        exit(1);
    }

    printf("Analyzing Wi-Fi signal...\n");
    printf("SSID: %s\n", ssid);
    print_signal_strength(signal_strength);

    return 0;
}