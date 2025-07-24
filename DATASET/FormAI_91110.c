//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000

/* Function to replace a character in the given URL with the specified new character */
void replace_char(char *url, char old_char, char new_char) {
    int length = strlen(url);
    for(int i = 0; i < length; i++) {
        if(url[i] == old_char) {
            url[i] = new_char;
        }
    }
}

/* Function to remove all occurrences of the specified character in the given URL */
void remove_char(char *url, char remove_char) {
    int length = strlen(url);
    int j = 0;
    for(int i = 0; i < length; i++) {
        if(url[i] != remove_char) {
            url[j++] = url[i];
        }
    }
    url[j] = '\0';
}

/* Function to remove all occurrences of the specified character from the beginning of the given URL */
void remove_char_from_beginning(char *url, char remove_char) {
    int length = strlen(url);
    int i = 0;
    while(i < length && url[i] == remove_char) {
        i++;
    }
    if(i > 0) {
        memmove(url, url+i, length-i+1);
    }
}

/* Function to remove all occurrences of the specified character from the end of the given URL */
void remove_char_from_end(char *url, char remove_char) {
    int length = strlen(url);
    int i = length-1;
    while(i >= 0 && url[i] == remove_char) {
        i--;
    }
    url[i+1] = '\0';
}

/* Function to sanitize the given URL */
void sanitize_url(char *url) {
    // remove all new line characters
    replace_char(url, '\n', ' ');

    // remove leading and trailing spaces
    remove_char_from_beginning(url, ' ');
    remove_char_from_end(url, ' ');

    // remove any single quotes or double quotes
    remove_char(url, '\'');
    remove_char(url, '\"');

    // remove any backslashes
    remove_char(url, '\\');
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // sanitize the URL
    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);
    return 0;
}