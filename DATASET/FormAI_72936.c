//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 200

// Function to check if a character is special
int is_special(char c) {
    if(c=='.' || c=='-' || c=='_' || c=='~' || (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) {
        return 0;
    }
    return 1;
}

// Function to sanitize a URL
char* sanitize_url(char* url) {
    char* sanitized_url = malloc(sizeof(char)*MAX_URL_LENGTH);
    int i=0, j=0;
    while(url[i]!='\0') {
        if(j>=MAX_URL_LENGTH-1) { // Check if maximum URL length reached
            break;
        }
        if(is_special(url[i])) { // Encode special characters
            sprintf(&sanitized_url[j], "%%%02X", url[i]);
            j += 3;
        } else { // Copy non-special characters
            sanitized_url[j] = url[i];
            j++;
        }
        i++;
    }
    sanitized_url[j] = '\0';
    return sanitized_url;
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    char* sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
    free(sanitized_url);
    return 0;
}