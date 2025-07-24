//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXSIZE 100

// This function checks if the input is a valid IP address
int is_valid_ip(char *ip)
{
    int num, dots = 0;
    char *ptr;
    if (ip == NULL) {
        return 0;
    }

    ptr = strtok(ip, ".");
    if (ptr == NULL) {
        return 0;
    }

    while (ptr) {
        if (!isdigit(*ptr)) {
            return 0;
        }

        num = atoi(ptr);
        if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, ".");
            if (ptr != NULL) {
                dots++;
            }
        } else {
            return 0;
        }
    }

    if (dots != 3) {
        return 0;
    }

    return 1;
}

// This function checks if the input is a valid MAC address
int is_valid_mac(char *mac)
{
    int num, colons = 0;
    char *ptr;
    if (mac == NULL) {
        return 0;
    }

    ptr = strtok(mac, ":");
    if (ptr == NULL) {
        return 0;
    }

    while (ptr) {
        if (strlen(ptr) != 2) {
            return 0;
        }

        if (!isxdigit(*ptr) || !isxdigit(*(ptr+1))) {
            return 0;
        }

        ptr = strtok(NULL, ":");
        if (ptr != NULL) {
            colons++;
        }
    }

    if (colons != 5) {
        return 0;
    }

    return 1;
}

int main()
{
    int i, j, k, l;
    int num_nodes;
    char ip[MAXSIZE], mac[MAXSIZE];

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    // Array to store the IP and MAC addresses of the nodes
    char nodes[num_nodes][MAXSIZE][MAXSIZE];

    // Taking input of IP and MAC addresses of the nodes
    for (i = 0; i < num_nodes; i++) {
        printf("Enter IP address and MAC address of node %d: ", i+1);
        scanf("%s %s", ip, mac);

        // Checking if the input is valid
        if (!is_valid_ip(ip) || !is_valid_mac(mac)) {
            printf("\n-- Invalid Input! Please enter a valid IP and MAC address. --\n\n");
            i--;
            continue;
        }

        // Adding the IP and MAC addresses to the array
        strcpy(nodes[i][0], ip);
        strcpy(nodes[i][1], mac);
    }

    // Printing the adjacency matrix
    printf("\n\nAdjacency Matrix:\n");
    for (i = 0; i < num_nodes; i++) {
        // Printing the IP and MAC addresses of the node
        printf("%s (%s) : ", nodes[i][0], nodes[i][1]);

        // Checking the connectivity of the node with other nodes and printing the adjacency matrix
        for (j = 0; j < num_nodes; j++) {
            if (i == j) {
                printf("X ");
                continue;
            }
            int connected = 0;
            for (k = 0; k < MAXSIZE; k++) {
                if (strcmp(nodes[i][k], "") == 0) {
                    break;
                }
                for (l = 0; l < MAXSIZE; l++) {
                    if (strcmp(nodes[j][l], "") == 0) {
                        break;
                    }
                    if (strcmp(nodes[i][k], nodes[j][l]) == 0) {
                        connected = 1;
                        break;
                    }
                }
                if (connected) {
                    break;
                }
            }
            if (connected) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}