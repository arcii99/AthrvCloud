//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SSID_LENGTH 32
#define BUFFER_SIZE 4096

struct wirelessNetwork {
   char ssid[SSID_LENGTH];
   int signalStrength;
};

int main() {
    char buffer[BUFFER_SIZE];
    bool isIwlistCommandFound = false;
    struct wirelessNetwork networks[10];
    int numberOfNetworks = 0;

    FILE* inputPipe = popen("iwlist wlan0 scan", "r");
    if (inputPipe == NULL) {
        printf("Error: Failed to execute the iwlist command");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, inputPipe)) {
        char* isIwlistCommand = strstr(buffer, "wlan0     Scan completed :");
        if (isIwlistCommand != NULL) {
            isIwlistCommandFound = true;
            continue;
        }

        if (isIwlistCommandFound == true) {
            char* isNetworkSsid = strstr(buffer, "ESSID:\"");
            if (isNetworkSsid != NULL) {
                char ssid[SSID_LENGTH];
                int signalStrength = 0;
                sscanf(buffer, "          Quality=%*d/%*d  Signal level=%d dBm  %s\n", &signalStrength, ssid);
                strcpy(networks[numberOfNetworks].ssid, ssid);
                networks[numberOfNetworks].signalStrength = signalStrength;
                numberOfNetworks++;
            }
        }
    } 

    printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("Available Wi-Fi Networks with Signal Strength in Descending Order\n");
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    for (int i = 0; i < numberOfNetworks; i++) {
        for (int j = i + 1; j < numberOfNetworks; j++) {
            if (networks[i].signalStrength < networks[j].signalStrength) {
                struct wirelessNetwork temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }

    for (int i = 0; i < numberOfNetworks; i++) {
        printf("%-20s Signal Strength: %d dBm\n", networks[i].ssid, networks[i].signalStrength);
    }

    pclose(inputPipe);
    return 0;
}