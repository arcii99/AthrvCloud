//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    char message[512];
    int checksum = 0;

    printf("Enter the message to calculate checksum:\n");
    fgets(message, sizeof(message), stdin);

    for(int i = 0; message[i] != '\0'; i++) {
        checksum += message[i];
    }

    printf("Checksum of the message is: %d", checksum);

    return 0;
}