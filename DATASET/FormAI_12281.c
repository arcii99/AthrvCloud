//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printChar(char c);

int main() {
    char input[50];

    printf("Enter a string: ");
    fgets(input, 50, stdin);

    // remove newline character at end of input
    input[strcspn(input, "\n")] = '\0';

    printf("\nOutput:\n\n");

    // loop through each character in string
    for(int i = 0; i < strlen(input); i++) {
        char currentChar = toupper(input[i]);

        // switch statement to determine ASCII art for each character
        switch(currentChar) {
            case 'A':
                printf("  /\\  \n /  \\ \n/____\\\n"); 
                break;
            case 'B':
                printf(" ____  \n|  _ \\ \n| |_) |\n|  __/ \n|_|    \n"); 
                break;
            case 'C':
                printf("  ___ \n / __|\n| (__ \n \\___|\n"); 
                break;
            case 'D':
                printf(" ____  \n|  _ \\ \n| | | |\n| |_| |\n|____/ \n"); 
                break;
            case 'E':
                printf(" _____ \n| ____|\n|  _|  \n| |___ \n|_____| \n"); 
                break;
            case 'F':
                printf(" _____ \n|  ___|\n| |_   \n|  _|  \n|_|    \n"); 
                break;
            case 'G':
                printf("  ___  \n / __| \n| (___ \n \\___ \\ \n|____/ \n"); 
                break;
            case 'H':
                printf(" _   _ \n| | | |\n| |_| |\n|  _  |\n|_| |_|"); 
                break;
            case 'I':
                printf(" ___ \n|_ _|\n | | \n|___|\n"); 
                break;
            case 'J':
                printf("     _ \n    | |\n _  | |\n| |_| |\n \\___/ \n"); 
                break;
            case 'K':
                printf(" _  __\n| |/ /\n| ' / \n| . \\ \n|_|\\_\\\n"); 
                break;
            case 'L':
                printf(" _     \n| |    \n| |    \n| |___ \n|_____| \n"); 
                break;
            case 'M':
                printf(" __  __ \n|  \\/  |\n| |\\/| |\n| |  | |\n|_|  |_| \n"); 
                break;
            case 'N':
                printf(" _   _ \n| \\ | |\n|  \\| |\n| |\\  |\n|_| \\_|\n"); 
                break;
            case 'O':
                printf("  ___  \n / _ \\ \n| | | |\n| |_| |\n \\___/ \n"); 
                break;
            case 'P':
                printf(" ____  \n|  _ \\ \n| |_) |\n|  __/ \n|_|    \n"); 
                break;
            case 'Q':
                printf("  ___  \n / _ \\ \n| | | |\n| |_| |\n \\__\\_\\\n"); 
                break;
            case 'R':
                printf(" ____  \n|  _ \\ \n| |_) |\n|  _ < \n|_| \\_\\\n"); 
                break;
            case 'S':
                printf(" ____  \n/ ___| \n\\___ \\ \n ___) |\n|____/ \n"); 
                break;
            case 'T':
                printf(" _____ \n|_   _|\n  | |  \n  | |  \n  |_|  \n"); 
                break;
            case 'U':
                printf(" _   _ \n| | | |\n| | | |\n| |_| |\n \\___/ \n"); 
                break;
            case 'V':
                printf("__      __\n\\ \\    / /\n \\ \\  / / \n  \\ \\/ /  \n   \\__/   \n"); 
                break;
            case 'W':
                printf("__        __\n\\ \\      / /\n \\ \\ /\\ / / \n  \\ V  V /  \n   \\_/\\_/   \n"); 
                break;
            case 'X':
                printf("\\ \\ / /\n \\ V / \n  > <  \n / . \\ \n/_/ \\_\\\n"); 
                break;
            case 'Y':
                printf("__   __\n\\ \\ / /\n \\ V / \n  | |  \n  |_|  \n"); 
                break;
            case 'Z':
                printf(" _____\n|__  /\n  / / \n / /_ \n/____|\n"); 
                break;
            default:
                printf("%c not supported.\n", currentChar);    
        }

        // add whitespace between characters
        printf("\n\n");
    }

    return 0;
}

// function to deal with extra whitespace in the ASCII art
void printChar(char c) {
    if(c == ' ') {
        printf(" ");
    } else if (c == '\n') {
        printf("\n");
    } else {
        printf("%c", c);
    }
}