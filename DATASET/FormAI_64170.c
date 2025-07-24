//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SSID_LEN 32
#define MAC_ADDR_LEN 6
#define MAX_NETWORKS 10

typedef struct {
    char ssid[SSID_LEN + 1];
    unsigned char mac_address[MAC_ADDR_LEN];
    int channel;
    int signal_strength;
} wireless_network;

int main(void) {
    wireless_network networks[MAX_NETWORKS];
    int num_networks = 0;
    bool found_duplicate = false;

    // scan for wireless networks
    // store the information in the networks array

    // check for duplicate networks and remove them
    for(int i = 0; i < num_networks; i++) {
        for(int j = i+1; j < num_networks; j++) {
            if(strcmp(networks[i].ssid, networks[j].ssid) == 0) {
                if(networks[i].signal_strength < networks[j].signal_strength) {
                    // remove networks[i]
                    for(int k = i; k < num_networks-1; k++) {
                        networks[k] = networks[k+1];
                    }
                    num_networks--;
                    found_duplicate = true;
                } else {
                    // remove networks[j]
                    for(int k = j; k < num_networks-1; k++) {
                        networks[k] = networks[k+1];
                    }
                    num_networks--;
                    found_duplicate = true;
                }
            }
        }
    }

    if(found_duplicate) {
        printf("Duplicate networks removed.\n\n");
    }

    // print the remaining networks
    printf("Wireless Networks Found:\n\n");
    for(int i = 0; i < num_networks; i++) {
        printf("SSID: %s\n", networks[i].ssid);
        printf("MAC Address: ");
        for(int j = 0; j < MAC_ADDR_LEN; j++) {
            printf("%02x:", networks[i].mac_address[j]);
        }
        printf("\n");
        printf("Channel: %d\n", networks[i].channel);
        printf("Signal Strength: %d dBm\n\n", networks[i].signal_strength);
    }

    return 0;
}