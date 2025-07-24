//FormAI DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_word_count(char* str) {
    int count = 0;
    char *prev = str;
    char *curr = str;

    while (*curr != '\0') {
        if (*prev == ' ' && *curr != ' ') {
            count++;
        }
        prev = curr;
        curr++;
    }

    return count;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    int count = get_word_count(sentence);
    printf("The sentence contains %d words.", count);

    return 0;
}