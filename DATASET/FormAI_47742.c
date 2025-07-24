//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int wifiSignalStrength = 0;
    int min = -100; // minimum possible wifi signal strength
    int max = 0; // highest possible wifi signal strength
    int avg = -80; // average wifi signal strength
    int diffMin = 0; // difference between current wifi signal strength and minimum
    int diffMax = 0; // difference between current wifi signal strength and maximum
    int diffAvg = 0; // difference between current wifi signal strength and average
    srand(time(0)); // seed for random number generator
   
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    printf("Please wait while we analyze your Wi-Fi signal strength...\n");

    // Simulating signal strength fluctuations for 30 seconds
    for(int i = 0; i < 30; i++) {
        wifiSignalStrength = rand() % (max - min + 1) + min; // generating random signal strength
        printf("Wi-Fi Signal Strength: %d dBm\n", wifiSignalStrength);
        diffMin = abs(wifiSignalStrength - min); // calculating difference between current strength and minimum
        diffMax = abs(wifiSignalStrength - max); // calculating difference between current strength and maximum
        diffAvg = abs(wifiSignalStrength - avg); // calculating difference between current strength and average

        // Analyzing signal strength based on paranoid criteria
        if(diffMin <= 5 || diffMax <= 5 || diffAvg <= 10) {
            printf("Warning! Your Wi-Fi signal strength is not safe! Proceed with caution...\n");
        }
        else if(diffMin <= 10 || diffMax <= 10 || diffAvg <= 20) {
            printf("Caution: Your Wi-Fi signal strength is weaker than usual. Please check your network settings...\n");
        }
        else {
            printf("Your Wi-Fi signal strength is within the normal range. You can proceed as usual...\n");
        }
        printf("\n");
        sleep(1); // wait for 1 second before generating next signal strength value
    }
    printf("Thank you for using Wi-Fi Signal Strength Analyzer.\n");
    printf("Have a safe browsing experience!\n");

    return 0;
}