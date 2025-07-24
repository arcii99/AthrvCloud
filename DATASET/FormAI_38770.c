//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to remove whitespace from a string */
void remove_whitespace(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

/* function to remove trailing slashes from a string */
void remove_trailing_slashes(char *str) {
    int i = strlen(str) - 1;
    while (str[i] == '/') {
        str[i] = '\0';
        i--;
    }
}

/* function to check if a character is valid in a URL */
int is_valid_char(char c) {
    return isalnum(c) || c == '.' || c == '-' || c == '_';
}

/* function to sanitize a URL */
void sanitize_url(char *url) {
    /* convert to lowercase */
    for (int i = 0; url[i]; i++) {
        url[i] = tolower(url[i]);
    }

    /* remove whitespace */
    remove_whitespace(url);

    /* remove trailing slashes */
    remove_trailing_slashes(url);

    /* remove invalid characters */
    int i = 0, j = 0;
    while (url[i]) {
        if (is_valid_char(url[i])) {
            url[j++] = url[i];
        }
        i++;
    }
    url[j] = '\0';
}

/* main function for testing */
int main() {
    char url[100] = "hTTpS://www.example.com/path/to/URL/?query=param";
    sanitize_url(url);
    printf("%s\n", url);
    return 0;
}