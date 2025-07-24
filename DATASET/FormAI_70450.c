//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert char to ascii art
void charToAscii(char c) {
    switch(c) {
        case 'A': printf(" /\\  \n/  \\ \n/----\\\n/      \n"); break;
        case 'B': printf("----\\\n|___/ \n|___\\ \n|____/ \n"); break;
        case 'C': printf(" /----\n/      \n\\      \n \\----\n"); break;
        case 'D': printf("----\\ \n|___/ \n|    \\ \n|____/ \n"); break;
        case 'E': printf("-----\n|____ \n|____ \n|_____ \n"); break;
        case 'F': printf("-----\n|____ \n|____ \n|     \n"); break;
        case 'G': printf(" /----\n/  ___\n\\     \n \\----\\\n"); break;
        case 'H': printf("|    |\n|----|\n|    |\n|    |\n"); break;
        case 'I': printf(" _\n|\n|\n|_\n"); break;
        case 'J': printf("    _\n   |\n   |\n\\__/\n"); break;
        case 'K': printf("|\\   |\n| \\  |\n|   \\|\n|   /|\n"); break;
        case 'L': printf("|     \n|     \n|     \n|____ \n"); break;
        case 'M': printf("|\\  /|\n| \\/ |\n|    |\n|    |\n"); break;
        case 'N': printf("|\\   |\n| \\  |\n|  \\ |\n|   \\|\n"); break;
        case 'O': printf(" /\\  \n/  \\ \n\\  / \n \\/  \n"); break;
        case 'P': printf("----\\\n|___/ \n|     \n|     \n"); break;
        case 'Q': printf(" /\\  \n/  \\ \n\\_/'\\\n   __/\n"); break;
        case 'R': printf("----\\ \n|___/ \n|    \\\n|    |\n"); break;
        case 'S': printf(" ----\n/____ \n\\----\\\n____/ \n"); break;
        case 'T': printf("-----\n  |  \n  |  \n  |  \n"); break;
        case 'U': printf("|    |\n|    |\n\\    /\n \\__/\n"); break;
        case 'V': printf("|    |\n \\  / \n  \\/  \n      \n"); break;
        case 'W': printf("|    |\n| /\\ |\n|    |\n|    |\n"); break;
        case 'X': printf("\\   /\n \\/  \n /\\  \n/  \\ \n"); break;
        case 'Y': printf("\\   /\n \\ / \n  |  \n  |  \n"); break;
        case 'Z': printf(" ____\n   / \n  /  \n /___\n"); break;
        case ' ': printf("\n\n\n\n"); break;
        default: printf("Invalid character\n"); break;
    }
}

int main() {
    // get user input
    char input[100];
    printf("Enter a string to convert to ASCII art: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    // loop through each character and convert to ASCII art
    for(int i=0; i<strlen(input); i++) {
        charToAscii(input[i]);
    }

    return 0;
}