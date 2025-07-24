//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert character to ASCII art
void charToArt(char c) {
    
    // switch statement to determine which character to print
    switch (c) {
        case 'A':
            printf("  /\\  \n");
            printf(" /  \\ \n");
            printf("/____\\\n");
            printf("|    |\n");
            printf("|    |\n");
            break;
        case 'B':
            printf("____  \n");
            printf("|__ \\ \n");
            printf("   ) |\n");
            printf("  / / \n");
            printf(" |____|\n");
            break;
        case 'C':
            printf("  ____\n");
            printf(" / ___|\n");
            printf("| |    \n");
            printf("| |___ \n");
            printf(" \\____|\n");
            break;
        case 'D':
            printf("____  \n");
            printf("|__ \\ \n");
            printf("   ) |\n");
            printf("  / / \n");
            printf(" |_|  \n");
            break;
        case 'E':
            printf("_____\n");
            printf("| ___ \n");
            printf("| |_/ /\n");
            printf("|    / \n");
            printf("|_|\\_\\\n");
            break;
        case 'F':
            printf("_____\n");
            printf("| ___ \n");
            printf("| |_/ /\n");
            printf("|  __/ \n");
            printf("|_|    \n");
            break;
        // add more cases for other characters
        default:
            printf("     \n");
            printf("     \n");
            printf("     \n");
            printf("     \n");
            printf("     \n");
    }
}

int main() {
    char message[100];

    // get input message from user
    printf("Enter message to convert to ASCII art: ");
    fgets(message, 100, stdin);

    // iterate through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        charToArt(message[i]);
    }

    return 0;
}