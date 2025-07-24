//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 100

char safe_characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./_-";

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    int url_length = strlen(url);
    char sanitized_url[MAX_URL_LENGTH];
    int sanitized_url_length = 0;

    for(int i=0; i<url_length; i++) {
        char current_character = url[i];
        if(strchr(safe_characters, current_character) != NULL) {
            sanitized_url[sanitized_url_length++] = current_character;
        } else {
            sanitized_url[sanitized_url_length++] = '_';
        }
    }

    printf("Sanitized URL: %s\n", sanitized_url);
    return 0;
}