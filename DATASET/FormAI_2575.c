//FormAI DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int allowed = 0;
    printf("Access Granted\n");
    while (1) {
        printf("\nEnter packet data:\n");
        fgets(input, sizeof(input), stdin);
        if (strstr(input, "hack") || strstr(input, "attack")) {
            printf("\nALERT! Packet contains unauthorized data:\n%s", input);
        }
        else {
            printf("\nPacket allowed:\n%s", input);
            allowed++;
        }
        printf("\nTotal packets allowed: %d\n", allowed);
    }
    return 0;
}