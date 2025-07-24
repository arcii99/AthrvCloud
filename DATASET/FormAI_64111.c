//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char source_ip[16];
    char dest_ip[16];
    char message[100];
} PACKET;

int main() {
    PACKET *packet = (PACKET *) malloc(sizeof(PACKET));

    printf("Enter the source IP address: ");
    scanf("%s", packet->source_ip);

    printf("Enter the destination IP address: ");
    scanf("%s", packet->dest_ip);

    printf("Enter the message: ");
    scanf(" %[^\n]s", packet->message);

    // Check for possible intrusion attempts
    if (strcmp(packet->message, "admin") == 0) {
        printf("Suspicious message detected - Possible intrusion attempt!\n");
    } else if (strcmp(packet->message, "password") == 0) {
        printf("Suspicious message detected - Possible intrusion attempt!\n");
    } else if (strcmp(packet->message, "malware") == 0) {
        printf("Suspicious message detected - Possible intrusion attempt!\n");
    }

    free(packet);

    return 0;
}