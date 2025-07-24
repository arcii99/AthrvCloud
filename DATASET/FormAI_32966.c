//FormAI DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h> 

// function to reverse a string
char* reverseString(char *str) { 
    int len = strlen(str); 

    for (int i = 0; i < len / 2; i++) { 
        char temp = str[i]; 
        str[i] = str[len - i - 1]; 
        str[len - i - 1] = temp; 
    } 

    return str; 
} 

// function to check if a string is a palindrome
int isPalindrome(char *str) { 
    int len = strlen(str); 

    for (int i = 0; i < len / 2; i++) { 
        if (str[i] != str[len - i - 1]) { 
            return 0; 
        } 
    } 

    return 1; 
} 

int main() { 
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input); 

    // reverse the string and print it 
    printf("Reversed string: %s\n", reverseString(input)); 

    // check if the string is a palindrome and print result
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0; 
}