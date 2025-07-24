//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>

int main(void) {

    char str[100], temp;
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf("%s",str);

    j = strlen(str) - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            printf("The string is NOT a palindrome.\n");
            return 0;
        }
        i++; 
        j--;
    }
    printf("The string is a palindrome.\n");
    return 0;
}