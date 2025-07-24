//FormAI DATASET v1.0 Category: Word Count Tool ; Style: genious
#include <stdio.h>
#include <string.h>

int word_count(char str[]) {
    int i, count = 0;
    int len = strlen(str);

    // Loop through string character by character
    for (i = 0; i < len; i++) {
        // If a space or a new line character is found, increment count
        if (str[i] == ' ' || str[i] == '\n') {
            count++;
        }
    }

    // If the string ends with a word, increment count
    if (str[len - 1] != ' ' && str[len - 1] != '\n') {
        count++;
    }

    return count;
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    printf("Word count: %d\n", word_count(str));

    return 0;
}