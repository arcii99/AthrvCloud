//FormAI DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int word_count(const char *str);

int main() {
    char input_str[1000];

    printf("Enter a string: ");
    fgets(input_str, 1000, stdin);

    int count = word_count(input_str);

    printf("The number of words in the string: %d\n", count);

    return 0;
}

int word_count(const char *str) {
    int count = 0;
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        if(str[i] == ' ') {
            count++;
        }
    }

    return count+1; // The number of spaces is always 1 less than the number of words
}