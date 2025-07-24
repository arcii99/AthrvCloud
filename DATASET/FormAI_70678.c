//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: futuristic
#include <stdio.h>

int main() {
    char message[100];
    int i, checksum = 0;

    // Getting user input message
    printf("Enter the message: ");
    fgets(message, 100, stdin);

    // Calculating checksum
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] == ' ')
            continue;
        checksum ^= (int)(message[i]);
    }

    // Printing the checksum
    printf("The calculated checksum is: %d\n", checksum);

    return 0;
}