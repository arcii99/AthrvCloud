//FormAI DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <string.h>

int get_word_count(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            count++;
        }
    }

    return count + 1;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    printf("The word count of the sentence is %d\n", get_word_count(sentence));

    return 0;
}