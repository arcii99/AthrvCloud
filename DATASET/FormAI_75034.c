//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
 
int isPalindrome(char str[]);
//function to check palindrome
 
int main(){
    char str[MAX];
    printf("Enter the string : ");
    fgets(str, MAX, stdin);
 
    if(isPalindrome(str)==0)
        printf("%s is a palindrome.", str);
    else
        printf("%s is not a palindrome.", str);
 
    return 0;
}
 
int isPalindrome(char str[]){
    int len = strlen(str) - 1;  // length of string
 
    for(int i = 0; i < len; i++,len--){
        if(str[i] != str[len])
            return 1;          // not a palindrome
    }
    return 0;              // palindrome
}