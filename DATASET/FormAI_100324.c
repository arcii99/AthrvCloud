//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// function to check if connected to WiFi or not
bool isWiFiConnected() {
    char buffer[128];
    FILE* pipe = popen("iw dev wlan0 link", "r");
    if (!pipe) {
        return false;
    }
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL) {
            if (strstr(buffer, "Connected")) {
                return true;
            }
        }
    }
    pclose(pipe);
    return false;
}

// function to get current signal strength
int getSignalStrength() {
    char buffer[128];
    FILE* pipe = popen("iwconfig wlan0 | grep Link | awk '{print $2}' | cut -d= -f2", "r");
    if (!pipe) {
        return -1;
    }
    fgets(buffer, 128, pipe);
    pclose(pipe);
    int signalStrength = atoi(buffer);
    return signalStrength;
}

// main function
int main() {
    while (true) {
        if (isWiFiConnected()) {
            int signalStrength = getSignalStrength();
            if (signalStrength >= 0) {
                printf("Current signal strength: %d dBm\n", signalStrength);
            } else {
                printf("Error getting signal strength\n");
            }
        } else {
            printf("Not connected to WiFi\n");
        }
        sleep(1);
    }
    return 0;
}