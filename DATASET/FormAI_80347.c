//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include<stdio.h>
#include<string.h>
// function prototype for checking palindrome
int isPalindrome(char *s);

int main(){
    char str[100];
    printf("Enter a string: ");
    // input string
    scanf("%s", str);
    // check if string is palindrome
    if(isPalindrome(str))
        printf("\n%s is a palindrome!\n", str);
    else
        printf("\n%s is not a palindrome!\n", str);

    return 0;
}

int isPalindrome(char *s){
    int len = strlen(s);
    int i, j;
    for(i=0, j=len-1; i<len/2; i++, j--){
        // Compare characters from both ends
        if(s[i] != s[j]){
            printf("\nWait, what!? %s is not a palindrome!!\n", s);
            return 0;
        }
    }
    printf("\nWow! %s is a palindrome.\n", s);
    return 1;
}