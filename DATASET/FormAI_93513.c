//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    int count = 0, flag = 0;

    printf("Enter your text here:\n");
    fgets(input, 1000, stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'C' || input[i] == 'c') {
            count++;

            // Check if the next character is whitespace or punctuation
            if (isspace(input[i+1]) || ispunct(input[i+1])) {
                flag = 1;
            }
        }
    }

    printf("\n");
    printf("*************************\n");
    printf("The word count for 'c' is %d\n", count);
    
    if (flag) {
        printf("The word 'c' is followed by a whitespace or punctuation.\n");
    } else {
        printf("The word 'c' is not followed by a whitespace or punctuation.\n");
    }

    return 0;
}