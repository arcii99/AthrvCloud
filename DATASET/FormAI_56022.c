//FormAI DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void remove_punctuation(char *str) {
    // Remove all punctuation characters from the given string
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (ispunct(str[i])) {
            for (int j = i; j < len - 1; j++) {
                str[j] = str[j+1];
            }
            str[len-1] = '\0';
            len--;
            i--;
        }
    }
}

int count_words(char *str) {
    // Count the number of words in the given string
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isspace(str[i]) && !isspace(str[i+1])) {
            count++;
        }
    }
    if (len > 0 && !isspace(str[len-1])) {
        count++;
    }
    return count;
}

int main() {
    char input[1000];

    // Read input from the user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove punctuation from the input string
    remove_punctuation(input);

    // Count the number of words in the input string
    int num_words = count_words(input);

    // Print the results
    printf("Input string with punctuation removed: %s\n", input);
    printf("Number of words in the input string: %d\n", num_words);

    return 0;
}