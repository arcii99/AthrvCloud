//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_checksum(char* message);

int main() {
    char message[100];
    printf("Enter a message to calculate checksum: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; //remove newline character
    int checksum = calculate_checksum(message);
    printf("The checksum of the message is: %d\n", checksum);
    return 0;
}

int calculate_checksum(char* message) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(message); i++) {
        sum += (int)message[i];
    }
    return sum % 256; //8-bit checksum
}