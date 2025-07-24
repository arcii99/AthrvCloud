//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[1000];
    int i, j, flag = 0;
    
    printf("Enter a string: ");
    fgets(input, 1000, stdin);
    
    // Removing all non-alphanumeric characters and converting to lowercase
    for(i = 0; i < strlen(input); i++) {
        if(isalnum(input[i])) {
            input[j++] = tolower(input[i]);
        }
    }
    input[j] = '\0';
    
    // Checking if the string is a palindrome
    for(i = 0, j = strlen(input) - 1; i < j; i++, j--) {
        if(input[i] != input[j]) {
            flag = 1;
            break;
        }
    }
    
    if(flag) {
        printf("%s is not a palindrome.\n", input);
    }
    else {
        printf("%s is a palindrome.\n", input);
    }
    
    return 0;
}