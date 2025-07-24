//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void checkPalindrome(char *str);

int main(){
    char str[MAX];

    printf("Enter a word or phrase: ");
    fgets(str, sizeof(str), stdin);
    checkPalindrome(str);

    return 0;
}

void checkPalindrome(char *str){
    int len = strlen(str) - 1;
    int i,j;

    char temp[MAX];
    for(i = 0, j = 0; i < len; i++){
        if(isalpha(str[i])){
            temp[j++] = tolower(str[i]);
        }
    }
    temp[j] = '\0';
    
    char reverse[MAX];
    for(i = 0; i < j; i++){
        reverse[i] = temp[j-i-1];
    }
    reverse[j] = '\0';

    if(strcmp(temp, reverse) == 0){
        printf("\n%s is a palindrome\n", str);
    } else{
        printf("\n%s is not a palindrome\n", str);
    }
}