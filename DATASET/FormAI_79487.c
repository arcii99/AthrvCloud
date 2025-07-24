//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include<stdio.h>
#include<string.h>

int checkPalindrome(char*);

int main(){
    char string[100];

    printf("Enter a string:\n");
    gets(string);

    // check if it is palindrome
    if(checkPalindrome(string)){
        printf("The entered string is a palindrome");
    }
    else{
        printf("The entered string is not a palindrome");
    }

    return 0;
}

// function to check if the string is palindrome or not
int checkPalindrome(char* string){
    int length = strlen(string);
    int i, j;

    // loop through the string and compare characters from start and end
    for(i=0, j=length-1; i<j; i++, j--){
        if(string[i] != string[j]){
            return 0;
        }
    }
    return 1;
}