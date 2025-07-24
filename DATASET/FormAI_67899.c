//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* sanitize_url(const char* url) {
    char sanitized_url[100];
    int i = 0;
    int j = 0;

    while (url[i] != '\0') {
        if (isalpha(url[i]) || isdigit(url[i])) {
            sanitized_url[j] = tolower(url[i]);
            j++;
        } else if (url[i] == '.') {
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }

    return strdup(sanitized_url);
}

int main() {
    char* url = "hTtP://www.Example.com:80/path/to/myfile.php?name=John%20Doe&age=25#anchor";
    char* sanitized_url = sanitize_url(url);

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}