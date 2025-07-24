//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

void detect_intrusion(char *packet) {
    int len = strlen(packet);
    int i;
    int alpha = 0, numeric = 0, special = 0;

    // Check for the presence of suspicious keywords
    if(strstr(packet, "root") || strstr(packet, "hack") || strstr(packet, "password")) {
        printf("Suspicions of server intrusion detected!\n");
        return;
    }

    // Check for the ratio of alphabets, numbers and special characters
    for(i = 0; i < len; i++) {
        if(isalpha(packet[i])) {
            alpha++;
        } else if(isdigit(packet[i])) {
            numeric++;
        } else {
            special++;
        }
    }

    if(alpha/numeric >= 3 || alpha/special >= 3) {
        printf("Suspicions of server intrusion detected!\n");
        return;
    }

    printf("No intrusions detected.\n");
}

int main() {
    char packet[MAX_PACKET_SIZE];
    printf("Enter packet data:\n");
    fgets(packet, MAX_PACKET_SIZE, stdin);
    detect_intrusion(packet);

    return 0;
}