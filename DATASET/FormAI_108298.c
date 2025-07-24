//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>

// Function to translate English to C Cat Language
void catTranslator(char englishPhrase[]) {
    printf("C Cat Language Translation: ");
    
    for(int i = 0; englishPhrase[i] != '\0'; i++) {
        if(englishPhrase[i] == ' ') {
            printf(" meow");
        } else {
            printf(" purr");
        }
    }
    
    printf("\n");
}

int main() {
    char englishPhrase[100];
    printf("Enter a phrase to translate into C Cat language: ");
    scanf("%[^\n]%*c", englishPhrase);
    
    // Call the Translate function
    catTranslator(englishPhrase);
    
    return 0;
}