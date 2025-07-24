//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int word_count = 0, i;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    for (i = 0; i<strlen(sentence); i++) {
        if (sentence[i] == ' ') { //if current character is a space
            word_count++; //increase word count
        }
    }

    //add 1 to word count for last word (not followed by a space)
    word_count++;

    printf("Word count: %d", word_count);

    return 0;
}