//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 2048

int main() {
    char packet[MAX_PACKET_SIZE];

    while (1) {
        printf("Enter packet data: ");
        fgets(packet, MAX_PACKET_SIZE, stdin);

        if (strstr(packet, "DROP") != NULL) {
            printf("Intrusion detection: DROP command detected!\n");
            exit(0);
        }

        if (strstr(packet, "EXEC") != NULL) {
            printf("Intrusion detection: EXEC command detected!\n");
            char *cmd = packet + strlen("EXEC ") + 1; // Get the command after EXEC
            system(cmd);
        }

        if (strstr(packet, "DELETE") != NULL) {
            printf("Intrusion detection: DELETE command detected!\n");
            char *filename = packet + strlen("DELETE ") + 1; // Get the filename after DELETE
            remove(filename);
        }

        // Check for buffer overflow attacks
        if (strstr(packet, "BUFFER_OVERFLOW") != NULL) {
            char buffer[MAX_PACKET_SIZE];
            strcpy(buffer, packet);
            printf("Intrusion detection: BUFFER_OVERFLOW detected!\n");
        }
    }

    return 0;
}