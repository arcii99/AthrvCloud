//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a special character
int isSpecial(char c) {
    char special[] = {'#', '&', '+', ',', '/', ':', ';', '=', '?', '@', '[', ']',' '};
    int i;
    for(i=0;i<13;i++) {
        if(c == special[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char url[1000];
    char sanitize_url[1000];
    printf("Enter URL to sanitize: ");
    fgets(url, 1000, stdin);
    url[strcspn(url, "\n")] = 0; // Removing newline character
    int len = strlen(url);

    int i, j;
    j = 0;
    for(i=0;i<len;i++) {
        if(!isSpecial(url[i])) {
            sanitize_url[j++] = url[i];
        }
    }
    sanitize_url[j] = '\0';

    printf("Sanitized URL: %s", sanitize_url);

    return 0;
}