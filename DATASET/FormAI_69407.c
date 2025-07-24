//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to check if a given string is palindrome or not
int isPalindrome(char* str, int start, int end){
    // traverse the string from both ends to check for match
    while(start < end){
        // if characters don't match, return false
        if(str[start++] != str[end--])
            return 0;
    }
    // if all characters match, return true
    return 1;
}

int main(){
    char input[1000];

    printf("Enter a string: ");
    fgets(input, sizeof input, stdin);

    // remove trailing newline character if present
    input[strcspn(input, "\n")] = 0;

    // check if input is palindrome or not
    if(isPalindrome(input, 0, strlen(input)-1)){
        printf("%s is a palindrome\n", input);
    }else{
        printf("%s is not a palindrome\n", input);
    }

    return 0;
}