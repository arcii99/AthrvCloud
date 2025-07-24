//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIFI_STRENGTH_RANGE 50

int main() {
    srand(time(0));
    int wifi_strength = rand() % WIFI_STRENGTH_RANGE + 1;

    printf("Analyzing Wi-Fi signal strength...\n\n");

    printf("Wi-Fi Signal Strength: %ddBm\n", wifi_strength);

    if (wifi_strength >= 1 && wifi_strength <= 10) {
        printf("Signal strength is very weak. Please move closer to the Wi-Fi router.\n");
    } else if (wifi_strength >= 11 && wifi_strength <= 20) {
        printf("Signal strength is weak. Try to move closer to the Wi-Fi router.\n");
    } else if (wifi_strength >= 21 && wifi_strength <= 30) {
        printf("Signal strength is okay. You can move closer to the Wi-Fi router for better performance.\n");
    } else if (wifi_strength >= 31 && wifi_strength <= 40) {
        printf("Signal strength is good. You can still improve the signal with a Wi-Fi extender.\n");
    } else {
        printf("Signal strength is excellent. Enjoy your fast Wi-Fi speeds!\n");
    }

    return 0;
}