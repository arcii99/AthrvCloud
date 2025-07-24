//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    int count = 0, i = 0;

    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // removes the trailing newline

    printf("Your input: %s\n", input);

    // Count the number of letters in the input string
    while (input[i]) {
        if (isalpha(input[i])) {
            count++;
        }
        i++;
    }

    if (count == 0) {
        printf("There are no letters in the input.\n");
    }
    else if (count == 1) {
        printf("There is only 1 letter in the input.\n");
    }
    else {
        printf("There are %d letters in the input.\n", count);
    }

    return 0;
}