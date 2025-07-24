//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

int main() {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];
    int i, j;
    int url_length;

    //Get the raw URL from the user
    printf("Enter the URL to be sanitized: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    //Remove new line character from the URL
    url_length = strlen(url) - 1;
    if (url[url_length] == '\n') {
        url[url_length] = '\0';
    }

    //Sanitize the URL by removing any invalid characters
    for (i = 0, j = 0; i < url_length; i++) {
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') ||
            (url[i] >= '0' && url[i] <= '9') || url[i] == ':' || url[i] == '.' || url[i] == '/' ||
            url[i] == '?' || url[i] == '=' || url[i] == '&' || url[i] == '-') {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';

    //Print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    return 0;
}