//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNALS 100
#define MAX_SSID_LENGTH 50

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Signal;

int compare_signals(const void *a, const void *b) {
    return ((Signal*) b)->signal_strength - ((Signal*) a)->signal_strength;
}

void analyze_signal_strength(Signal *signals, int num_signals) {
    printf("Analyzing signal strength...\n");
    // sort signals by descending signal strength
    qsort(signals, num_signals, sizeof(Signal), compare_signals);
    // print out sorted signals
    printf("SSID\tSignal Strength (dBm)\n");
    for (int i = 0; i < num_signals; i++) {
        printf("%s\t%d\n", signals[i].ssid, signals[i].signal_strength);
    }
}

int main() {
    Signal signals[MAX_SIGNALS];
    int num_signals = 0;
    
    // simulate Wi-Fi scan results
    strcpy(signals[0].ssid, "MyHomeNetwork");
    signals[0].signal_strength = -50;
    num_signals++;
    
    strcpy(signals[1].ssid, "Starbucks Free Wi-Fi");
    signals[1].signal_strength = -60;
    num_signals++;
    
    strcpy(signals[2].ssid, "Airport_Wi-Fi");
    signals[2].signal_strength = -70;
    num_signals++;
    
    strcpy(signals[3].ssid, "Free_Public_Wi-Fi");
    signals[3].signal_strength = -80;
    num_signals++;
    
    analyze_signal_strength(signals, num_signals);
    
    return 0;
}