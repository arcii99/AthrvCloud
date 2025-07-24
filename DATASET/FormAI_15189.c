//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000], search[50];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a word to search: ");
    scanf("%s", search);

    // Splitting the sentence into tokens
    char *token = strtok(str, " ");

    while (token != NULL) {
        if (strcmp(token, search) == 0)
            count++;

        token = strtok(NULL, " ");
    }

    if (count > 0) {
        printf("'%s' was found %d times in the given string.\n", search, count);
    } else {
        printf("'%s' was not found in the given string.\n", search);
    }

    return 0;
}