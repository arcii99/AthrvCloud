//FormAI DATASET v1.0 Category: Firewall ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100

int main() {
    char input[MAX_INPUT_LEN];

    printf("Enter a packet input: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    // Apply firewall rules
    if (strstr(input, "DROP")) {
        printf("Firewall: Packet dropped.\n");
    } else {
        printf("Firewall: Packet allowed.\n");
    }

    return 0;
}