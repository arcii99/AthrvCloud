//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

/* Function to sanitize the URL and remove any whitespace at the end */
char* sanitize_url(char* url) {
    int len = strlen(url);
    while (len > 0 && isspace(url[len - 1])) {
        url[--len] = '\0';
    }
    return url;
}

/* Function to convert all alphabets to lowercase */
char* to_lowercase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
    return str;
}

/* Function to check if the URL is valid or not */
int is_valid_url(char* url) {
    /* List of valid URL schemes */
    char* valid_schemes[] = {"http", "https", "ftp", "ssh", "sftp", "telnet", "news"};

    /* List of valid URL characters */
    const char* valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-._~:/?#[]@!$&'()*+,;=";

    /* Check if the URL starts with a valid scheme */
    int i, valid_scheme = 0;
    for (i = 0; i < sizeof(valid_schemes) / sizeof(char*); i++) {
        if (strstr(url, valid_schemes[i]) == url) {
            valid_scheme = 1;
            break;
        }
    }
    if (!valid_scheme) {
        return 0;
    }

    /* Check if all characters in the URL are valid */
    for (i = 0; i < strlen(url); i++) {
        if (strchr(valid_chars, url[i]) == NULL) {
            return 0;
        }
    }
    return 1;
}

/* Main function to sanitize the URL entered by the user */
int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter the URL: ");
    fgets(url, sizeof(url), stdin);

    /* Sanitize the URL and convert to lowercase */
    char* sanitized_url = sanitize_url(url);
    char* lowercase_url = to_lowercase(sanitized_url);

    /* Check if the URL is valid */
    if (!is_valid_url(lowercase_url)) {
        printf("Invalid URL!\n");
        return 1;
    }

    printf("The sanitized URL is: %s\n", lowercase_url);
    return 0;
}