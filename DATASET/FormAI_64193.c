//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
// ASCII Art Generator
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print(char *string) {
    int i;
    int len = strlen(string);

    for (i = 0; i < len; i++) {
        switch(string[i]) {
            case 'A':
                printf("  /\\  \n /  \\ \n/__\\_\\\n");
                break;
            case 'B':
                printf(" ____ \n| __ \\\n|  __/\n|____/\n");
                break;
            case 'C':
                printf("  ___ \n / __\\\n/ /   \\\n\\ \\___/\n \\____\\\n");
                break;
            // Add more cases for other letters
            default:
                printf("     \n     \n     \n");
                break;
        }
    }
}

int main() {
    char input[50];
    printf("Enter a string: ");
    fgets(input, 50, stdin);
    
    print(input);

    return 0;
}