//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, len;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    for (i=0, j=len-1; i<len/2; i++, j--) {
        if (str[i] != str[j]) {
            printf("Not a palindrome.\n");
            return 0;
        }
    }
    printf("Yes, '%s' is a palindrome!\n", str);
    return 0;
}