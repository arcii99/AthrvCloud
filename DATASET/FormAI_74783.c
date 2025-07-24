//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_SCAN_RESULTS 100

typedef struct {
    char ssid[32];
    char bssid[18];
    int rssi;
    int channel;
} ScanResult;

int convertHexToInt(char *hex) {
    int dec = 0;
    int i;

    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += hex[i] - 48;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += hex[i] - 87;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += hex[i] - 55;
        } else {
            return -1;
        }

        if (hex[i+1] != '\0') {
            dec *= 16;
        }
    }

    return dec;
}

void displayScanResults(ScanResult *results, int count) {
    int i;

    printf("\n\nSSID\t\tBSSID\t\t\tRSSI\tCHANNEL\n");
    for (i = 0; i < count; i++) {
        printf("%-16s%-22s%-4d\t%d\n", results[i].ssid, results[i].bssid, results[i].rssi, results[i].channel);
    }
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    ScanResult scanResults[MAX_SCAN_RESULTS];
    int scanResultCount = 0;
    int i;

    FILE *fp;
    fp = fopen("wifi_scan_results.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        char *token;
        char *tokens[4];
        int j = 0;

        token = strtok(buffer, ",");
        while (token != NULL) {
            tokens[j++] = token;
            token = strtok(NULL, ",");
        }

        if (j == 4) {
            strncpy(scanResults[scanResultCount].ssid, tokens[0], sizeof(scanResults[scanResultCount].ssid));
            strncpy(scanResults[scanResultCount].bssid, tokens[1], sizeof(scanResults[scanResultCount].bssid));
            scanResults[scanResultCount].rssi = convertHexToInt(tokens[2]);
            scanResults[scanResultCount].channel = atoi(tokens[3]);
            
            scanResultCount++;
        }
    }

    fclose(fp);

    displayScanResults(scanResults, scanResultCount);

    return 0;
}