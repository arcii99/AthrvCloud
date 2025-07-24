//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, i, j, flag = 0;

    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0, j = len - 1; i < len/2; i++, j--) {
        if (str[i] != str[j]) {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        printf("%s is not a palindrome\n", str);
    else
        printf("%s is a palindrome\n", str);

    return 0;
}