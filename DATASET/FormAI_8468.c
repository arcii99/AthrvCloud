//FormAI DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {

    char message[100] = "Hello, Future!";
    char temp[100];

    // Print original message
    printf("Original message: %s\n", message);

    // Reverse the message
    int i, j;
    for(i = strlen(message) - 1, j = 0; i >= 0; i--, j++) {
        temp[j] = message[i];
    }
    temp[j] = '\0';

    // Print reversed message
    printf("Reversed message: %s\n", temp);

    // Count vowels in message
    int count = 0;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] == 'a' || message[i] == 'e' || message[i] == 'i' || message[i] == 'o' || message[i] == 'u' || message[i] == 'A' || message[i] == 'E' || message[i] == 'I' || message[i] == 'O' || message[i] == 'U') {
            count++;
        }
    }

    // Print number of vowels
    printf("Number of vowels: %d\n", count);

    // Remove whitespace from message
    int k = 0;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] != ' ') {
            message[k] = message[i];
            k++;
        }
    }
    message[k] = '\0';

    // Print message without whitespace
    printf("Message without whitespace: %s\n", message);

    return 0;
}