//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

char *clean_input(const char *str) {
    char *clean_str = malloc(BUFFER_SIZE * sizeof(char));
    int i = 0, j = 0;

    while(str[i] != '\0') {
        if(isalpha(str[i]) || isdigit(str[i]) || isspace(str[i])) {
            clean_str[j++] = str[i++];
        } else {
            i++;
        }
    }

    clean_str[j] = '\0';
    return clean_str;
}

int main() {
    char *input = malloc(BUFFER_SIZE * sizeof(char));
    printf("Enter some string with special characters and punctuation marks: \n");
    fgets(input, BUFFER_SIZE, stdin);

    char *cleaned_input = clean_input(input);
    printf("Sanitized string: %s\n", cleaned_input);

    free(input);
    free(cleaned_input);
    return 0;
}