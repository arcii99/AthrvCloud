//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_READINGS 10

int main() {
    char ssid[MAX_SSID_LENGTH];
    int signal_strengths[MAX_READINGS];
    int num_readings = 0;
    int total_strength = 0;
    float average_strength = 0;

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");

    printf("Please enter the SSID of the network to analyze: ");
    fgets(ssid, MAX_SSID_LENGTH, stdin);

    printf("\nStarting signal strength readings...\n");
    printf("(Press 'q' followed by Enter to stop taking readings)\n\n");

    while(num_readings < MAX_READINGS) {
        char input[MAX_SSID_LENGTH];
        printf("Reading %d: ", num_readings+1);
        fgets(input, MAX_SSID_LENGTH, stdin);
        
        // Check if user wants to quit
        if (tolower(input[0]) == 'q') {
            printf("Ending signal strength readings...\n\n");
            break;
        }

        // Convert input to integer and add to array
        signal_strengths[num_readings] = atoi(input);
        total_strength += signal_strengths[num_readings];
        num_readings++;
    }

    // Calculate and print out average signal strength
    if (num_readings > 0) {
        average_strength = (float) total_strength / (float) num_readings;
        printf("Average signal strength for network '%s': %.2f dBm\n\n", ssid, average_strength);
    } else {
        printf("No readings taken. Exiting program...\n\n");
    }

    return 0;
}