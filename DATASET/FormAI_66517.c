//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

/*
Function to convert a character to its ASCII art representation
*/
void charToArt(char c) {
    switch(c) {
        case 'A':
            printf("   /\\   \n");
            printf("  /  \\  \n");
            printf(" /____\\ \n");
            printf("/      \\\n");
            printf("\n");
            break;
        case 'B':
            printf(" _____ \n");
            printf("|     \\\n");
            printf("|_____\n");
            printf("|     \\\n");
            printf("|_____\n");
            printf("\n");
            break;
        case 'C':
            printf("  ____ \n");
            printf(" /     \\\n");
            printf("/       \\\n");
            printf("\\       /\n");
            printf(" \\_____/\n");
            printf("\n");
            break;
        case 'D':
            printf(" _____ \n");
            printf("|     \\\n");
            printf("|     |\n");
            printf("|     /\n");
            printf("|____/\n");
            printf("\n");
            break;
        // add more cases for other characters as desired
        default:
            printf("\n");
            break;
    }
}

/*
Function to convert a string to its ASCII art representation
*/
void stringToArt(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        charToArt(str[i]);
    }
}

int main() {
    // usage example:
    char* str = "ABCD";
    stringToArt(str);
    return 0;
}