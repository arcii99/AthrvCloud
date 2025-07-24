//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

/*
 * This program is a C Cat Language Translator
 * Written by a chatbot
 */

int main() {

    char phrase[100], translated_phrase[1000];

    printf("Enter a phrase in C Cat Language: ");
    scanf("%[^\n]%*c", phrase);

    // Check if phrase contains any of the following words:
    if (strstr(phrase, "meow") != NULL || strstr(phrase, "meows") != NULL || strstr(phrase, "meowing") != NULL) {
        // Translate to English
        strcpy(translated_phrase, "I");
        if (strstr(phrase, "meows") != NULL) {
            strcat(translated_phrase, " am");
        }
        strcat(translated_phrase, " meowing");
        if (strstr(phrase, "at") != NULL) {
            strcat(translated_phrase, " at");
        }
        if (strstr(phrase, "you") != NULL) {
            strcat(translated_phrase, " you");
        }
        strcat(translated_phrase, ".");
    } else {
        // Translate to C Cat Language
        strcpy(translated_phrase, "meow");
        if (strstr(phrase, "am") != NULL) {
            strcat(translated_phrase, "s");
        }
        strcat(translated_phrase, " meowing");
        if (strstr(phrase, "at") != NULL) {
            strcat(translated_phrase, "at");
        }
        if (strstr(phrase, "you") != NULL) {
            strcat(translated_phrase, " you");
        }
        strcat(translated_phrase, ".");
    }

    printf("%s", translated_phrase);

    return 0;
}