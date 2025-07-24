//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to sanitize URL */
char* sanitizeURL(char *url) {
    int i, j = 0, len = strlen(url);
    char *newURL = (char*)malloc((len + 1) * sizeof(char)); 

    for(i = 0; i < len; i++) {
        if(isalpha(url[i])) { // check if alphabet
            newURL[j] = tolower(url[i]); // convert to lowercase
            j++;
        } else if(url[i] == '.' || url[i] == '/' || url[i] == '-'
               || url[i] == '_') { // check if valid character
            newURL[j] = url[i];
            j++;
        }
    }

    newURL[j] = '\0'; // terminate string
    return newURL;
}

int main(void) {
    char url[100], *newURL;

    printf("Enter a URL to sanitize: ");
    scanf("%s", url);

    /* Sanitize URL and print */
    newURL = sanitizeURL(url);
    printf("Sanitized URL: %s\n", newURL);
    free(newURL);

    return 0;
}