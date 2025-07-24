//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Convert character to ASCII art
void asciiart(char ch) {
    switch(ch) {
        case 'A':
        case 'a':
            printf("  /\\ \n");
            printf(" /  \\ \n");
            printf("/    \\ \n");
            printf("|____|\n");
            break;
        case 'B':
        case 'b':
            printf(" ____\n");
            printf("| __ \\\n");
            printf("| ||_/  >\n");
            printf("|___. /\n");
            printf("    \\/\n");
            break;
        case 'C':
        case 'c':
            printf("  ___ \n");
            printf(" / __\\\n");
            printf("| |___\n");
            printf(" \\____/\n");
            break;
        case 'D':
        case 'd':
            printf(" ____ \n");
            printf("|    \\\n");
            printf("| |   |\n");
            printf("| |___|\n");
            printf("|_____/\n");
            break;
        default:
            printf("     \n");
            printf("     \n");
            printf("     \n");
            printf("     \n");
            break;
    }
}

// Convert string to ASCII art
void convert_ascii(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < MAX_LENGTH; i++) {
        for(int j = 0; j < len; j++) {
            asciiart(str[j]);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to convert to ASCII art: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("\nASCII Art Output:\n");
    convert_ascii(input);
    
    return 0;
}