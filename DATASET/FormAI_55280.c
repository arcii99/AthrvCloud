//FormAI DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
/* 
   C Compression Algorithm
   This program compresses a message by removing consecutive occurrences of the same character, 
   replacing them with a number indicating how many consecutive occurrences of that character were removed.

   Example: "aaaabbbcccccdd" -> "a4b3c5d2"
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void compress(char* message) {
    int length = strlen(message);
    char compressed[MAX_LENGTH] = ""; // Initialize compressed message as empty string
    int count = 1;
    
    for (int i = 1; i <= length; i++) {
        if (message[i] == message[i-1]) {
            count++;
        } else {
            sprintf(compressed + strlen(compressed), "%c%d", message[i-1], count);
            count = 1;
        }
    }
    
    strcpy(message, compressed); // Update original message with compressed message
}

int main() {
    char message[MAX_LENGTH] = "aaaabbbcccccdd";
    
    printf("Before compression: %s\n", message);
    compress(message);
    printf("After compression: %s\n", message);
    
    return 0;
}