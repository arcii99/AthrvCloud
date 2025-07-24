//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SSID_LENGTH 100
#define NUM_CHANNELS 14

struct access_point {
    char ssid[MAX_SSID_LENGTH];
    int channel;
    bool is_open;
};

int main() {

    // create array of access points
    struct access_point access_points[NUM_CHANNELS];
    
    // initialize all access points to closed and set their channel
    for (int i = 0; i < NUM_CHANNELS; i++) {
        strcpy(access_points[i].ssid, "");
        access_points[i].channel = i + 1;
        access_points[i].is_open = false;
    }
    
    // scan for wireless networks
    int num_networks;
    printf("Scanning for wireless networks...\n");
    printf("Enter the number of networks found: ");
    scanf("%d", &num_networks);
    getchar(); // consume newline character from scanf
    
    // iterate through each network found and add/update access point
    char ssid[MAX_SSID_LENGTH];
    for (int i = 0; i < num_networks; i++) {
        printf("Enter the name of network %d: ", i+1);
        fgets(ssid, MAX_SSID_LENGTH, stdin);
        ssid[strcspn(ssid, "\n")] = '\0'; // remove newline character from ssid
        printf("Enter the channel number of network %d (1-14): ", i+1);
        int channel;
        scanf("%d", &channel);
        getchar(); // consume newline character from scanf
        printf("Is network %d open? (y/n): ", i+1);
        char open;
        scanf("%c", &open);
        getchar(); // consume newline character from scanf
        
        // find the access point for the given channel and update its info
        for (int j = 0; j < NUM_CHANNELS; j++) {
            if (access_points[j].channel == channel) {
                strcpy(access_points[j].ssid, ssid);
                access_points[j].is_open = (open == 'y' || open == 'Y');
                break;
            }
        }
    }
    
    // print all access points
    printf("\nAccess Points:\n");
    for (int i = 0; i < NUM_CHANNELS; i++) {
        printf("Channel %d: %s (%s)\n", access_points[i].channel, access_points[i].ssid, access_points[i].is_open ? "OPEN" : "CLOSED");
    }
    
    return 0;
}