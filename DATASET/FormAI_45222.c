//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: rigorous
#include <stdio.h>
#include <string.h>

void printAsciiArt(char c);

int main() {
    char input[50];
    fgets(input, 50, stdin); // get user input
    
    int length = strlen(input);
    for(int i=0; i<length; i++) {
        printAsciiArt(input[i]);
    }
    return 0;
}

void printAsciiArt(char c) {
    switch(c) {
        case 'A':
            printf("  /\\  \n /  \\ \n/____\\\n");
            break;
        case 'B':
            printf(" ____  \n|___ \\ \n  __) |\n |___/ \n");
            break;
        case 'C':
            printf("  ____ \n / ___|\n| |    \n| |___ \n \\____|\n");
            break;
        // add more ascii art for other letters
        default:
            printf("   \n   \n %c \n   \n", c);
    }
}