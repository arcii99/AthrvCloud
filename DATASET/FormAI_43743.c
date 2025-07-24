//FormAI DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drop_packet(char *packet) {
    printf("Packet dropped: %s\n", packet);
}

int main() {
    char packet[100];
    int i;

    printf("Enter packet data (max 99 characters): ");
    scanf("%s", packet);

    for (i = 0; i < strlen(packet); i++) {
        if ((packet[i] >= 'A' && packet[i] <= 'Z') || (packet[i] >= 'a' && packet[i] <= 'z')) {
            continue;
        } else if (packet[i] == ' ') {
            printf("Whitespace character allowed.\n");
            continue;
        } else {
            drop_packet(packet);
            printf("Illegal character '%c' found at position %d.\n", packet[i], i+1);
            exit(0);
        }
    }

    printf("Packet accepted.\n");

    return 0;
}