//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>

int main() {
    char message[100];
    printf("Enter the message to calculate checksum: ");
    fgets(message, 100, stdin);

    int checksum = 0;
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        checksum += message[i];
    }
    printf("The checksum of your message is %d\n", checksum);
    
    return 0;
}