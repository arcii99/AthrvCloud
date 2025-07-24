//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>

/* Function to reverse the given string */
void reverse(char *str)
{
    int length = strlen(str);

    /* Swap characters from the start and end of the string */
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main()
{
    printf("Enter a string: ");

    char str[100];
    fgets(str, sizeof(str), stdin);

    /* Remove newline character from the input */
    str[strcspn(str, "\n")] = 0;

    printf("Original string: %s\n", str);

    /* Reverse the input string */
    reverse(str);

    printf("Reversed string: %s\n", str);

    return 0;
}