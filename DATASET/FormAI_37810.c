//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <string.h>

void sanitize_url(char *url) {
    // blacklisted characters to be removed
    char blacklist[] = " !\"#$%&'()*+,./:;<=>?@[\\]^_`{|}~";
    int i, j, k, len;

    // get length of URL
    len = strlen(url);

    // loop through every character
    for (i = 0; i < len; i++) {
        // check if character is in blacklist
        for (j = 0; j < strlen(blacklist); j++) {
            if (url[i] == blacklist[j]) {
                // shift all remaining characters one position to the left
                for (k = i; k < len; k++) {
                    url[k] = url[k+1];
                }
                // decrement length since one character has been removed
                len--;
                // decrement index i since the next character has been shifted to the current position
                i--;
                break;
            }
        }
    }

    // if URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) && strncmp(url, "https://", 8)) {
        // prepend "http://" to the beginning of the URL
        char temp[7+len+1];
        strcpy(temp, "http://");
        strcpy(temp+7, url);
        strcpy(url, temp);
    }
}

int main() {
    // example URLs to sanitize
    char url1[] = "http://www.example.com/path//to//page.html";
    char url2[] = "https://www.example.com/path/to/page.html?query=value";
    char url3[] = "www.example.com/path/to/page.html#fragment";

    // sanitize URLs
    sanitize_url(url1);
    sanitize_url(url2);
    sanitize_url(url3);

    // output sanitized URLs
    printf("URL 1: %s\n", url1);
    printf("URL 2: %s\n", url2);
    printf("URL 3: %s\n", url3);

    return 0;
}