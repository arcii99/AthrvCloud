//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    printf("Enter a sentence: ");
    char sentence[100];
    fgets(sentence, 100, stdin);
    printf("\nASCII ART:\n\n");
    
    for (int i = 0; i < strlen(sentence); i++) {
        switch(sentence[i]) {
            case 'A':
                printf("  /\\ \n /  \\ \n/__\\ \n");
                break;
            case 'B':
                printf(" |¯¯\\ \n |__/ \n |¯¯\\ \n |__/ \n |¯¯\\ \n |__/ \n");
                break;
            // continue with all letters of the alphabet
                
            default: 
                printf("\n");
        }
    }
    return 0;
}