//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
// Recursive C program to sanitize user input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Recursive function to sanitize each character in a string
void sanitize(char *s, int n)
{
    // base case
    if(n == 0) {
        return;
    }
    
    // iterate through the string
    sanitize(s, n - 1);
    // replace any non-alphanumeric character with a space
    if(!isalnum(s[n - 1])) {
        s[n - 1] = ' ';
    }
}

int main()
{
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // call recursively to sanitize input
    sanitize(str, strlen(str));

    printf("Sanitized string: %s", str);

    return 0;
}