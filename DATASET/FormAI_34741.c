//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void remove_special_chars(char *str);
int is_palindrome(const char *str);

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    remove_special_chars(str); 
    
    if(is_palindrome(str))
        printf("The string is a palindrome.\n");
    else 
        printf("The string is not a palindrome.\n");
        
    return 0;
}

// Removes any special characters and spaces from the string
void remove_special_chars(char *str) {
    int i = 0, j = 0;
    while(str[i]) {
        if(isalpha(str[i]))
            str[j++] = tolower(str[i]);
        i++;
    }
    str[j] = '\0';
}

// Checks if the given string is a palindrome
int is_palindrome(const char *str) {
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        if(str[i] != str[len-i-1])
            return 0;
    }
    return 1;
}