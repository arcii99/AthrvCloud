//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    char network_name[20];
    int signal_strength, antenna_height, frequency, distance;
    float signal_wavelength, fresnel_radius, obstruction_clearance;
    
    printf("Enter the name of the Wi-Fi network: ");
    fgets(network_name, 20, stdin);
    printf("\nEnter the signal strength (in dBm): ");
    scanf("%d", &signal_strength);
    printf("\nEnter the antenna height (in meters): ");
    scanf("%d", &antenna_height);
    printf("\nEnter the Wi-Fi frequency (in GHz): ");
    scanf("%d", &frequency);
    
    signal_wavelength = (float) 300 / frequency;
    distance = (int) pow(10, (27.55 - (20 * log10(frequency)) + abs(signal_strength)) / 20);
    fresnel_radius = sqrt((signal_wavelength * distance * (distance - antenna_height)) / (2 * distance));
    obstruction_clearance = (float) (fresnel_radius * 4.14) / sqrt(distance * (1 - (distance / fresnel_radius)));
    
    printf("\nNetwork name: %s", network_name);
    printf("\nSignal strength: %d dBm", signal_strength);
    printf("\nAntenna height: %d meters", antenna_height);
    printf("\nWi-Fi frequency: %d GHz", frequency);
    printf("\nSignal wavelength: %f meters", signal_wavelength);
    printf("\nDistance from the Wi-Fi router: %d meters", distance);
    printf("\nFresnel radius: %f meters", fresnel_radius);
    printf("\nObstruction clearance: %f meters", obstruction_clearance);
    
    return 0;
}