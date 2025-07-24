//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

int main(void) {
    char url[256];
    regex_t preg;
    char* regex = "^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w\\.-]*)*\\/?$";

    printf("Enter a URL:\n");
    scanf("%s", url);

    if (regcomp(&preg, regex, REG_EXTENDED) != 0) {
        printf("Error compiling regular expression\n");
        return 1;
    }

    int match = regexec(&preg, url, 0, NULL, 0);
    if (match != 0) {
        printf("Invalid URL\n");
        return 1;
    }

    // check for potentially malicious content
    if (strstr(url, "<script>") != NULL || strstr(url, "onmouseover=") != NULL) {
        printf("Potentially malicious content found in URL\n");
        // remove any script or event listeners
        char sanitizedUrl[256];
        char* token;
        char* ptr = url;
        while ((token = strtok(ptr, "<>")) != NULL) {
            if (strstr(token, "script") == NULL && strstr(token, "on") == NULL) {
                strcat(sanitizedUrl, token);
                printf("Token: %s\n", token);
            }
            ptr = NULL;
        }

        strcpy(url, sanitizedUrl);
    }

    printf("Sanitized URL: %s\n", url);

    return 0;
}