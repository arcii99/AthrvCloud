//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

bool checkWifiConnection() {
    // Check if there is a Wi-Fi connection by randomly generating 0 or 1
    srand(time(0));
    int connectionStatus = rand() % 2;
    if(connectionStatus == 1) {
        return true;
    } else {
        return false;
    }
}

int getWifiSignalStrength() {
    int signalStrength = (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH)) + MIN_SIGNAL_STRENGTH;
    return signalStrength;
}

void displaySignalStrength(int signalStrength) {
    // Print a histogram of the signal strength
    printf("\nSignal Strength: %d\n", signalStrength);
    for(int i = MIN_SIGNAL_STRENGTH; i <= MAX_SIGNAL_STRENGTH; i+=10) {
        printf("%3d-%3d: ", i, i + 9);
        for(int j = MIN_SIGNAL_STRENGTH; j <= (i + 9); j++) {
            if(j <= signalStrength) {
                printf("|");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
}

int main() {
    bool isConnected = checkWifiConnection();
    if(isConnected) {
        int signalStrength = getWifiSignalStrength();
        displaySignalStrength(signalStrength);
    } else {
        printf("No Wi-Fi connection.\n");
    }
    return 0;
}