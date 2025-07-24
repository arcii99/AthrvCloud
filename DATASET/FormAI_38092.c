//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 1000

void recursiveSanitize(char url[], int len, int i)
{
    // Base case
    if (i >= len) {
        return;
    }

    // If the current character is a '<' or '>' or a null terminator
    if (url[i] == '<' || url[i] == '>' || url[i] == '\0') {
        url[i] = '\0';
        return;
    }

    // If the current character is a space or a tab, jump to the next character
    if (url[i] == ' ' || url[i] == '\t') {
        recursiveSanitize(url, len, i + 1);
        return;
    }

    // If the current character is a backslash
    if (url[i] == '\\') {
        // If the escape character is followed by a double quote
        if (url[i + 1] == '\"') {
            // Replace the escape character with a double quote
            url[i] = '\"';
            // Shift the remaining characters to the left by one
            for (int j = i + 1; j < len; j++) {
                url[j] = url[j + 1];
            }
            len--;
            // Continue recursion
            recursiveSanitize(url, len, i);
        }
        // If the escape character is followed by a single quote
        else if (url[i + 1] == '\'') {
            // Replace the escape character with a single quote
            url[i] = '\'';
            // Shift the remaining characters to the left by one
            for (int j = i + 1; j < len; j++) {
                url[j] = url[j + 1];
            }
            len--;
            // Continue recursion
            recursiveSanitize(url, len, i);
        }
        else {
            // Otherwise, skip the escape character and continue recursion
            recursiveSanitize(url, len, i + 1);
        }
    }
    else {
        // Otherwise, continue recursion
        recursiveSanitize(url, len, i + 1);
    }
}

int main() {
    char url[MAX_URL_LENGTH] = "http://example.com/test.php?name=<>\"'&surname=Jones\\'s";

    printf("Before sanitizing:\n%s\n", url);

    recursiveSanitize(url, strlen(url), 0);

    printf("After sanitizing:\n%s\n", url);

    return 0;
}