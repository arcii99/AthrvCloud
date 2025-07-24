//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MAX_SSID_LENGTH 128

/* Function to print the signal strength table */
void printTable(double *table, int numPoints) {
    int i;
    printf("Signal Strength Table\n");
    printf("Signal Strength\t\tPercentage of Maximum Signal Strength\n");

    for (i = 0; i < numPoints; i++) {
        printf("%3.0f\t\t\t\t%.2f%%\n", table[i], 100 * table[i]/MAX_SIGNAL_STRENGTH);
    }
    printf("------------------------------------------------------\n");
}

int main() {
    double signalStrengths[10] = {2, 10, 20, 30, 45, 60, 75, 85, 95, 100};
    int numSignalStrengths = 10;
    double table[MAX_SIGNAL_STRENGTH];
    int i, j;
    char ssid[MAX_SSID_LENGTH];

    printf("Please enter the SSID: ");
    fgets(ssid, MAX_SSID_LENGTH, stdin);
    ssid[strcspn(ssid, "\n")] = 0; //Removing the trailing newline character

    printf("Analyzing Wi-Fi signal strength for SSID: %s\n\n", ssid);

    /* Filling up the signal strength table using the signalStrengths array */
    for (i = 0; i < MAX_SIGNAL_STRENGTH; i++) {
        double sumOfPowers = 0;
        for (j = 0; j < numSignalStrengths; j++) {
            double diff = i - signalStrengths[j];
            sumOfPowers += pow(10, diff/10);
        }
        table[i] = 10 * log10(sumOfPowers);
    }

    printTable(table, MAX_SIGNAL_STRENGTH);

    return 0;
}