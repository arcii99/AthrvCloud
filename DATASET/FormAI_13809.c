//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: imaginative
#include <stdio.h>
#include <string.h>

void sanitizeURL(char *url)
{   
    // Check if URL has "http://" or "https://" at the beginning
    char *http_start = strstr(url, "http://");
    char *https_start = strstr(url, "https://");
    
    // If 'http://' or 'https://' not present, add 'http://' to the beginning
    if (http_start == NULL && https_start == NULL) {
        char new_url[strlen(url) + 8];
        sprintf(new_url, "http://%s", url);
        strcpy(url, new_url);
    }
    
    // Check if URL has any illegal characters
    char illegal_chars[] = {"<>\\[]^`{|}"};
    char *illegal_char_start = strpbrk(url, illegal_chars);
    
    // If illegal character present, remove it and replace it with '_'
    if (illegal_char_start != NULL) {
        char new_url[strlen(url)];
        int index = illegal_char_start - url;
        sprintf(new_url, "%.*s_%s", index, url, illegal_char_start + 1);
        strcpy(url, new_url);
    }
    
    // Check if URL is too long
    if (strlen(url) >= 2083) {
        char new_url[2084];
        strncpy(new_url, url, 2083);
        new_url[2083] = '\0';
        strcpy(url, new_url);
    }
}

int main()
{
    char url[] = "www<[test]>website.com";
    printf("Before: %s\n", url);
    sanitizeURL(url);
    printf("After: %s", url);
    return 0;
}