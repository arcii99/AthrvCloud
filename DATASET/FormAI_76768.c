//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#define ASCII_WIDTH 7

int main() {
    char input[100];
    printf("Enter text to convert to ASCII art: ");
    fgets(input, sizeof(input), stdin);
    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];
        if (ch == '\n') break;
        for (int j = 0; j < ASCII_WIDTH; j++) {
            switch (ch) {
                case 'A':
                    printf("  O  \n /   \\ \n/     \\n|     |\n");
                    break;
                case 'B':
                    printf("|-----\\\n|-------| \n|-------|\n|-----/\n");
                    break;
                case 'C':
                    printf("  ___\n /   \\\n|      \n \\___/\n");
                    break;
                case 'D':
                    printf("|-----\\\n|      \\\n|      /\n|-----/\n");
                    break;
                case 'E':
                    printf("|------\n|-------\n|-------\n|------\n");
                    break;
                //New characters can be added here as needed
                default:
                    printf("\n\n");
                    break;
            }
        }
    }
    return 0;
}