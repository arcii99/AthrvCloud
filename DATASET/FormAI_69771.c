//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

/* Function to translate given string from Alien Language to English */
void translateAlienToEnglish(char* alienLanguage) {
    char english[27] = "abcdefghijklmnopqrstuvwxyz"; 
    /* Assuming Alien Language does not have any special characters, digits or upper-case letters. 
    However, this can be extended/enhanced to support them as well */
    int len = strlen(alienLanguage);
    char translatedMessage[len];
    int i,j,k;
    for (i = 0; i<len; i++) {
        for (j = 0; j<26; j++) {
            if (alienLanguage[i] == english[j]) {
                translatedMessage[i] = english[25-j];
                /* Translate each character of the Alien Language */
            } 
        }
    }
    translatedMessage[len] = '\0';
    printf("Original message in Alien Language: %s\n", alienLanguage);
    printf("Translated message in English: %s\n", translatedMessage);
}

int main() {
    char alienLanguage[50];
    printf("Enter a message in Alien Language to be translated into English: ");
    scanf("%s", &alienLanguage);
    printf("\nTranslating...\n\n");
    translateAlienToEnglish(alienLanguage);
    printf("\nTranslation complete. Thank you for using our software.\n");
    return 0;
}