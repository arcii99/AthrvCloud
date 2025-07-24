//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct WifiSignal {
    char ssid[50];
    int signal_strength;
};

int main() {
    int num_signals;
    printf("Enter the number of Wi-Fi signals to analyze: ");
    scanf("%d", &num_signals);
    struct WifiSignal signals[num_signals];

    for(int i=0; i<num_signals; i++) {
        printf("Enter the SSID of Wi-Fi signal #%d: ", (i+1));
        scanf("%s", signals[i].ssid);
        printf("Enter the signal strength (0-100) of Wi-Fi signal #%d: ", (i+1));
        scanf("%d", &signals[i].signal_strength);
    }

    int strongest_signal = 0;
    int weakest_signal = 100;
    for(int i=0; i<num_signals; i++) {
        if(signals[i].signal_strength > strongest_signal) {
            strongest_signal = signals[i].signal_strength;
        }
        if(signals[i].signal_strength < weakest_signal) {
            weakest_signal = signals[i].signal_strength;
        }
    }

    printf("\nThe strongest Wi-Fi signal is '%s' with a signal strength of %d%%.\n", signals[strongest_signal].ssid, signals[strongest_signal].signal_strength);
    printf("The weakest Wi-Fi signal is '%s' with a signal strength of %d%%.\n", signals[weakest_signal].ssid, signals[weakest_signal].signal_strength);

    return 0;
}