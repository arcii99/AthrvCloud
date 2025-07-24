//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char url[1000];
    char illegal_chars[] = "<>@!#$%^&*()_+[]\\{}|;':\"/?,.`~";
    int i, j, length;

    printf("Enter URL: ");
    fgets(url, sizeof(url), stdin);

    length = strlen(url);

    for (i = 0; i < length; i++) {
        for (j = 0; j < sizeof(illegal_chars); j++) {
            if (url[i] == illegal_chars[j]) {
                url[i] = '-';
            }
        }
    }

    printf("Sanitized URL: %s", url);

    return 0;
}