//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

// Function to translate C Cat Language to English
char* c_cat_lang_translator(char* c_cat_lang_text) {
    char* c_cat_lang_words_array[100];
    int word_count = 0;
    int word_length = 0;

    // Loop through each character in the C Cat Language text
    for (int i = 0; i < strlen(c_cat_lang_text); i++) {
        char c = c_cat_lang_text[i];

        if (c == 'm') { // "meow" - indicates the start of a new word
            c_cat_lang_words_array[word_count] = malloc((word_length + 1) * sizeof(char));
            word_length = 0;
            word_count++;
        }
        else if (c == 'w') { // "purr" - indicates the end of a word
            word_length++;
        }
        else if (c == 'c') { // "hiss" - indicates a lowercase letter
            c_cat_lang_words_array[word_count - 1][word_length] = c + 32;
            word_length++;
        }
        else if (c == 'C') { // "HISS" - indicates an uppercase letter
            c_cat_lang_words_array[word_count - 1][word_length] = c + 32;
            word_length++;
        }
    }

    char* english_text = malloc(1000 * sizeof(char));

    // Loop through each word in the C Cat Language words array
    for (int i = 0; i < word_count; i++) {
        strcat(english_text, c_cat_lang_words_array[i]);
        strcat(english_text, " ");
    }

    // Free memory allocated for C Cat Language words array
    for (int i = 0; i < word_count; i++) {
        free(c_cat_lang_words_array[i]);
    }

    return english_text;
}

int main() {
    char* c_cat_lang_text = "meowcMeowCiMeowmiwMeowmiwMeowpurrmiwMeowmiw";
    char* english_text = c_cat_lang_translator(c_cat_lang_text);

    printf("C Cat Language: %s\n", c_cat_lang_text);
    printf("English: %s\n", english_text);

    free(english_text);

    return 0;
}