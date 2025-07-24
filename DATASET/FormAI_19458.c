//FormAI DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, 1000, stdin);

    int count = 0;
    int length = strlen(input);

    for (int i = 0; i < length-1; i++) {
        if (input[i] == ' ') {
            count++;
        }
    }

    printf("The word count is: %d\n", count+1);

    return 0;
}