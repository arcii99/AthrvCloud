//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to sanitize URLs
char *sanitize_url(char *url) {
    char *sanitized_url = malloc(strlen(url) + 1);
    int i, j = 0;
    for (i = 0; url[i] != '\0'; i++) {
        if (isalnum(url[i]) || url[i] == '/' || url[i] == '-' || url[i] == '_' || url[i] == '.') {
            // if it is alphanumeric or /, -, _, or . add to the sanitized_url string
            sanitized_url[j++] = url[i];
        } else if (url[i] == ' ') {
            // if it is a space, add a %20 to the sanitized_url string
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j++] = '0';
        }
    }
    // add null terminator to the end of the string
    sanitized_url[j] = '\0';
    return sanitized_url;
}

// main function to test sanitize_url function
int main() {
    char *url = "https://www.google.com/search?q=c%20language+examples&rlz=1C1GCEU_enUS832US832&oq=c+language+examples&aqs=chrome.0.69i59l2j35i39j0l2j69i60.4783j1j7&sourceid=chrome&ie=UTF-8";
    char *sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);

    return 0;
}