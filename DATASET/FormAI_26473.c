//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char message[100];
    int checksum = 0;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    for (int i = 0; i < sizeof(message); i++) {
        if (message[i] != '\n') {
            checksum ^= message[i];
            for (int j = 0; j < (checksum % 11); j++) {
                printf("%d", j);
            }
        }
    }
    
    printf("\nChecksum: %d\n", checksum);
    return 0;
}