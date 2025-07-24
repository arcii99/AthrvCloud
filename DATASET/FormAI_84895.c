//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *url) {
    char temp[strlen(url) + 1];
    int j = 0;

    for (int i = 0; i < strlen(url); i++) {
        if (url[i] == ' ' || url[i] == '\n') {
            continue;
        } else if (isalnum(url[i]) || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '/') {
            temp[j] = url[i];
            j++;
        } else if (url[i] == ':') {
            temp[j] = url[i];
            j++;

            if (url[i+1] == '/') {
                temp[j] = url[i+1];
                j++;

                if (url[i+2] == '/') {
                    i += 2;
                    while (url[i + 1] == '/') {
                        i++;
                    }
                }
            }
        }
    }

    temp[j] = '\0';

    if (strcmp(url, temp) != 0) {
        printf("Original URL: %s\n", url);
        printf("Sanitized URL: %s\n", temp);
    } else {
        printf("URL has not been altered.\n");
    }
}

int main() {
    char url1[] = "http://www.example.com/path to file.html";
    char url2[] = "https://example.com/a-b_c/123/456/file.jpg";
    char url3[] = "ftp://ftp.server.net/path/to/file.pdf";
    char url4[] = "http://server.net/path/to/file.docx";
    char url5[] = "invalid:url@#$&!^characters.com";

    sanitize(url1);
    printf("\n");
    sanitize(url2);
    printf("\n");
    sanitize(url3);
    printf("\n");
    sanitize(url4);
    printf("\n");
    sanitize(url5);

    return 0;
}