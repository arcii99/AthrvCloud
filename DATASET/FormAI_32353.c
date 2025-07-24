//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* A function to sanitize URLs */
void sanitize_url(char* url) {
    int i = 0;
    int j = 0;
    char* temp = url;
    
    /* loop through entire string */
    while (*temp) {
        /* check for forbidden characters */
        if (*temp == '<' || *temp == '>' || *temp == '\'' || *temp == '\"' || *temp == '(' || *temp == ')' || *temp == '{' || *temp == '}' || *temp == '[' || *temp == ']' || *temp == '\\' || *temp == ' ' || *temp == '\n' || *temp == '\r' || *temp == '\t' || *temp == '+' || *temp == '\"' || *temp == '#' || *temp == '%') {
            /* skip over forbidden characters */
            temp++;
        }
        else {
            /* copy valid character to new string */
            url[i++] = *temp++;
            /* check for consecutive slashes */
            if (url[i-1] == '/') {
                j++;
                if (j > 2) {
                    /* skip consecutive slashes */
                    i--;
                }
            }
            else {
                /* reset consecutive slash counter */
                j = 0;
            }
        }
    }
    /* add null terminating character to sanitized string */
    url[i] = '\0';
}

int main() {
    char url[500];
    /* prompt user to enter URL */
    printf("Enter your URL: ");
    fgets(url, sizeof(url), stdin);
    /* sanitize the URL */
    sanitize_url(url);
    /* display the sanitized URL */
    printf("Your sanitized URL is: %s", url);

    return 0;
}