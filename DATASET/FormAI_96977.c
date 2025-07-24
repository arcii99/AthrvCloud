//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MAX_RSSI 100
#define RSSI_REFRESH_RATE 2 // seconds

void printSignalStrength(int rssi) {
    if(rssi < -80) {
        printf("[|||||     ]\n");
    } else if(rssi >= -80 && rssi < -70) {
        printf("[|||||||   ]\n");
    } else if(rssi >= -70 && rssi < -60) {
        printf("[||||||||| ]\n");
    } else if(rssi >= -60) {
        printf("[||||||||||]\n");
    }
}

void analyzeSignal(int rsid, int previousRssi) {
    int delta = abs(rsid - previousRssi);
    if(delta > 10) {
        printf("\nSignal strength changed significantly.\n");
    }
    printSignalStrength(rsid);
}

int main(int argc, char *argv[]) {
    printf("Wi-Fi Signal Strength Analyzer v1.0\n");
    printf("----------------------------------\n");

    int previousRssi = 0;
    int currentRssi = 0;
    int j = 0;

    for(;;) {
        int rssi = (int)(MAX_RSSI*sin((float)(j++ % 360)*(M_PI/180.0)));
        
        printf("\nSignal strength: %ddBm\t", rssi);
        analyzeSignal(rssi, previousRssi);
        previousRssi = rssi;

        sleep(RSSI_REFRESH_RATE);
    }
    
    return 0;
}