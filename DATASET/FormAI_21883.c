//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *str) {
    int i, count = 0, len = strlen(str);

    for (i = 0; i < len; i++) {
        // Counting words till space, newline or end of string is reached
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
            count++;
    }

    return count;
}

int main() {
    char text[1000];

    printf("Enter the text to count words:\n");
    fgets(text, sizeof(text), stdin);

    int words_count = count_words(text);

    printf("Total number of words in given text = %d\n", words_count);

    return 0;
}