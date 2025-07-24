//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: accurate
#include<stdio.h>
#include<string.h>

// function to check if a character is alphanumeric
int isAlphanumeric(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}

int main() {
    char str[100];
    int i, j, flag = 1;

    printf("Enter a string: ");
    scanf("%[^\n]", str);  // reading a string with spaces

    // removing non-alphanumeric characters and converting to lower case
    char cleanStr[strlen(str)];
    int cleanIndex = 0;
    for(i=0; i<strlen(str); i++) {
        if(isAlphanumeric(str[i])) {
            if(str[i] >= 'A' && str[i] <= 'Z')
                cleanStr[cleanIndex++] = str[i] + 32;  // converting to lower case
            else
                cleanStr[cleanIndex++] = str[i];
        }
    }
    cleanStr[cleanIndex] = '\0';  // marking end of string

    // checking if clean string is palindrome or not
    for(i=0, j=strlen(cleanStr)-1; i<=j; i++, j--) {
        if(cleanStr[i] != cleanStr[j]) {
            flag = 0;
            break;
        }
    }

    // printing result based on the flag
    if(flag == 1)
        printf("The entered string is a palindrome.\n");
    else
        printf("The entered string is not a palindrome.\n");

    return 0;
}