//FormAI DATASET v1.0 Category: Firewall ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50];
    char firewall[3][20] = {"192.168.1.1", "10.0.0.1", "172.16.0.1"};

    printf("Enter IP address to check: ");
    scanf("%s", input);

    int is_firewall = 0;
    for (int i = 0; i < 3; i++) {
        if (strcmp(input, firewall[i]) == 0) {
            is_firewall = 1;
            break;
        }
    }

    if (is_firewall) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}