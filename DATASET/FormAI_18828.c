//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include<stdio.h>
#include<string.h>

// Function to remove unwanted characters from C URLs
void sanitizeUrl(char* url) {
    int i, j;
    int length = strlen(url);

    // Removing protocol from URL
    if(strstr(url, "://")) {
        for(i = 0; i < length - 2; i++)
            url[i] = url[i + 3];
        url[i - 2] = '\0';
    }

    // Removing trailing slash if present
    if(url[length - 1] == '/')
        url[length - 1] = '\0';

    // Removing query string if present
    if(strstr(url, "?")) {
        for(i = 0; url[i] != '?'; i++);
        url[i] = '\0';
    }

    // Removing fragment identifier if present
    if(strstr(url, "#")) {
        for(i = 0; url[i] != '#'; i++);
        url[i] = '\0';
    }

    // Removing any double slashes in the URL
    for(i = 0; i < length - 1; i++) {
        if(url[i] == '/' && url[i + 1] == '/')
            for(j = i + 1; j < length; j++)
                url[j] = url[j + 1];
    }
}

int main() {
    // Testing the sanitizeUrl() function
    char url1[] = "https://example.com//page/?param=value#fragment";
    char url2[] = "http://www.example.com/path/";
    char url3[] = "ftp://ftp.example.com/file?param1=value1&param2=value2#hash";

    printf("Original URL: %s\n", url1);
    sanitizeUrl(url1);
    printf("Sanitized URL: %s\n", url1);

    printf("Original URL: %s\n", url2);
    sanitizeUrl(url2);
    printf("Sanitized URL: %s\n", url2);

    printf("Original URL: %s\n", url3);
    sanitizeUrl(url3);
    printf("Sanitized URL: %s\n", url3);

    return 0;
}