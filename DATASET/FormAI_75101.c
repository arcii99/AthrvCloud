//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Function to check if character is part of the allowed URL characters */
bool is_allowed_char(char c) {
    if ((c >= 'a') && (c <= 'z'))
        return true;
    if ((c >= 'A') && (c <= 'Z'))
        return true;
    if ((c >= '0') && (c <= '9'))
        return true;
    if ((c == '-') || (c == '_') || (c == '.') || (c == '~'))
        return true;
    return false;
}

/* Function to sanitize the input URL */
void sanitize_url(char* url) {
    int len = strlen(url);
    int i, j;
    char* new_url = (char*)malloc((len+1)*sizeof(char));  // allocate memory for sanitized URL
    if (new_url == NULL) {  // check if memory allocation was successful
        printf("Error! Unable to allocate memory.\n");
        return;
    }
    j = 0;
    new_url[j] = '\0';
    for (i=0; i < len; i++) {
        if (is_allowed_char(url[i]))
            new_url[j++] = url[i];
        else if (url[i] == ' ')
            new_url[j++] = '+';
    }
    new_url[j] = '\0';
    strcpy(url, new_url);  // copy sanitized URL back to original URL
    free(new_url);  // free memory allocated for sanitized URL
}

/* Main function */
int main() {
    char url[500];
    printf("Enter URL to be sanitized:\n");
    fgets(url, 500, stdin);  // get URL input from user
    sanitize_url(url);  // sanitize URL
    printf("Sanitized URL: %s\n", url);
    return 0;
}