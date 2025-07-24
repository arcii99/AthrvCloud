//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Sanitize a given URL by removing unwanted characters
void sanitize_url(char* url) {
    char* p = url;
    while (*p) {  // loop until the end of the string
        if (*p == ' ') {  // replace spaces with %20
            *p = '%';
            *(p+1) = '2';
            *(p+2) = '0';
            p += 2;
        } else if (*p == '#' || *p == '<' || *p == '>' || *p == '\"' || *p == '\''
                   || *p == '\\' || *p == '^' || *p == '|' || *p == '{' || *p == '}'
                   || *p == '[' || *p == ']' || *p == '`') {
            // remove unwanted characters
            memmove(p, p+1, strlen(p+1) + 1);
            p--;
        }
        p++;
    }
}

int main() {
    // Example URLs
    char url1[] = "http://www.example.com/this is a test#link";
    char url2[] = "https://www.example.com/<script>alert('XSS')</script>/page.html";
    char url3[] = "ftp://www.example.com/file name with spaces.jpg";
    
    printf("Original URL 1: %s\n", url1);
    sanitize_url(url1);
    printf("Sanitized URL 1: %s\n", url1);

    printf("Original URL 2: %s\n", url2);
    sanitize_url(url2);
    printf("Sanitized URL 2: %s\n", url2);

    printf("Original URL 3: %s\n", url3);
    sanitize_url(url3);
    printf("Sanitized URL 3: %s\n", url3);

    return 0;
}