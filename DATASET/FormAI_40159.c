//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sanitizeUrl(char *url) {
    char *sanitizedUrl = (char*) malloc(strlen(url) + 1); // Allocate memory for sanitized url
    int i, j;
    j = 0;
 
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] == '&' || url[i] == '?' || url[i] == '#' || url[i] == ';') {
            continue; // ignore special characters
        }
        sanitizedUrl[j] = url[i];
        j++;
    }
    sanitizedUrl[j] = '\0'; // add null character at the end of the string
 
    // Convert all characters to lower case
    for (i = 0; i < strlen(sanitizedUrl); i++) {
        sanitizedUrl[i] = tolower(sanitizedUrl[i]);
    }
 
    return sanitizedUrl;
}
 
int main() {
    char url[100] = "https://www.Example-URL.com/Path1/Path2;param1=value1;param2=value2?query1=value3&query2=value4#fragment"; // Example URL
    char *sanitizedUrl = sanitizeUrl(url);
    printf("\nOriginal URL: %s", url);
    printf("\nSanitized URL: %s\n", sanitizedUrl);
    free(sanitizedUrl); // Free the allocated memory
    return 0;
}