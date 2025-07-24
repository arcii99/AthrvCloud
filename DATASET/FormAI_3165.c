//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to sanitize a URL */
void sanitize(char *url) {
    char *p1 = url, *p2 = url;
    while (*p1) {
        /* Convert alphabetic characters to lowercase */
        if (isalpha(*p1))
            *p2++ = tolower(*p1);
        /* Remove characters that are not alphanumeric, _, -, or . */
        else if (isalnum(*p1) || *p1 == '_' || *p1 == '-' || *p1 == '.')
            *p2++ = *p1;
        /* Replace spaces with dashes */
        else if (*p1 == ' ')
            *p2++ = '-';
        p1++;
    }
    *p2 = '\0';
}

/* Main function to run the program */
int main() {
    char url[100];
    printf("Enter a URL: ");
    fgets(url, 100, stdin);
    /* Remove newline character from input */
    url[strcspn(url, "\n")] = '\0';
    printf("Original URL: %s\n", url);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}