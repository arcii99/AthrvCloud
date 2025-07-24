//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000], word[100], new_sentence[1000] = "";
    int i, j, found = 0;
    char cat_words[][2][20] = {{"meow", "hello"}, {"purr", "goodbye"}, {"hiss", "no"}, {"scratch", "yes"}, {"nap", "sleep"}};
    int num_cat_words = 5;

    printf("Enter a sentence in cat language: ");
    fgets(sentence, 1000, stdin);

    i = 0;
    while (sentence[i] != '\0') {
        j = 0;
        while (sentence[i] != ' ' && sentence[i] != '\n' && sentence[i] != '\0') {
            word[j] = sentence[i];
            i++;
            j++;
        }
        word[j] = '\0';

        found = 0;
        for (j = 0; j < num_cat_words; j++) {
            if (strcmp(word, cat_words[j][0]) == 0) {
                strcat(new_sentence, cat_words[j][1]);
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(new_sentence, word);
        }
        if (sentence[i] == ' ') {
            strcat(new_sentence, " ");
            i++;
        }
    }

    printf("The sentence in human language is: %s", new_sentence);

    return 0;
}