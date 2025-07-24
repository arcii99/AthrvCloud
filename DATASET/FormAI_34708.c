//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_language[1000], translated_text[1000], word[100] = "", current_char;
    int i, j = 0;
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter the text you wish to translate: ");
    fgets(c_cat_language, sizeof(c_cat_language), stdin);
    c_cat_language[strcspn(c_cat_language, "\n")] = 0; // Remove newline character from input
    
    printf("\nTranslating...\n");

    for (i = 0; i < strlen(c_cat_language); i++) {
        current_char = c_cat_language[i];
        if (current_char == ' ') {
            strcat(translated_text, word);
            strcat(translated_text, " meow ");
            memset(word, 0, sizeof(word));
            j = 0;
        }
        else {
            word[j] = current_char;
            j++;
        }
    }
    
    strcat(translated_text, word); // Add the final word to the translation
    
    printf("\nTranslation: %s\n", translated_text);
    printf("\nThank you for using the C Cat Language Translator!");
    
    return 0;
}