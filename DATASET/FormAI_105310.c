//FormAI DATASET v1.0 Category: String manipulation ; Style: Alan Touring
// Alan Turing style C String manipulation program

#include <stdio.h>
#include <string.h>

int main() {
    // Define the original string
    char str[] = "Hello World";
    printf("Original string: %s\n", str);

    // Append a string to the original string
    char str2[] = ", how are you?";
    strcat(str, str2);
    printf("Appended string: %s\n", str);

    // Copy a substring from the original string
    char substr[6];
    strncpy(substr, str + 6, 5);
    substr[5] = '\0';
    printf("Substring: %s\n", substr);

    // Convert the original string to all uppercase letters
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    printf("Uppercase string: %s\n", str);

    // Reverse the original string
    char temp;
    int j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("Reversed string: %s\n", str);

    return 0;
}