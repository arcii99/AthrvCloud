//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

/* Function to sanitize the URL */
void sanitize_url(char *url) {
    int len = strlen(url);
    int i = 0, j = 0;
    char temp[MAX_URL_LENGTH];
    memset(temp, 0, sizeof(temp));

    /* Remove any non-alphanumeric characters */
    for (i = 0; i < len; i++) {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '-' || url[i] == '_') {
           temp[j++] = url[i];
        }
    }

    /* Copy sanitized URL back to original URL */
    strncpy(url, temp, j);
    url[j] = '\0';
}

/* Function to test the URL sanitizer */
int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter the URL to sanitize (Max Length: %d):\n", MAX_URL_LENGTH-1);
    scanf("%s", url);

    sanitize_url(url);

    printf("Sanitized URL: %s\n", url);
    return 0;
}