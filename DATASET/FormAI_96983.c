//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIFI_STRENGTH 100

// Function to generate random wifi signal strength
int getWifiStrength() {
    srand(time(NULL));
    int strength = rand() % MAX_WIFI_STRENGTH;
    return strength;
}

int main() {
    int signalStrength = getWifiStrength();
    printf("Scanning for wifi signal strength...\n");
    printf("Signal strength: %d out of %d\n", signalStrength, MAX_WIFI_STRENGTH);
    if (signalStrength >= 80) {
        printf("Signal is strong. You can stream videos and download files.\n");
    } else if (signalStrength >= 50) {
        printf("Signal is moderate. You can browse the internet and check emails.\n");
    } else {
        printf("Signal is weak. You may experience slow internet speeds and disconnections.\n");
        printf("Please move closer to the router or check for any interferences.\n");
    }
    return 0;
}