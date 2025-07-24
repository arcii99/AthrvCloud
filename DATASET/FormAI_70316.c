//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * This program takes a URL as an input and sanitizes it by
 * removing any characters that are not alphanumeric or
 * allowed in the URL. It then prints out the sanitized URL.
 */

int main() {

    char url[256];
    int i, len;
    char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.";

    /* Prompt the user for a URL */
    printf("Enter a URL: ");
    fgets(url, 256, stdin);

    /* Remove the newline character from the end of the input */
    len = strlen(url);
    if (url[len - 1] == '\n') {
        url[len - 1] = '\0';
    }

    /* Sanitize the URL */
    for (i = 0; i < strlen(url); i++) {
        if (!isalnum(url[i]) && !strchr(allowed_chars, url[i])) {
            url[i] = '\0';
            break;
        }
    }

    /* Print out the sanitized URL */
    printf("%s\n", url);

    return 0;
}