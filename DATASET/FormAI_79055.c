//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int i, j, flag = 1;

    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);

    for (i = 0, j = length-1; i < j; i++, j--) {
        if (input[i] != input[j]) {
            flag = 0;
            break;
        }
    }

    if (flag) printf("The string is a palindrome");
    else printf("The string is not a palindrome");

    return 0;
}