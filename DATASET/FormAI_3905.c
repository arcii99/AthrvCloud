//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    This program sanitizes a URL to make sure it is properly formatted and safe to use.
    It removes any leading/trailing whitespace and converts the scheme and host to lowercase.
*/

void sanitize_url(char *url) {
    // Remove leading/trailing whitespace
    char *start = url;
    char *end = url + strlen(url) - 1;
    while (isspace(*start)) start++;
    while (isspace(*end)) end--;
    *(++end) = '\0';
    if (start > end) {
        // empty url
        return;
    }
    
    // Convert scheme to lowercase
    char *scheme_end = strstr(start, "://");
    if (scheme_end != NULL) {
        char *scheme_start = start;
        char *c = scheme_start;
        while (c != scheme_end) {
            *c = tolower(*c);
            c++;
        }
    }
    
    // Convert host to lowercase
    char *host_start = strstr(start, "://");
    if (host_start != NULL) {
        host_start += 3; // skip "://"
        char *host_end = host_start;
        while (*host_end != '\0' && *host_end != '/' && *host_end != ':') {
            *host_end = tolower(*host_end);
            host_end++;
        }
    }
}

int main() {
    char url1[] = "  Https://www.EXAMPLE.com/  ";
    char url2[] = "  ftp://ftp.example.com:21/  ";
    char url3[] = "  http://www.example.com/path/to/file?query=string#fragment  ";
    
    sanitize_url(url1);
    sanitize_url(url2);
    sanitize_url(url3);
    
    printf("Sanitized URL 1: %s\n", url1);
    printf("Sanitized URL 2: %s\n", url2);
    printf("Sanitized URL 3: %s\n", url3);
    
    return 0;
}