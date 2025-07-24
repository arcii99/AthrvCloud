//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char url[1000];
    printf("Enter the URL to sanitize: ");
    fgets(url, 1000, stdin);
    // remove newline character from input
    url[strcspn(url, "\n")] = 0;

    char* sanitized_url = (char*) malloc(sizeof(char) * 1000);
    int j = 0;
    for(int i = 0; i < strlen(url); i++) {
        // if it is a safe character, copy it to sanitized_url
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '/' || url[i] == ':' || url[i] == '?' || url[i] == '=' || url[i] == '&') {
            sanitized_url[j] = url[i];
            j++;
        } else {
            // if it is not a safe character, encode it and copy it to sanitized_url
            char* encoded_char = (char*) malloc(sizeof(char) * 4);
            sprintf(encoded_char, "%%%02X", url[i]);
            for(int k = 0; k < strlen(encoded_char); k++) {
                sanitized_url[j] = encoded_char[k];
                j++;
            }
            free(encoded_char);
        }
    }
    sanitized_url[j] = '\0';

    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}