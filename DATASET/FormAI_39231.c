//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len, i, j;
    int flag = 1;

    printf("Please enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    j = len - 1;

    for(i = 0; i < len / 2; i++) {
        if(str[i] != str[j]) {
            flag = 0;
            break;
        }
        j--;
    }

    if(flag) {
        printf("%s is a palindrome.", str);
    } else {
        printf("%s is not a palindrome.", str);
    }

    return 0;
}