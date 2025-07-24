//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    char *substr;
    int pos, len, i, j;

    // Get the user input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = 0;

    // Get the position and length of the substring to be removed
    printf("Enter the position of the substring to remove: ");
    scanf("%d", &pos);

    printf("Enter the length of the substring to remove: ");
    scanf("%d", &len);

    // Allocate memory for the substring
    substr = (char*) malloc(len + 1);

    // Copy the substring
    for (i = pos - 1, j = 0; i < pos + len - 1; i++, j++)
    {
        substr[j] = str[i];
    }

    substr[j] = '\0';

    // Remove the substring from the string
    memmove(str + pos - 1, str + pos + len - 1, strlen(str) - pos - len + 2);

    // Print the modified string
    printf("Modified string: %s\n", str);

    // Free the allocated memory
    free(substr);

    return 0;
}