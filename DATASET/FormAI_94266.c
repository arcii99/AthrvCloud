//FormAI DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Set up array to contain firewall rules */
int rules[] = {2024, 8080, 22, 53, 80, 443, 3128, 25, 110, 143, 3306, 3389};

/* Implement a binary search algorithm to check for matching ports */
int search(int port) {
    int first = 0;
    int last = sizeof(rules) / sizeof(rules[0]) - 1;
    int middle;
    while (last >= first) {
        middle = (last + first) / 2;
        if (rules[middle] == port)
            return 1;
        if (rules[middle] < port)
            first = middle + 1;
        if (rules[middle] > port)
            last = middle - 1;
    }
    return 0;
}

/* Main program to check if a given port is allowed through the firewall */
int main(int argc, char *argv[]) {
    int port;
    /* Check for usage error */
    if (argc != 2) {
        fprintf(stderr, "Usage: ./firewall <port>\n");
        return 1;
    }
    /* Convert the command-line argument to an integer */
    port = atoi(argv[1]);
    /* Check if the port is allowed */
    if (search(port)) {
        printf("Port %d is allowed.\n", port);
    } else {
        printf("Port %d is not allowed.\n", port);
    }
    return 0;
}