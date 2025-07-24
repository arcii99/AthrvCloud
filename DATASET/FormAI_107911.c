//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int len = strlen(input);
    int i = 0, j = len - 1;
    while (i < j) {
        if (input[i] != input[j]) {
            printf("%s is not a palindrome.\n", input);
            return 0;
        }
        i++;
        j--;
    }
    printf("%s is a palindrome.\n", input);
    return 0;
}