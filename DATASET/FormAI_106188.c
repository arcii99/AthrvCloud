//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM_SAMPLES 1000
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int rssi;
} wifi_sample_t;

int get_signal_strength(wifi_sample_t *samples, int num_samples, char *ssid) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < num_samples; i++) {
        if (strcmp(samples[i].ssid, ssid) == 0) {
            sum += samples[i].rssi;
            count++;
        }
    }
    if (count == 0) {
        return -1;
    }
    return round(1.0 * sum / count);
}

int main() {
    wifi_sample_t samples[MAX_NUM_SAMPLES];
    int num_samples = 0;
    
    // Read in Wi-Fi samples from file or input
    // ...
    
    // Print signal strength for a few example SSIDs
    printf("Signal strength for 'MySSID': %d dBm\n", get_signal_strength(samples, num_samples, "MySSID"));
    printf("Signal strength for 'SecondSSID': %d dBm\n", get_signal_strength(samples, num_samples, "SecondSSID"));
    
    return 0;
}