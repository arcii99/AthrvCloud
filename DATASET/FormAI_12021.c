//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>

// Function to translate Alien Language into English
void AlienLanguageTranslator(char *alienLang) {
    // ASCII values of A, E, I, O, U, Y
    int alpha[] = {65, 69, 73, 79, 85, 89};
    // Vowels to translate
    char vow[] = {'A', 'E', 'I', 'O', 'U', 'Y'};
    // Store the index of vowels to translate
    int ind[6], j = 0;
    
    // Find the index of vowels
    for(int i=0; alienLang[i]!='\0'; i++) {
        for(int k=0; k<6; k++) {
            if(alienLang[i] == vow[k]) {
                ind[j++] = i;
            }
        }
    }
    
    // Translate the vowels
    for(int i=0; i<j; i++) {
        alienLang[ind[i]] = alpha[i];
    }
    
    // Print the translated alien language
    printf("Translated Alien Language: %s", alienLang);
}

int main() {
    // Input Alien Language
    char alienLang[100];
    printf("Enter Alien Language: ");
    fgets(alienLang, 100, stdin);
    
    // Translate Alien Language
    AlienLanguageTranslator(alienLang);
    
    return 0;
}