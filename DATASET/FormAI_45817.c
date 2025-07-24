//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>

int main() {
    char text[100];
    printf("Enter text: ");
    fgets(text, 100, stdin);

    printf("\nASCII art:\n");

    for(int i = 0; text[i] != '\0'; i++) {
        switch(text[i]) {
            case 'A':
            case 'a':
                printf("  /\\  \n /__\\ \n/    \\\n");
                break;
            case 'B':
            case 'b':
                printf(" ____ \n|___ \\\n __) |\n|____/\n");
                break;
            case 'C':
            case 'c':
                printf("  ___ \n / __|\n| (__ \n \\___|\n");
                break;
            case 'D':
            case 'd':
                printf(" ____ \n|  _ \\\n| | | |\n|_| |_|\n");
                break;
            case 'E':
            case 'e':
                printf(" _____\n| ____|\n|  _|  \n|_____\n");
                break;
            // add more cases for other letters
            default:
                printf("\n"); // for any character not in the list above
        }
    }

    return 0;
}