//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Text to ASCII Art Generator!\n");
    printf("Enter the text to be converted: ");

    // Read user input
    char input[50];
    fgets(input, 50, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Generate ASCII art based on user input
    printf("\nYour ASCII art:\n");
    printf("------------------------------------------\n");

    int i;
    for(i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case 'A':
            case 'a':
                printf("  /\\ \n /  \\ \n/____\\\n");
                break;
            case 'B':
            case 'b':
                printf(" ____ \n| __ )\n|  _ \\\n|____/\n");
                break;
            case 'C':
            case 'c':
                printf("  ___ \n / __|\n| (__ \n \\___|\n");
                break;
            case 'D':
            case 'd':
                printf(" ____  \n|  _ \\ \n| |_) |\n|____/ \n");
                break;
            case 'E':
            case 'e':
                printf(" _____\n| ____|\n|  _|  \n|____| \n");
                break;
            case 'F':
            case 'f':
                printf(" _____\n| ____|\n|  _|  \n|_|    \n");
                break;
            // Add more cases for other letters and symbols
            default:
                printf("\nSorry, ASCII art is not available for this character.\n");
        }

        printf("------------------------------------------\n");
    }

    return 0;
}