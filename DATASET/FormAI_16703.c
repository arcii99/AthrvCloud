//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

void reverse(char *str, int len) {
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    printf("Welcome to the Palindrome Checker!\n");

    while (1) {
        printf("Enter a string (press 'q' to quit): ");
        char input[100];
        fgets(input, 100, stdin);
        if (input[0] == 'q' && strlen(input) == 2) { // 'q' + '\n'
            printf("Goodbye!\n");
            break;
        }

        int len = strlen(input) - 1; // remove '\n'
        char copy[100];
        strcpy(copy, input);
        reverse(copy, len);

        if (strcmp(input, copy) == 0) {
            printf("Hooray, it's a palindrome!\n");
        } else {
            printf("Sorry, it's not a palindrome.\n");
        }
    }

    return 0;
}