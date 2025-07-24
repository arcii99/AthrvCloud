//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surprised
#include <stdio.h>
#include <string.h> 

int main() 
{
    char input[1000]; 
    printf("***PALINDROME CHECKER***\n"); 
    printf("Enter a word or a phrase: \n"); 
    fgets(input, 1000, stdin); 

    int len = strlen(input); 
    int start = 0; 
    int end = len - 1;

    printf("Checking if the input is a palindrome...\n"); 

    while(end > start) 
    {
        if(input[start] != input[end]) 
        {
            printf("Sorry, \"%s\" is not a palindrome.\n", input); 
            break; 
        }
        start++; 
        end--; 
    }

    if(end <= start) 
    {
        printf("Congratulations, \"%s\" is a palindrome!\n", input); 
    }

    return 0; 
}