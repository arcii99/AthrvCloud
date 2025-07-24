//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIGNAL_THRESHOLD -70 // minimum signal strength to be considered

char *parseSSID(char *line) {
    char *result = NULL;
    if (strncmp(line, "ESSID:", 6) == 0) {
        result = malloc(strlen(line) - 8);
        if (result) {
            strncpy(result, line + 7, strlen(line) - 8);
            result[strlen(line) - 8] = '\0';
        }
    }
    return result;
}

int parseSignalStrength(char *line) {
    int result = -1;
    if (strncmp(line, "Signal level=", 13) == 0) {
        char *signalStr = malloc(strlen(line) - 13);
        if (signalStr) {
            strncpy(signalStr, line + 13, strlen(line) - 13);
            signalStr[strlen(line) - 13] = '\0';
            int signalValue = atoi(signalStr);
            result = signalValue;
            free(signalStr);
        }
    }
    return result;
}

int main(int argc, char **argv) {
    FILE *fp;
    char path[1035];
    int signalStrength, maxSignalStrength = SIGNAL_THRESHOLD;
    char *ssid, *maxSSID;

    fp = popen("/sbin/iwconfig wlan0", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    while (fgets(path, sizeof(path), fp) != NULL) {
        ssid = parseSSID(path);
        if (ssid) {
            signalStrength = parseSignalStrength(path);
            if (signalStrength != -1 && signalStrength > maxSignalStrength) {
                maxSignalStrength = signalStrength;
                if (maxSSID != NULL) {
                    free(maxSSID);
                }
                maxSSID = ssid;
            } else {
                free(ssid);
            }
        }
    }

    pclose(fp);

    if (maxSSID == NULL) {
        printf("No wifi networks found");
    } else {
        printf("The strongest wifi signal is '%s' with signal strength of '%ddBm'", maxSSID, maxSignalStrength);
        free(maxSSID);
    }

    return 0;
}