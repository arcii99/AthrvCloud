//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

const char *cat_dictionary[] = {
    "meow", "hello",
    "purr", "thank you",
    "hiss", "go away"
};

int main() {
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter a sentence in Cat Language:\n");

    char sentence[256];
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    printf("Translation: ");

    char* word = strtok(sentence, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < sizeof(cat_dictionary)/sizeof(const char*); i += 2) {
            if (strcmp(word, cat_dictionary[i]) == 0) {
                printf("%s ", cat_dictionary[i+1]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}