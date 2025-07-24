//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEVICES 10 // Maximum number of devices in the network
#define MAX_ROUTERS 5 // Maximum number of routers in the network

// Function for generating random integers between min and max
int get_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function for generating a random IP address
void generate_ip_address(char *ip_address) {
    sprintf(ip_address, "%d.%d.%d.%d", get_random_int(0, 255), get_random_int(0, 255), get_random_int(0, 255), get_random_int(0, 255));
}

int main() {
    srand(time(NULL)); // Initialize random number generator with current time

    // Generate random devices and routers with IP addresses
    char devices[MAX_DEVICES][16];
    char routers[MAX_ROUTERS][16];
    for (int i = 0; i < MAX_DEVICES; i++) {
        generate_ip_address(devices[i]);
    }
    for (int i = 0; i < MAX_ROUTERS; i++) {
        generate_ip_address(routers[i]);
    }

    // Create adjacency matrix for the network topology
    int network[MAX_DEVICES + MAX_ROUTERS][MAX_DEVICES + MAX_ROUTERS];
    for (int i = 0; i < MAX_DEVICES + MAX_ROUTERS; i++) {
        for (int j = 0; j < MAX_DEVICES + MAX_ROUTERS; j++) {
            network[i][j] = 0;
        }
    }

    // Connect devices to routers randomly
    for (int i = 0; i < MAX_DEVICES; i++) {
        int router_index = get_random_int(0, MAX_ROUTERS - 1);
        network[i][MAX_DEVICES + router_index] = 1;
        network[MAX_DEVICES + router_index][i] = 1;
    }

    // Print the network topology
    printf("\n\nNetwork Topology:\n\n");
    printf("Devices:\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        printf("%s ", devices[i]);
    }
    printf("\n\nRouters:\n");
    for (int i = 0; i < MAX_ROUTERS; i++) {
        printf("%s ", routers[i]);
    }
    printf("\n\nConnections:\n");
    for (int i = 0; i < MAX_DEVICES + MAX_ROUTERS; i++) {
        for (int j = 0; j < MAX_DEVICES + MAX_ROUTERS; j++) {
            printf("%d ", network[i][j]);
        }
        printf("\n");
    }

    return 0;
}