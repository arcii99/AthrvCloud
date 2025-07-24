//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

/* Surrealist Palindrome Checker */

int main() {
    char input[100];
    printf("Welcome to the Surrealist Palindrome Checker!\n");
    printf("Please enter a word or phrase to check: ");
    scanf("%s", input);

    int length = strlen(input);
    int i, j;
    int flag = 0;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (input[i] == input[j]) {
            continue;
        } else {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Congratulations, %s is a surrealist palindrome!\n", input);
    } else {
        printf("Sorry, %s is not a surrealist palindrome.\n", input);
    }

    return 0;
}