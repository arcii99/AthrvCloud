//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void) {
    char url[1000];
    printf("Enter URL : ");
    fgets(url, 1000, stdin);

    printf("\nSanitizing URL ...\n");

    // Removing any extra space or newline character at the end
    url[strcspn(url, "\n")] = '\0';

    // Removing any whitespaces at the beginning of the URL
    while (url[0] == ' ') {
        memmove(url, url + 1, strlen(url));
    }

    // Checking if the URL starts with http:// or https://
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
        printf("\nValid URL : %s\n", url);
    } 
    else {
        printf("\nInvalid URL : %s\n", url);
        int i;
        for (i=0; url[i]; i++) {
            if (url[i] == ' ') url[i] = '+';
        }
        printf("\nURL after replacing spaces with '+' : %s\n", url);
    }

    return 0;
}