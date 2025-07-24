//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define MAX_SIGNALS 10

struct wifi_signal {
    char ssid[BUFFER_SIZE];
    float strength;
};

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");

    struct wifi_signal signals[MAX_SIGNALS];
    int num_signals = 0;

    char input[BUFFER_SIZE];
    while (num_signals < MAX_SIGNALS) {
        printf("Enter SSID and signal strength (press Enter on an empty line to stop):\n");
        fgets(input, sizeof(input), stdin);

        if (input[0] == '\n') {
            break;
        }

        char *token = strtok(input, ",");
        if (token) {
            strncpy(signals[num_signals].ssid, token, BUFFER_SIZE);
        }

        token = strtok(NULL, ",");
        if (token) {
            signals[num_signals].strength = atof(token);
        }

        num_signals++;
    }

    float avg_strength = 0.0;
    for (int i = 0; i < num_signals; i++) {
        avg_strength += signals[i].strength;
    }
    avg_strength /= num_signals;

    printf("\nSignal strengths:\n");
    for (int i = 0; i < num_signals; i++) {
        printf("%s: %.1f dBm ", signals[i].ssid, signals[i].strength);
        if (signals[i].strength > avg_strength) {
            printf("(above average)\n");
        } else {
            printf("(below average)\n");
        }
    }

    printf("\nAverage signal strength: %.1f dBm\n", avg_strength);

    float variance = 0.0;
    for (int i = 0; i < num_signals; i++) {
        variance += pow(signals[i].strength - avg_strength, 2);
    }
    variance /= num_signals;

    printf("Signal variance: %.1f dBm^2\n", variance);

    printf("\nSignal strengths sorted in descending order:\n");
    for (int i = 0; i < num_signals; i++) {
        int max_idx = i;
        for (int j = i + 1; j < num_signals; j++) {
            if (signals[j].strength > signals[max_idx].strength) {
                max_idx = j;
            }
        }
        struct wifi_signal temp = signals[i];
        signals[i] = signals[max_idx];
        signals[max_idx] = temp;
        printf("%s: %.1f dBm\n", signals[i].ssid, signals[i].strength);
    }

    return 0;
}