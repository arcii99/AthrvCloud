//FormAI DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Function to replace all occurrences of a substring in a string
void replaceAll(char *str, const char *old_str, const char *new_str) {
    char *pos;

    int old_len = strlen(old_str);
    int new_len = strlen(new_str);

    // Find and replace all occurrences of old_str with new_str
    while ((pos = strstr(str, old_str)) != NULL) {
        // Move the remaining characters to the right
        memmove(pos + new_len, pos + old_len, strlen(pos) - old_len + 1);
        // Copy new_str in place of old_str
        memcpy(pos, new_str, new_len);
    }
}

int main() {
    // Take input string
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Take substring and new substring to replace
    char old_str[100], new_str[100];
    printf("Enter substring to replace: ");
    fgets(old_str, sizeof(old_str), stdin);
    printf("Enter new substring: ");
    fgets(new_str, sizeof(new_str), stdin);

    // Remove newline character from inputs
    str[strcspn(str, "\n")] = '\0';
    old_str[strcspn(old_str, "\n")] = '\0';
    new_str[strcspn(new_str, "\n")] = '\0';

    // Call the replaceAll function
    replaceAll(str, old_str, new_str);

    // Print the replaced string
    printf("Replaced string: %s\n", str);

    return 0;
}