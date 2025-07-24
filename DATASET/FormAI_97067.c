//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

int main(void) {
    char str[MAX_STR_LEN];
    char c;
    int count = 0;

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    printf("Enter a character to count: ");
    c = getchar();

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }

    printf("The character %c appears %d times in the string.\n", c, count);

    return EXIT_SUCCESS;
}