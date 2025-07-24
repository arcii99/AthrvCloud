//FormAI DATASET v1.0 Category: Word Count Tool ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main() {
    char string[1000];
    int count = 0, i;

    printf("Enter a string: ");
    fgets(string, 1000, stdin);

    for (i = 0; i < strlen(string); i++) {
        if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
            count++;
        }
    }

    printf("The number of words in the string is: %d\n", count + 1);

    return 0;
}