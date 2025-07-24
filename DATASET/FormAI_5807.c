//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
#include <stdio.h> // to perform I/O operations
#include <stdlib.h>

#define MAX_SSID_LEN 100  //Max length of the SSIDs stored
#define MAX_NETWORKS 100   //Max number of networks that the array can store
#define MAX_SIGNAL 1000    //Max possible signal strength value
#define SCAN_INTERVAL 3   //Scan Interval for networks in seconds 

// Structure to hold network information
struct network {
    char ssid[MAX_SSID_LEN];
    int signalStrength;
};

// Method to scan for Wi-Fi networks and return an array of networks
int scanForNetworks(struct network *networks) {
    printf("Scanning for Wi-Fi Networks...\n");
    int numNetworks = 0;
    // Simulating the scanning process by generating random data
    for(int i=0; i<MAX_NETWORKS; i++) {
        int randSignal = rand() % MAX_SIGNAL;
        if(randSignal > 500) {
            sprintf(networks[numNetworks].ssid, "Network%d", i+1);
            networks[numNetworks].signalStrength = randSignal;
            numNetworks++;
        }
    }
    return numNetworks;
}

// Method to print details of each network
void printNetwork(struct network n) {
    printf("%-20s: ", n.ssid);
    for (int i = 0; i < n.signalStrength/20; ++i) {
        printf("#");
    }
    printf("\n");
}

// Method to print all the detected networks
void printAllNetworks(struct network *networks, int numNetworks) {
    printf("\nNetwork Name        : Signal Strength\n");
    printf("--------------------------------------\n");
    for(int i=0; i<numNetworks; i++) {
        printNetwork(networks[i]);
    }
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n\n");
    struct network networks[MAX_NETWORKS];
    int numNetworks = 0;
    while(1) {
        numNetworks = scanForNetworks(networks);
        printAllNetworks(networks, numNetworks);
        printf("\nScanning again in %d seconds...\n", SCAN_INTERVAL);
        sleep(SCAN_INTERVAL);
        system("clear");
    }
    return 0;
}