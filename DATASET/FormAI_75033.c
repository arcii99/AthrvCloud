//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str){
    int start = 0;
    int end = strlen(str) - 1;
    
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(){
    char input[100];
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", input);
    
    if(isPalindrome(input)){
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    
    return 0;
}