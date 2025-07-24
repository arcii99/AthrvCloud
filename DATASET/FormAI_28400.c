//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str);

int main() 
{   
    char str[50];
    
    printf("Enter a string: ");
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';  // Removing the trailing newline character
    
    if (is_palindrome(str))
        printf("%s is a palindrome\n", str);
    else 
        printf("%s is not a palindrome\n", str);
    
    return 0;
}

int is_palindrome(char *str)
{
    int i, j;
    int len = strlen(str);
    char *clean_str = (char*) malloc((len+1) * sizeof(char));  // Allocating memory to store cleaned string
    
    for (i=0, j=0; i<len; i++) {  // Looping through string and removing non-alphanumeric characters
        if (isalnum(str[i])) {
            clean_str[j] = tolower(str[i]);  // Ignoring case
            j++;
        }
    }
    clean_str[j] = '\0';  // Adding null character to end of string
    
    len = strlen(clean_str);
    for (i=0, j=len-1; i<len/2; i++, j--) {  // Looping through half of string to check for palindrome
        if (clean_str[i] != clean_str[j]) {
            free(clean_str);  // Freeing memory before exit
            return 0;  // Not a palindrome
        }
    }
    free(clean_str);  // Freeing memory
    return 1;  // Palindrome
}