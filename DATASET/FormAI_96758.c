//FormAI DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {

    char message[] = "Hello, World!";
    char name[] = "John";
    char greeting[50];

    // Concatenate two strings
    strcat(greeting, message);
    strcat(greeting, " My name is ");
    strcat(greeting, name);

    // Replace a character in a string
    char hello[] = "hello";
    hello[0] = 'H';

    // Find the length of a string
    int messageLength = strlen(message);

    // Copy a string
    char messageCopy[50];
    strcpy(messageCopy, message);

    // Convert all characters to uppercase
    char lowerName[] = "john";
    for(int i = 0; i < strlen(lowerName); i++) {
        lowerName[i] -= 32;
    }

    // Display the results
    printf("%s\n", greeting);
    printf("%s\n", hello);
    printf("%d\n", messageLength);
    printf("%s\n", messageCopy);
    printf("%s\n", lowerName);

    return 0;
}