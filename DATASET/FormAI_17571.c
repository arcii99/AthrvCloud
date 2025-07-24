//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <string.h>

/*
 * This program converts a given string into ASCII art.
 */

int main() {
    char str[1000];
    printf("Enter your text: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);

    // Remove newline character from string
    if(str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }

    // Use ASCII codes to generate art
    printf("\n");
    for(int i = 0; i < len; i++) {
        switch(str[i]) {
            case 'A':
                printf("  /\\  \n /  \\ \n/____\\\n");
                break;
            case 'B':
                printf(" ____ \n|    \\\n|___  \n|___| \n");
                break;
            case 'C':
                printf("  ___ \n /   \\\n|     \n \\___/\n");
                break;
            // Add more cases for each letter
            case ' ':
                printf(" ");
                break;
            default:
                printf("   __ \n /    \\\n|  o  |\n \\___/\n");
                break;
        }
    }

    return 0;
}