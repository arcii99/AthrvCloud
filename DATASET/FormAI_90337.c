//FormAI DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
#include <stdio.h>

int main() {

    // Declare variables
    char message[100];
    int count = 1, i, j;

    // Ask user to input message
    printf("Enter message: ");
    fgets(message, 100, stdin);

    // Count number of occurrences of each character
    for(i = 0; message[i] != '\0'; i++) {
        
        // If character has already been counted, skip it
        if(message[i] == '*') {
            continue;
        }
        
        // Count number of occurrences of character
        for(j = i + 1; message[j] != '\0'; j++) {
            if(message[i] == message[j]) {
                count++;
                message[j] = '*'; // Mark character as counted
            }
        }
        
        // Print number of occurrences of character
        printf("%c%d", message[i], count);
        count = 1; // Reset counter
    }
    
    printf("\n");
    return 0;
}