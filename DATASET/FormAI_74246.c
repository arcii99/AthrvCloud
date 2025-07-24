//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char wifiSignal[20];
    int signalStrength = 0;

    printf("Welcome to the Wi-Fi Signal Strength Analyzer program.\n\n");
    printf("Please enter the Wi-Fi signal strength (in dBm) of your network: ");

    fgets(wifiSignal, 20, stdin);
    sscanf(wifiSignal, "%d", &signalStrength);

    if (signalStrength >= -50) {
        printf("Your Wi-Fi signal strength is excellent, sir.\n\n");
    } else if (signalStrength >= -70) {
        printf("Your Wi-Fi signal strength is good, sir.\n\n");
    } else if (signalStrength >= -80) {
        printf("Your Wi-Fi signal strength is acceptable, sir.\n\n");
    } else if (signalStrength >= -90) {
        printf("Your Wi-Fi signal strength is weak, sir.\n\n");
    } else {
        printf("Your Wi-Fi signal strength is very weak, sir. You may want to consider relocating your router.\n\n");
    }

    printf("Thank you for using the Wi-Fi Signal Strength Analyzer program. Goodbye, sir.\n");

    return 0;
}