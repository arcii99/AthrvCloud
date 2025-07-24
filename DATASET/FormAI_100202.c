//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complete
#include<stdio.h>
#include<math.h>

// function to calculate WiFi Signal Strength
int calcSignalStrength(double distance, double frequency, double txPower, double expFactor){

    double signalStrength;

    // calculating signal strength based on distance, frequency, txPower and expFactor
    signalStrength = txPower - (20 * log10(distance) + 20 * log10(frequency) + expFactor);

    // returning the calculated signal strength
    return (int)signalStrength;

}

int main(){

    double distance, frequency, txPower, expFactor;
    int signalStrength;

    printf("Enter distance (in meters) between WiFi modem and device : ");
    scanf("%lf", &distance);

    printf("Enter WiFi frequency (in GHz) : ");
    scanf("%lf", &frequency);

    printf("Enter WiFi transmitter power (in dBm) : ");
    scanf("%lf", &txPower);

    printf("Enter path loss exponent factor : ");
    scanf("%lf", &expFactor);

    // calling calcSignalStrength function to calculate signal strength
    signalStrength = calcSignalStrength(distance, frequency, txPower, expFactor);

    // printing calculated signal strength
    printf("WiFi Signal Strength : %d dBm\n", signalStrength);

    return 0;
}