//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int isPalindrome(char *str);

int main()
{
    char str[MAX_LENGTH];
    printf("Hello there! I'm the Curious Palindrome Checker Bot.\n");
    printf("Please enter a word or a sentence without spaces (less than or equal to %d characters):\n", MAX_LENGTH-1);
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0; //removing the trailing newline character

    if(isPalindrome(str)){
        printf("Wow, '%s' is a palindrome!\n", str);
    }
    else{
        printf("Hmm, '%s' is not a palindrome :(\n", str);
    }

    printf("Thanks for using the Curious Palindrome Checker Bot. Have a nice day!\n");
    return 0;
}

int isPalindrome(char *str){
    int len = strlen(str);
    char *revStr = malloc(sizeof(char) * (len+1)); //allocating memory for reversed string

    for(int i=0; i<len; i++){
        revStr[i] = str[len-i-1]; //reversing the string
    }
    revStr[len] = '\0';

    for(int i=0; i<len; i++){
        if(str[i] != revStr[i]){
            free(revStr); //freeing the allocated memory
            return 0; //not a palindrome
        }
    }
    free(revStr); //freeing the allocated memory
    return 1; //palindrome
}