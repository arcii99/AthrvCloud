//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>

// Function to check if a string is palindrome
int isPalindrome(char str[]){
    int left = 0;
    int right = strlen(str) - 1;
    
    while(left < right){
        if(str[left] != str[right])
            return 0;
    
        left++;
        right--;
    }
    return 1;
}

int main(){
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);
    
    // check if string is palindrome or not
    if(isPalindrome(str))
        printf("The entered string is a palindrome.\n");
    else
        printf("The entered string is not a palindrome.\n");
    
    return 0;
}