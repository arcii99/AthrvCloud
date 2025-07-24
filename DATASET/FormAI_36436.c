//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: synchronous
#include <stdio.h>
#include <string.h>

int calculate_checksum(char* message, int length);

int main(int argc, char** argv) {
    char message[100];
    int length, checksum;
    
    printf("Enter message: ");
    fgets(message, 100, stdin);
    
    length = strlen(message) - 1; // exclude newline character from length
    
    checksum = calculate_checksum(message, length);
    
    printf("The checksum of the message is: %d\n", checksum);
    
    return 0;
}

int calculate_checksum(char* message, int length) {
    int i, checksum = 0;
    
    for (i = 0; i < length; i++) {
        checksum += message[i];
    }
    
    return checksum;
}