//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NUM_NETWORKS 20

void scanNetworks() {
    printf("Scanning for networks...\n");
    sleep(3);  // Takes some time to scan!

    int numNetworks = rand() % MAX_NUM_NETWORKS + 1;  // Random number of networks found
    printf("Found %d networks:\n", numNetworks);

    for(int i=0; i<numNetworks; i++) {
        char* networkName = (char*)malloc(15);  // Allocate memory randomly
        for(int j=0; j<14; j++) {
            networkName[j] = rand() % 26 + 'a';  // Randomly generate characters from a to z
        }
        networkName[14] = '\0';  // Null-terminate the string
        
        int signalStrength = rand() % 100;  // Random signal strength
        printf("%d. %s (signal strength: %d%%)\n", i+1, networkName, signalStrength);

        free(networkName);  // Free memory to avoid memory leaks
    }
}

int main() {
    printf("Welcome to the Wireless Network Scanner!\n");

    char userInput;
    do {
        printf("\nPress any key to scan for networks (q to quit): ");
        scanf("%c", &userInput);

        if(userInput != 'q') {
            scanNetworks();
        }
    } while(userInput != 'q');

    printf("\nGoodbye! Thanks for using our program!\n");

    return 0;
}