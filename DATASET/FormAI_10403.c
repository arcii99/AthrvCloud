//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Struct to hold information about a Wi-Fi access point
typedef struct {
    char ssid[20];
    int signal_strength;
} access_point;


// Function to generate a random signal strength value
int rand_signal_strength() {
    return rand() % 101;  // Random number between 0-100
}


// Function to simulate scanning for Wi-Fi APs
access_point* scan_for_aps(int num_aps) {
    // Allocate memory for the list of access points
    access_point* ap_list = (access_point*) malloc(num_aps * sizeof(access_point));
    if (ap_list == NULL) {
        printf("Error: Could not allocate memory for AP list\n");
        exit(1);
    }

    // Fill the list with random AP values
    int i;
    for (i = 0; i < num_aps; i++) {
        sprintf(ap_list[i].ssid, "AP_%d", i); // Give it a unique name
        ap_list[i].signal_strength = rand_signal_strength(); // Generate random signal strength
    }

    return ap_list; // Return the list to the caller
}


// Function to print out the list of APs
void print_ap_list(access_point* ap_list, int num_aps) {
    int i;
    printf("Wi-Fi access points found:\n");
    for (i = 0; i < num_aps; i++) {
        printf("- SSID: %s | Signal Strength: %d%%\n", ap_list[i].ssid, ap_list[i].signal_strength);
    }
}


// Main function
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Simulate scanning for Wi-Fi APs
    access_point* ap_list = scan_for_aps(10);

    // Print out the list of APs
    print_ap_list(ap_list, 10);

    // Free the memory
    free(ap_list);

    return 0;
}