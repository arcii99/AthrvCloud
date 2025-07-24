//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 20

// Struct to represent a network
typedef struct Network {
    char ssid[MAX_SSID_LENGTH];
    int strength;
} Network;

/**
 * Function to read the SSID from stdin
 */
void read_ssid(char* ssid) {
    printf("Enter the SSID of the network: ");
    scanf("%s", ssid);
}

/**
 * Function to check if the SSID is valid
 */
bool is_valid_ssid(char* ssid) {
    int length = strlen(ssid);
    if (length >= 1 && length <= MAX_SSID_LENGTH) {
        for (int i = 0; i < length; i++) {
            if (!isprint(ssid[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

/**
 * Function to read the strength of the network from stdin
 */
void read_strength(int* strength) {
    printf("Enter the strength of the network (0-100): ");
    scanf("%d", strength);
}

/**
 * Function to initialize the networks array
 */
void initialize_networks(Network* networks, int* num_networks) {
    *num_networks = 0;
    for (int i = 0; i < MAX_NETWORKS; i++) {
        memset(networks[i].ssid, 0, sizeof(networks[i].ssid));
        networks[i].strength = 0;
    }
}

/**
 * Function to add a network to the networks array
 */
void add_network(Network* networks, int* num_networks) {
    char ssid[MAX_SSID_LENGTH];
    int strength;

    read_ssid(ssid);
    while (!is_valid_ssid(ssid)) {
        printf("Invalid SSID. Please try again.\n");
        read_ssid(ssid);
    }

    read_strength(&strength);
    while (strength < 0 || strength > 100) {
        printf("Invalid strength. Please try again.\n");
        read_strength(&strength);
    }

    if (*num_networks < MAX_NETWORKS) {
        strcpy(networks[*num_networks].ssid, ssid);
        networks[*num_networks].strength = strength;
        *num_networks += 1;
    } else {
        printf("Maximum number of networks reached.\n");
    }
}

/**
 * Function to print the list of networks
 */
void print_networks(Network* networks, int num_networks) {
    printf("SSID\t\t\tStrength\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s\t\t\t%d\n", networks[i].ssid, networks[i].strength);
    }
}

/**
 * Function to scan for networks
 */
void scan_networks(Network* networks, int* num_networks) {
    // Simulate network scanning by adding a few networks
    if (*num_networks == 0) {
        strcpy(networks[0].ssid, "My WiFi");
        networks[0].strength = 75;

        strcpy(networks[1].ssid, "Home WiFi");
        networks[1].strength = 90;

        strcpy(networks[2].ssid, "Work WiFi");
        networks[2].strength = 65;

        *num_networks = 3;
    } else {
        printf("Networks already scanned.\n");
    }
}

int main(void) {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;
    int choice;

    initialize_networks(networks, &num_networks);

    do {
        printf("1. Scan for networks\n");
        printf("2. Add a network\n");
        printf("3. Print networks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scan_networks(networks, &num_networks);
                break;
            case 2:
                add_network(networks, &num_networks);
                break;
            case 3:
                print_networks(networks, num_networks);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}