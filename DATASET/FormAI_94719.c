//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_language[] = "meow_purr_hiss_howl_meow_hiss_chirp";
    char translated_sentence[100] = "";
    char c_word[5] = "";

    for (int i = 0; i < strlen(c_cat_language); i++) {
        if (c_cat_language[i] == '_') {
            if (strcmp(c_word, "meow") == 0) {
                strcat(translated_sentence, "Hello ");
            } else if (strcmp(c_word, "purr") == 0) {
                strcat(translated_sentence, "I'm happy ");
            } else if (strcmp(c_word, "hiss") == 0) {
                strcat(translated_sentence, "I'm angry ");
            } else if (strcmp(c_word, "howl") == 0) {
                strcat(translated_sentence, "I'm sad ");
            } else if (strcmp(c_word, "chirp") == 0) {
                strcat(translated_sentence, "Goodbye ");
            }
            strcpy(c_word, "");
        } else {
            strncat(c_word, &c_cat_language[i], 1);
        }
    }
    printf("%s\n", translated_sentence);
    return 0;
}