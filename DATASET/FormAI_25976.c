//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100];
    
    printf("Welcome to the Sherlock Holmes ASCII art generator!\n");
    printf("Please enter a word or phrase: ");
    fgets(input, sizeof(input), stdin);
    
    int length = strlen(input);
    int i, j;
    for (i = 0; i < length; i++) {
        char c = input[i];
        if (c == '\n') {
            continue;
        }
        
        for (j = 0; j < 10; j++) {
            if (j == 0) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("    _,...,_\n");
                }
            } else if (j == 1) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("  ,'       `.\n");
                }
            } else if (j == 2) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf(" /  __..--''\\\n");
                }
            } else if (j == 3) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("|/'/_ `'---._/|\n");
                }
            } else if (j == 4) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("|_/ |   .    `\\\n");
                }
            } else if (j == 5) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("    `\\  |\\     \\\n");
                }
            } else if (j == 6) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("      `\\'  \\    `\n");
                }
            } else if (j == 7) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("        `\\.'\n");
                }
            } else if (j == 8) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("          `\n");
                }
            } else if (j == 9) {
                if (c == ' ') {
                    printf("           ");
                } else {
                    printf("   \"%c\" in ASCII art form!\n", c);
                }
            }
        }
    }
    
    return 0;
}