//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: cheerful
//Welcome to my Palindrome Checker!

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char word[20];
    bool isPalindrome = true;

    printf("Hello there! Let's check if a word is a Palindrome or not.\n");
    printf("Enter a word (minimum 2 letters) : ");
    scanf("%s", word);

    int len = strlen(word);
    for (int i = 0; i < len/2; i++) {
        if (word[i] != word[len-i-1]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) {
        printf("Hooray! \"%s\" is a Palindrome!!\n", word);
    }
    else {
        printf("Oops! \"%s\" is not a Palindrome.\n", word);
    }
    printf("Thanks for using my program! Have a great day :)");
    return 0;
}