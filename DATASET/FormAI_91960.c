//FormAI DATASET v1.0 Category: Firewall ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold IP address and port number
struct IPAddress {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
    int port; // Assuming it's a TCP port number
};

// List of allowed IP addresses and ports
struct IPAddress allowedIPs[] = {
    {192, 168, 0, 1, 80},
    {10, 0, 0, 1, 22},
    {172, 16, 0, 1, 443},
    // Add more allowed IPs and ports here...
};

int numAllowedIPs = sizeof(allowedIPs) / sizeof(allowedIPs[0]);

// Function to check if a given IP address and port is allowed
int isAllowed(struct IPAddress *ip) {
    int i;
    for (i = 0; i < numAllowedIPs; i++) {
        if (ip->octet1 == allowedIPs[i].octet1 &&
            ip->octet2 == allowedIPs[i].octet2 &&
            ip->octet3 == allowedIPs[i].octet3 &&
            ip->octet4 == allowedIPs[i].octet4 &&
            ip->port == allowedIPs[i].port)
        {
            return 1; // This IP is allowed
        }
    }
    return 0; // This IP is not allowed
}

// Function to parse IP address and port number from a string
int parseIPAddress(char *str, struct IPAddress *ip) {
    char *tmp;
    int numFields = 0;

    tmp = strtok(str, ".");
    while (tmp != NULL && numFields < 4) {
        if (numFields == 0) {
            ip->octet1 = atoi(tmp);
        } else if (numFields == 1) {
            ip->octet2 = atoi(tmp);
        } else if (numFields == 2) {
            ip->octet3 = atoi(tmp);
        } else if (numFields == 3) {
            ip->octet4 = atoi(tmp);
        }
        tmp = strtok(NULL, ".");
        numFields++;
    }

    if (numFields != 4) {
        return 0;
    }

    tmp = strtok(NULL, ":");
    if (tmp == NULL) {
        return 0;
    }

    ip->port = atoi(tmp);

    return 1;
}

int main() {
    char input[100];
    struct IPAddress ip;

    while (1) {
        printf("Enter IP address and port number (e.g. 192.168.0.1:80): ");
        fgets(input, 100, stdin);

        if (parseIPAddress(input, &ip) == 0) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (isAllowed(&ip)) {
            printf("Access granted.\n");
        } else {
            printf("Access denied.\n");
        }
    }

    return 0;
}