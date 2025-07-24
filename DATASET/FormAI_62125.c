//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

/* This program takes a message from the user and converts it to secret code by 
 * replacing every letter with the letter that comes two places later in the alphabet */
int main(void) {
    char message[MAX_LENGTH];
    int i;
    
    printf("Enter your message: ");
    fgets(message, MAX_LENGTH, stdin);
    
    /* Iterate through each character in the message */
    for (i = 0; i < strlen(message); i++) {
        /* If the character is a letter, replace it with the next letter in the alphabet */
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + 2) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + 2) % 26;
        }
    }
    
    printf("Your secret code is: %s", message);
    
    return 0;
}