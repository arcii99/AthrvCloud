//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define MINIMUM_SIGNAL 10

typedef struct wifiSignalReading {
    char ssid[20];
    int signalStrength; // in dBm
} WiFiSignalReading;

// Function to compare WiFi signal strengths
int compareSignalStrength(const void *a, const void *b) {
    int strength1 = ((WiFiSignalReading*)a)->signalStrength;
    int strength2 = ((WiFiSignalReading*)b)->signalStrength;
    return strength2 - strength1;
}

int main() {
    WiFiSignalReading readings[MAX_SIZE];
    int numReadings = 0;

    // Read WiFi signal strength readings from a file
    FILE *fp = fopen("readings.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    printf("WiFi Signal Strength Analyzer\n\n");

    // Store the readings in an array of structs
    char line[256];
    while(fgets(line, sizeof(line), fp)) {
        char *ssid = strtok(line, ",");
        char *signal = strtok(NULL, ",");
        if(ssid != NULL && signal != NULL) {
            strcpy(readings[numReadings].ssid, ssid);
            readings[numReadings].signalStrength = atoi(signal);
            numReadings++;
        }
    }
    fclose(fp);

    // Sort the readings by signal strength
    qsort(readings, numReadings, sizeof(WiFiSignalReading), compareSignalStrength);

    printf("There are %d WiFi networks in the area.\n", numReadings);
    printf("Networks with signal strength less than %d dBm will be ignored.\n", MINIMUM_SIGNAL);

    // Calculate the average signal strength
    int totalSignalStrength = 0;
    int count = 0;
    for(int i = 0; i < numReadings; i++) {
        if(readings[i].signalStrength >= MINIMUM_SIGNAL) {
            totalSignalStrength += readings[i].signalStrength;
            count++;
        }
    }

    if(count == 0) {
        printf("\nNo networks have signal strength greater than or equal to %d dBm.\n", MINIMUM_SIGNAL);
    } else {
        printf("\nThe average signal strength of networks with signal strength greater than or equal to %d dBm is %d dBm.\n", MINIMUM_SIGNAL, totalSignalStrength/count);
    }

    // Display the top 10 networks
    printf("\nTop 10 Networks:\n");
    printf("%-20s %s\n", "SSID", "Signal Strength");
    for(int i = 0; i < fmin(numReadings, 10); i++) {
        if(readings[i].signalStrength >= MINIMUM_SIGNAL) {
            printf("%-20s %ddBm\n", readings[i].ssid, readings[i].signalStrength);
        }
    }

    return 0;
}