//FormAI DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

char str[100];
char pattern[100];
char insert[100];

int main() {
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter a pattern to search for: ");
    scanf("%s", pattern);
    printf("Enter characters to insert after pattern: ");
    scanf("%s", insert);

    int n = strlen(str);
    int m = strlen(pattern);

    char newstr[100];
    int i, j, k;

    for (i = 0, j = 0; i < n; i++) {
        // Check if pattern matches substring
        if (i + m <= n && strncmp(str + i, pattern, m) == 0) {
            // Copy everything up to the start of the pattern
            strncpy(newstr + j, str + i, m);
            j += m;

            // Insert new characters after the pattern
            strncpy(newstr + j, insert, strlen(insert));
            j += strlen(insert);

            // Skip over the pattern in the original string
            i += m - 1;
        } else {
            // Just copy the character as is
            newstr[j++] = str[i];
        }
    }

    newstr[j] = '\0';
    printf("Result: %s\n", newstr);

    return 0;
}