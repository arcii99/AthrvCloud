//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MIN_RSSI -100
#define MAX_RSSI -20

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer v1.0\n\n");
    printf("Press [ENTER] to start scanning the area for Wi-Fi signals\n");
    getchar();
    
    //simulate scanning
    printf("Scanning...\n");
    sleep(2);
    
    //generate random signal strengths
    int signal1 = rand() % (MAX_RSSI - MIN_RSSI + 1) + MIN_RSSI;
    int signal2 = rand() % (MAX_RSSI - MIN_RSSI + 1) + MIN_RSSI;
    int signal3 = rand() % (MAX_RSSI - MIN_RSSI + 1) + MIN_RSSI;
    
    //print signal strengths
    printf("\nResults:\n");
    printf("Signal 1: %ddBm\n", signal1);
    printf("Signal 2: %ddBm\n", signal2);
    printf("Signal 3: %ddBm\n", signal3);
    
    //calculate average signal strength
    double average = (double)(signal1 + signal2 + signal3) / 3.0;
    
    //print average signal strength
    printf("\nAverage signal strength: %.2f dBm\n", average);
    
    //determine signal quality
    char* quality = NULL;
    
    if(average <= -90) {
        quality = "Very poor";
    }
    else if(average <= -80) {
        quality = "Poor";
    }
    else if(average <= -70) {
        quality = "Fair";
    }
    else if(average <= -60) {
        quality = "Good";
    }
    else if(average <= -50) {
        quality = "Very good";
    }
    else {
        quality = "Excellent";
    }
    
    //print signal quality
    printf("Signal quality: %s\n", quality);
    
    return 0;
}