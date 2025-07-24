//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// function to convert character to ASCII art
void charToAscii(char c) {
    int asciiVal = (int) c;
    switch (asciiVal) {
        case 65 ... 90:     // uppercase letters
            printf("                          ___ \n");
            printf(" |\\   | |   | |\\   | |  \\ \n");
            printf(" | \\  | |   | | \\  | |   | \n");
            printf(" |  \\ | |   | |  \\ | |   | \n");
            printf(" |   \\| |___| |   \\| |__/ \n");
            break;
        case 97 ... 122:    // lowercase letters
            printf("                          ___ \n");
            printf(" |\\   | |   | |\\   | |  \\ \n");
            printf(" | \\  | |   | | \\  | |   | \n");
            printf(" |  \\ | |   | |  \\ | |   | \n");
            printf(" |   \\| |___| |   \\| |___\\ \n");
            break;
        case 48 ... 57:     // numbers
            printf("      _______ _     _  _______ \n");
            printf("     |__   __| |   | |/ /  __ \\ \n");
            printf("        | |  | |   | ' /| |__) |\n");
            printf("        | |  | |   |  < |  ___/ \n");
            printf("        | |  | |___| . \| |  \n");
            printf("        |_|  |_____|_|\_\\_|  \n");
            break;
        default:        // non-alphanumeric characters
            printf("  __ _  ___   ___   ___  ___ _ __ \n");
            printf(" / _` |/ _ \\ / _ \\ / __|/ _ \\ '__|\n");
            printf("| (_| | (_) | (_) | (__|  __/ |   \n");
            printf(" \\__, |\\___/ \\___/ \\___|\\___|_|  \n");
            printf(" |___/                           \n");
            break;
    }
}

// main function
int main() {
    char input[MAX_LENGTH];
    int i, len;

    printf("Enter a string (maximum %d characters):\n", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';    // replace newline with null terminator
    len = strlen(input);
    
    printf("\n");

    for (i = 0; i < len; i++) {
        charToAscii(input[i]);
        printf("\n");
    }

    printf("\n");

    return 0;
}