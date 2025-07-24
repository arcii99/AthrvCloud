//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdbool.h> 

bool isPalindrome(char str[]) 
{ 
    int i = 0, j = strlen(str) - 1; 

    while (i < j) 
    { 
        if (str[i] != str[j]) 
            return false; 
        i++; 
        j--; 
    } 

    return true; 
} 

int main() 
{ 
    char str[100]; 
    bool result; 

    printf("Enter a string: "); 
    scanf("%s", str); 

    result = isPalindrome(str); 

    if (result) 
        printf("%s is a Palindrome", str); 
    else
        printf("%s is not a Palindrome", str); 

    return 0; 
}