//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str);

int main() {
    char input_string[100];
    printf("Enter a string to check if it is a palindrome: ");
    fgets(input_string, 100, stdin);

    // Convert input string to lower case
    for(int i = 0; i < strlen(input_string); i++) {
        input_string[i] = tolower(input_string[i]);
    }

    if(is_palindrome(input_string)) {
        printf("%s is a palindrome.", input_string);
    } else {
        printf("%s is not a palindrome.", input_string);
    }

    return 0;
}

/*
 * Function to check if a string is a palindrome
 */
int is_palindrome(char *str) {
    int i = 0, j = strlen(str)-1;

    while(i < j) {
        // Skip non-alphanumeric characters
        while(!isalnum(str[i])) {
            i++;
        }
        while(!isalnum(str[j])) {
            j--;
        }

        if(i < j && tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}