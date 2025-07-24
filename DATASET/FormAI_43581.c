//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>

// Function to convert character to ASCII art
void charToArt(char c) {
    switch(c) {
        case 'A':
            printf("  /\\");
            printf("\n /__\\");
            printf("\n/    \\");
            printf("\n/____\\\n");
            break;
        case 'B':
            printf(" ____ ");
            printf("\n| __ )");
            printf("\n|  _ \\");
            printf("\n|____/");
            break;
        case 'C':
            printf("  ___");
            printf("\n / __|");
            printf("\n| (__");
            printf("\n \\___|\n");
            break;
        // Add more cases for each letter of the alphabet and some other characters
    }
}

int main() {
    // Ask user for input
    printf("Enter some text: ");
    char text[50];
    scanf("%s", text);
    
    // Loop through each character of the input and convert to ASCII art
    for(int i = 0; i < strlen(text); i++) {
        charToArt(text[i]);
    }
    
    return 0;
}