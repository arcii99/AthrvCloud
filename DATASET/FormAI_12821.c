//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main() {
    char str[100];
    int i, len, palindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i=0;i<len/2;i++) {
        if(tolower(str[i]) != tolower(str[len-i-1])) {
            palindrome = 0;
            break;
        }
    }

    if(palindrome)
        printf("%s is a palindrome.", str);
    else
        printf("%s is not a palindrome.", str);
}