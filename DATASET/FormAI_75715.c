//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to find Wi-Fi signal strength
int findSignalStrength(int rssi)
{
    int signalStrength = 0;
    
    if (rssi <= -100)
        signalStrength = 0;
    else if (rssi >= -50)
        signalStrength = 100;
    else
        signalStrength = 2*(rssi + 100);
    
    return signalStrength;
}

// Main function
int main()
{
    char *ssid;
    int rssi;

    // Read input from user
    printf("Enter SSID name: ");
    scanf("%s", ssid);
    printf("Enter signal strength (in dBm): ");
    scanf("%d", &rssi);
    
    // Find the Wi-Fi signal strength
    int signal = findSignalStrength(rssi);
    
    // Print the result
    printf("\nSSID: %s\n", ssid);
    printf("Signal Strength: %d%%\n", signal);
    
    return 0;
}