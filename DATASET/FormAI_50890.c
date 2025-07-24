//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[50];
    printf("Enter a string to check for palindrome: ");
    scanf("%s", str);
    int len = strlen(str);
    if (len == 0) {
        printf("Error: The string is empty.");
        return 0;
    }
    int i, j;
    char c;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        // Ignore non-alphabetic characters
        while (!isalpha(str[i]) && i < j) {
            i++;
        }
        while (!isalpha(str[j]) && i < j) {
            j--;
        }
        // Case-insensitive comparison
        if (tolower(str[i]) != tolower(str[j])) {
            printf("%s is not a palindrome.\n", str);
            return 0;
        }
    }
    printf("%s is a palindrome!\n", str);
    return 0;
}