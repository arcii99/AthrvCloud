//FormAI DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a given IP address is blocked
int isBlocked(char *ip, char *blocked_ips[], int num_blocked) {
    for (int i = 0; i < num_blocked; i++) {
        if (strcmp(ip, blocked_ips[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// main function
int main() {
    // define some sample blocked IP addresses
    char *blocked_ips[] = {"127.0.0.1", "192.168.1.10", "10.0.0.1"};
    int num_blocked = 3;

    // define a buffer to store the user's input
    char buffer[100];

    // loop to continuously read input and check if it is blocked
    while (1) {
        printf("Enter an IP address to check if it is blocked: ");
        scanf("%s", buffer);

        if (isBlocked(buffer, blocked_ips, num_blocked)) {
            printf("This IP address is blocked.\n");
        } else {
            printf("This IP address is not blocked.\n");
        }
    }

    return 0;
}