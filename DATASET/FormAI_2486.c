//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int wifi_strenghts[10];
    int i;
    int total_strenght = 0;

    srand(time(NULL));

    printf("Scanning Wi-Fi Signals...\n");

    for (i = 0; i < 10; i++) {
        wifi_strenghts[i] = rand() % 101 - 100;
        total_strenght += wifi_strenghts[i];
        if (wifi_strenghts[i] > -30) {
            printf("WARNING! Suspiciously strong signal detected!\n");
            printf("Signal strength: %d\n", wifi_strenghts[i]);
        } else if (wifi_strenghts[i] < -90) {
            printf("WARNING! Suspiciously weak signal detected!\n");
            printf("Signal strength: %d\n", wifi_strenghts[i]);
        }
    }

    printf("\n\n");
    printf("Signal strength report:\n");

    for (i = 0; i < 10; i++) {
        printf("Signal %d: %d\n", i + 1, wifi_strenghts[i]);
    }

    printf("\n");
    printf("Average signal strength: %d\n", total_strenght / 10);

    return 0;
}