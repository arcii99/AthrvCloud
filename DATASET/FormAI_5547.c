//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

int main() {

    char word[MAX_WORD_LEN];
    char sentence[MAX_WORDS];
    int i = 0, j = 0;
    int word_count = 0;

    printf("Enter a sentence:\n");
    fgets(sentence, MAX_WORDS, stdin);

    while(sentence[i] != '\0') {
        j = 0;

        while(isalpha(sentence[i])) {
            word[j] = sentence[i];
            i++;
            j++;
        }

        if(j > 0) {
            word[j] = '\0';
            word_count++;
            printf("Word Counting: %s\n", word);
        }

        i++;
    }

    printf("Total number of words: %d\n", word_count);

    return 0;
}