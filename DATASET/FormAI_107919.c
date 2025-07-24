//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL_DBM -20
#define MIN_SIGNAL_DBM -100

typedef struct wifi_signal {
    char ssid[20];
    int signal_strength;
} WifiSignal;

int main() {
    int signal_count;
    printf("Welcome to the WiFi Signal Strength Analyzer!\n");
    printf("How many signals would you like to analyze? ");
    scanf("%d", &signal_count);
    WifiSignal signals[signal_count];
    int strong_signals = 0;
    int weak_signals = 0;
    int strongest_signal = MIN_SIGNAL_DBM;
    int strongest_signal_index = -1;
    int weakest_signal = MAX_SIGNAL_DBM;
    int weakest_signal_index = -1;
    for (int i = 0; i < signal_count; i++) {
        printf("Please enter the SSID for signal #%d: ", i+1);
        scanf("%s", signals[i].ssid);
        printf("Please enter the signal strength in dBm for %s: ", signals[i].ssid);
        scanf("%d", &signals[i].signal_strength);
        if (signals[i].signal_strength >= MAX_SIGNAL_DBM && signals[i].signal_strength <= MIN_SIGNAL_DBM) {
            if (signals[i].signal_strength > strongest_signal) {
                strongest_signal = signals[i].signal_strength;
                strongest_signal_index = i;
            }
            if (signals[i].signal_strength < weakest_signal) {
                weakest_signal = signals[i].signal_strength;
                weakest_signal_index = i;
            }
            strong_signals++;
        } else {
            weak_signals++;
        }
    }
    printf("You analyzed %d WiFi signals.\n", signal_count);
    printf("%d signals had signal strength between %d dBm and %d dBm.\n", strong_signals, MAX_SIGNAL_DBM, MIN_SIGNAL_DBM);
    printf("%d signals had signal strength below %d dBm or above %d dBm.\n", weak_signals, MAX_SIGNAL_DBM, MIN_SIGNAL_DBM);
    if (strongest_signal_index != -1) {
        printf("The strongest signal was %s with a signal strength of %d dBm.\n", signals[strongest_signal_index].ssid, strongest_signal);
    }
    if (weakest_signal_index != -1) {
        printf("The weakest signal was %s with a signal strength of %d dBm.\n", signals[weakest_signal_index].ssid, weakest_signal);
    }
    return 0;
}