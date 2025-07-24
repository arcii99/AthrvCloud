//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    int flag = 1;

    // Check if the string is a palindrome
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}