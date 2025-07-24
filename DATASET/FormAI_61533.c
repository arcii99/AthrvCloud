//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize(char *url) {
    char buffer[10000];
    int j = 0;
    int i;
    int length = strlen(url);
    char current;

    for (i = 0; i < length; i++) {
        current = url[i];

        if (current == '\\') {
            continue;
        }

        if (current == '/') {
            buffer[j] = '%';
            buffer[j + 1] = '2';
            buffer[j + 2] = 'F';
            j += 3;
        } else {
            buffer[j] = current;
            j++;
        }
    }

    buffer[j] = '\0';
    strcpy(url, buffer);
}

int main() {
    char url[10000];

    printf("Welcome to the futuristic URL sanitizer!\n\n");

    printf("Please enter the URL you would like to sanitize: ");
    scanf("%s", url);

    sanitize(url);

    printf("\n\nThe sanitized URL is: %s", url);

    return 0;
}