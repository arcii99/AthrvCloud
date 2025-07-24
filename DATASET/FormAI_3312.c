//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFF_SIZE 200

int getSignalStrength(char* output) {
   char response[MAX_BUFF_SIZE];
   FILE *fp;
   fp = popen("iwconfig wlan0 | grep Signal | awk '{print $4}' | cut -d'=' -f2", "r");
   if (fp == NULL) {
       printf("Failed to execute command.\n" );
       return -1;
   }
   fgets(response, MAX_BUFF_SIZE, fp);
   strncpy(output, response, strlen(response)-1);
   pclose(fp);
   return 0;
}

bool isSignalWeak(char* signalStrength) {
    int dBm = atoi(signalStrength);
    if (dBm <= -90) {
        return true;
    }
    return false;
}

int main() {
    char signalStrength[MAX_BUFF_SIZE];
    int minutes = 0;
    bool isConnected = false;
    bool isDangerous = false;
    while (true) {
        if (getSignalStrength(signalStrength) == -1) {
            printf("Failed to retrieve signal strength.\n");
            return -1;
        }
        printf("Signal Strength: %s dBm\n", signalStrength);
        if (isSignalWeak(signalStrength)) {
            printf("Warning: Signal strength is weak.\n");
        } else {
            printf("Signal strength is good.\n");
        }
        if (isConnected && isSignalWeak(signalStrength)) {
            isDangerous = true;
        }
        if (isConnected) {
            printf("You have been connected for %d minutes.\n", minutes++);
        }
        printf("\n");

        isConnected = true;
        sleep(60); // Wait for 1 minute.
    }
}