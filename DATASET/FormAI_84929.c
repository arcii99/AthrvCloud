//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    char phrase[100];
    printf("Enter a phrase to translate into Cat Language: ");
    scanf("%[^\n]", phrase); // read the entire line of text
    getchar(); // consume the newline character
    
    printf("Translation into Cat Language: ");
    
    // loop through each character in the string
    for (int i = 0; i < strlen(phrase); i++) {
        if (phrase[i] == ' ') {
            // print a meow for spaces
            printf("meow ");
        } else if (phrase[i] == 'e') {
            // replace e's with meows
            printf("meow");
        } else {
            // otherwise just print the character
            printf("%c", phrase[i]);
        }
    }
    
    printf("\n");
    return 0;
}