//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function to calculate Wi-Fi signal strength
double calculateSignalStrength(int distance, int frequency, int power) {
    double signalStrength = power - (20 * log10(distance) + 20 * log10(frequency) + 92.45);
    return signalStrength;
}

int main() {
    int distance, frequency, power;
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    printf("Enter the distance (in meters) from the Wi-Fi hotspot: ");
    scanf("%d", &distance);
    printf("Enter the frequency (in GHz) of the Wi-Fi router: ");
    scanf("%d", &frequency);
    printf("Enter the power (in dBm) of the Wi-Fi router: ");
    scanf("%d", &power);
    
    double signalStrength = calculateSignalStrength(distance, frequency, power);
    
    printf("\nCalculating Wi-Fi signal strength...\n");
    printf("Distance from Wi-Fi hotspot: %d meters\n", distance);
    printf("Frequency of Wi-Fi router: %d GHz\n", frequency);
    printf("Power of Wi-Fi router: %d dBm\n", power);
    printf("Signal strength of Wi-Fi hotspot: %.2lf dBm\n\n", signalStrength);
    
    if(signalStrength >= -50) {
        printf("You are standing right next to the Wi-Fi hotspot!\n");
    } else if(signalStrength >= -60 && signalStrength < -50) {
        printf("You are very close to the Wi-Fi hotspot.\n");
    } else if(signalStrength >= -70 && signalStrength < -60) {
        printf("You are close to the Wi-Fi hotspot.\n");
    } else if(signalStrength >= -80 && signalStrength < -70) {
        printf("You are at a moderate distance from the Wi-Fi hotspot.\n");
    } else if(signalStrength >= -90 && signalStrength < -80) {
        printf("You are at a far distance from the Wi-Fi hotspot.\n");
    } else {
        printf("You are out of range from the Wi-Fi hotspot!\n");
    }
    
    return 0;
}