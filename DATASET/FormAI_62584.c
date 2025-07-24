//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void checkPalindrome(char *str);

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    checkPalindrome(str);

    return 0;
}

void checkPalindrome(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for(i=0, j=length-1; i<j; i++, j--) {
        while(!isalnum(str[i]) && i<j) {
            i++;
        }
        while(!isalnum(str[j]) && i<j) {
            j--;
        }
        if(tolower(str[i]) != tolower(str[j])) {
            printf("%s is not a palindrome\n", str);
            return;
        }
    }
    printf("%s is a palindrome\n", str);
}