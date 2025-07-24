//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100

//Function to check if the given string is a palindrome or not
int palindrome_checker(char* str){
    int len=strlen(str);
    for(int i=0;i<=len/2;i++){
        if(str[i]!=str[len-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[MAX_SIZE];

    printf("Welcome! This is a C Palindrome Checker. \n");
    printf("Enter a string:\n");

    //Accepting input from user
    fgets(str,MAX_SIZE,stdin);

    //Replacing the newline character with null terminator
    str[strcspn(str,"\n")]=0;

    //Checking if string is empty
    if(strlen(str)==0){
        printf("Error! Input string is empty. Please try again.\n");
        return 0;
    }

    //Converting the string to lowercase for case-insensitive check
    for(int i=0;i<strlen(str);i++){
        str[i]=tolower(str[i]);
    }

    //Checking if the given string is a palindrome or not
    if(palindrome_checker(str)==1){
        printf("The given string '%s' is a palindrome.",str);
    }
    else{
        printf("The given string '%s' is not a palindrome.",str);
    }
    return 0;
}