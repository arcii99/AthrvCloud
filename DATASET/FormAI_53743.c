//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the C Wireless Network Scanner!\n");
    printf("This program will scan for wireless networks in your area.\n");
    printf("Please make sure you are not in a microwave.\n");
    printf("Press any key to begin scanning...\n");
    getchar();

    int num_networks = 3;
    char** networks = malloc(num_networks * sizeof(char*));
    networks[0] = "Pretty Fly for a Wi-Fi";
    networks[1] = "LAN of the Dead";
    networks[2] = "Router? I hardly knew her!";

    printf("\n%d wireless networks found:\n\n", num_networks);
    for(int i = 0; i < num_networks; i++) {
        printf("%d. %s\n", i+1, networks[i]);
    }

    printf("\nWhich network would you like to connect to? ");
    int choice;
    scanf("%d", &choice);
    if(choice > num_networks) {
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }
    printf("Connecting to %s...\n", networks[choice-1]);
    printf("Please enter the password: ");
    char password[20];
    scanf("%s", password);
    printf("Authenticating...\n");
    printf("Connection successful! Have fun browsing the Internet!\n");

    free(networks);

    return 0;
}