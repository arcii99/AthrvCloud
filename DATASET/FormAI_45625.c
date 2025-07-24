//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include <stdio.h>
#include <string.h>

// function to convert character to ASCII art pattern
void asciiArt(char c) {
    switch(c) {
        case 'A':
            printf("  /\\  \n /  \\ \n/    \\\n/------\\\n");
            break;
        case 'B':
            printf("------\n|  _  \\\n| |_)  |\n|  _  / \n------\n");
            break;
        case 'C':
            printf("  _____\n / ____|\n| |     \n| |____ \n \\_____|\n");
            break;
        // add more cases for other characters
        default:
            printf("Sorry, this character is not supported yet.\n");
    }
}

int main() {
    char message[100];
    int i;

    // get input message from user
    printf("Enter your message: ");
    fgets(message, 100, stdin);

    // iterate through every character in the message
    for(i = 0; i < strlen(message); i++) {
        asciiArt(message[i]);
    }

    return 0;
}