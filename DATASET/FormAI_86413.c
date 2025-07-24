//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i] != str[len-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    if(isPalindrome(str)){
        printf("%s is a palindrome.", str);
    }else{
        printf("%s is not a palindrome.", str);
    }
    return 0;
}