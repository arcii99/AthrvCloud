//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: visionary
#include <stdio.h>
#include <string.h>

//Function to check if the given string is palindrome or not
int isPalindrome(char *str){
    
    int length = strlen(str);

    for(int i = 0; i < length/2; i++)
        if(str[i] != str[length - i - 1])
            return 0; //Not a palindrome
    
    return 1; //Palindrome
}

int main(){
    
    char str[100];
    printf("Enter a string to check if it's a palindrome : ");
    scanf("%s", str);

    //If the given string is a Palindrome
    if(isPalindrome(str)){
        printf("\nCongratulations! The string is a PALINDROME!\n\n");
        printf("     ^^     \n");
        printf("    ( o )    \n");
        printf("      |      \n");
        printf(" \\_______/  \n");
    }
    //If the given string is NOT a Palindrome
    else{
        printf("\nOops! The string is NOT a palindrome.\n\n");
        printf("   .-\"\"\"-.    \n");
        printf("  /       \\  \n");
        printf(" |   ERROR   | \n");
        printf("  \\       /  \n");
        printf("   '-...-'   \n");
    }

    return 0; 
}