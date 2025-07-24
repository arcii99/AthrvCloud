//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define translation mappings for C Cat language
const char cat_to_english[][20] = {
    "meow", "int",
    "purr", "printf",
    "claw", "*",
    "whisker", "&",
    "fish", "float",
    "scratch", "++",
};

// Function to translate a single C Cat word to English
void translate_word(char *word)
{
    int i;
    for (i = 0; i < sizeof(cat_to_english) / sizeof(cat_to_english[0]); i++) {
        if (strcmp(word, cat_to_english[i]) == 0) {
            strcpy(word, cat_to_english[i + 1]);
            return;
        }
    }
}

// Function to convert a C Cat sentence to English
void translate_sentence(char *sentence)
{
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        translate_word(word);
        printf("%s ", word);
        word = strtok(NULL, " ");
    }
    printf("\n");
}

int main()
{
    char input[100];
    printf("Enter a sentence in C Cat language:\n");
    fgets(input, sizeof(input), stdin);
    translate_sentence(input);
    return 0;
}