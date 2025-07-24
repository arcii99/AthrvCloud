//FormAI DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>

int main()
{
    char originalString[50], newString[50];
    int i, j, length;

    // input original string
    printf("Enter a string: ");
    scanf("%s", originalString);

    // copy original string to new string in reverse order
    length = strlen(originalString);
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        newString[j] = originalString[i];
    }
    newString[j] = '\0';

    // print original string and new string
    printf("Original String: %s\n", originalString);
    printf("New String: %s\n", newString);

    // check if original string is palindrome or not
    if (strcmp(originalString, newString) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // count number of vowels in original string
    int vowelCount = 0;
    for (i = 0; i < length; i++) {
        if (originalString[i] == 'a' || originalString[i] == 'e' || originalString[i] == 'i' || originalString[i] == 'o' || originalString[i] == 'u' || originalString[i] == 'A' || originalString[i] == 'E' || originalString[i] == 'I' || originalString[i] == 'O' || originalString[i] == 'U') {
            vowelCount++;
        }
    }
    printf("Number of vowels in the string: %d\n", vowelCount);

    // convert original string to uppercase
    for (i = 0; i < length; i++) {
        if (originalString[i] >= 'a' && originalString[i] <= 'z') {
            originalString[i] = originalString[i] - 32;
        }
    }
    printf("Uppercase string: %s\n", originalString);

    return 0;
}