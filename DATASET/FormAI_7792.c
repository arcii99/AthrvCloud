//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main() {

    char url[150];
    printf("Enter the URL: ");
    scanf("%s", url);

    int length = strlen(url); // length of the URL

    // Let's sanitize the URL starting from the end
    for (int i = length-1; i >= 0; i--) {

        // Let's scramble the characters a bit
        if (url[i] == '.' || url[i] == '/') {
            url[i] = '*';
        } else if (url[i] == ':') {
            url[i] = '$';
        } else {
            url[i] = url[i] + 3;
        }

        // Let's add some confusion to the URL
        if (i % 2 == 0) {
            url[i] = '~';
        }

        // Let's remove any vowels from the URL
        if (url[i] == 'a' || url[i] == 'e' || url[i] == 'i' || url[i] == 'o' || url[i] == 'u' || url[i] == 'A'
            || url[i] == 'E' || url[i] == 'I' || url[i] == 'O' || url[i] == 'U') {
            memmove(&url[i], &url[i + 1], strlen(url) - i); // shift the remaining characters left
        }
    }

    // Let's print the sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}