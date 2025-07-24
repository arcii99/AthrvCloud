//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int wifi_strength = 0;
    int signal_distance = 0;

    printf("Wi-Fi Signal Strength Analyzer\n");

    for (int i = 1; i <= 5; i++) {
        printf("Scanning signal distance...\n");
        srand(time(0));
        signal_distance = (rand() % 10) + 1;
        printf("Signal distance: %d km\n", signal_distance);

        wifi_strength = 50 - signal_distance * 5;

        if (wifi_strength > 0) {
            printf("Connecting to Wi-Fi network...\n");
            printf("Wi-Fi signal strength: %ddBm\n", wifi_strength);
        } else {
            printf("No Wi-Fi network in range.\n");
        }
        printf("\n");
    }

    printf("Exiting Wi-Fi Signal Strength Analyzer\n");

    return 0;
}