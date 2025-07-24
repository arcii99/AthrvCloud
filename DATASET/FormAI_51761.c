//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>

// function that converts a character to ASCII art
void charToArt(char c) {
    switch(c) {
        case 'A':
            printf("  /\\  \n /  \\ \n/____\\\n");
            break;
        case 'B':
            printf(" ____ \n|_  /\n  |/\n ");
            break;
        case 'C':
            printf("  ___\n /   \\\n|     \n \\___/\n");
            break;
        // add more cases for each letter
        // ...
        default:
            printf("     \n     \n     \n");
    }
}

int main() {
    char input[100];
    int length;

    printf("Enter some text: ");
    scanf("%s", input);

    length = strlen(input);
    for(int i = 0; i < length; i++) {
        system("clear"); // clear console for a "shape-shifting" effect
        charToArt(input[i]);
    }
    
    return 0;
}