//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

int main()
{
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a string to check if it is a palindrome: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin); // reading input string

    int length = strlen(input_string) - 1; // -1 to remove trailing newline
    int start = 0;
    int end = length - 1;

    while (end > start) {
      if (tolower(input_string[start++]) != tolower(input_string[end--])) {
        printf("'%s' is not a palindrome\n", input_string);
        return 0;
      }
    }

    printf("'%s' is a palindrome\n", input_string);
    return 0;
}