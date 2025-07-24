//FormAI DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 1000

int main() {
    char input_string[1000];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int word_count[MAX_WORDS];
    int num_words = 0;

    printf("Enter a string: ");
    fgets(input_string, 1000, stdin);

    // remove newline character from input string
    input_string[strcspn(input_string, "\n")] = 0;

    // tokenize input string into individual words
    char *token = strtok(input_string, " ");
    while (token != NULL && num_words < MAX_WORDS) {
        strcpy(words[num_words], token);
        word_count[num_words] = 1;
        num_words++;
        token = strtok(NULL, " ");
    }

    // count occurrences of each word
    for (int i = 0; i < num_words; i++) {
        for (int j = i+1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_count[i]++;
                word_count[j] = 0;
            }
        }
    }

    // print word count results
    printf("Word\t\tCount\n");
    printf("=====================\n");
    for (int i = 0; i < num_words; i++) {
        if (word_count[i] > 0) {
            printf("%s\t\t%d\n", words[i], word_count[i]);
        }
    }

    return 0;
}