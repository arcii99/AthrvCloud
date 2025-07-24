//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove invalid characters from the URL
char *sanitize(char *url) {
    int i, j = 0, n = strlen(url);
    char *newUrl = (char *)malloc(sizeof(char) * (n+1));
    // Loop through the URL and only keep valid characters
    for(i=0; i<n; i++) {
        if (url[i] >= 'A' && url[i] <= 'Z' || url[i] >= 'a' && url[i] <= 'z' ||
            url[i] >= '0' && url[i] <= '9' || url[i] == ':' || url[i] == '/' ||
            url[i] == '.' || url[i] == '?' || url[i] == '&' || url[i] == '=') {
            newUrl[j] = url[i];
            j++;
        }
    }
    newUrl[j] = '\0';
    return newUrl;
}

int main() {
    // Example URLs to be sanitized
    char url1[] = "https://example.com/page?param=value&param2=value2";
    char url2[] = "https://www.google.com/search?q=url+sanitizer&oq=url+sanitizer";
    char url3[] = "http://127.0.0.1:8080/path/to/file?param=value";

    // Sanitize the URLs and print the results
    printf("Original URL: %s\n", url1);
    printf("Sanitized URL: %s\n\n", sanitize(url1));

    printf("Original URL: %s\n", url2);
    printf("Sanitized URL: %s\n\n", sanitize(url2));

    printf("Original URL: %s\n", url3);
    printf("Sanitized URL: %s\n\n", sanitize(url3));

    return 0;
}