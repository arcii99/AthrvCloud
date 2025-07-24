//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SAMPLES 10  // Number of samples to take during signal strength calculation
#define MIN_RSSI -100    // Minimum possible RSSI value
#define MAX_RSSI 0       // Maximum possible RSSI value

typedef struct {
    char ssid[32];      // Name of the Wi-Fi network
    int rssi;           // Received signal strength indicator (RSSI) in dBm
} WiFiData;

int main() {
    
    WiFiData wifi;
    int totalRssi = 0;  // Total RSSI value across samples
    int avgRssi = 0;    // Average RSSI value across samples
    
    // Get user input for Wi-Fi network name
    printf("Enter the name of the Wi-Fi network: ");
    scanf("%s", wifi.ssid);
    
    // Loop to capture RSSI values and calculate average
    for(int i = 0; i < NUM_SAMPLES; i++) {
        // Simulate RSSI value between MIN_RSSI and MAX_RSSI
        wifi.rssi = rand() % (MAX_RSSI - MIN_RSSI + 1) + MIN_RSSI;
        
        // Add RSSI value to total
        totalRssi += wifi.rssi;
        
        // Display current RSSI value
        printf("Sample %d: %s RSSI = %ddb\n", i+1, wifi.ssid, wifi.rssi);
    }
    
    // Calculate average RSSI
    avgRssi = totalRssi / NUM_SAMPLES;
    
    // Display average RSSI value
    printf("\nAverage %s RSSI = %ddb\n", wifi.ssid, avgRssi);
    
    return 0;
}