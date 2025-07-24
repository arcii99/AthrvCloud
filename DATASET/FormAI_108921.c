//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char url[1000];
    printf("Enter the URL that needs to be sanitized: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0;

    printf("The sanitized URL is: ");

    char protocol[] = "http://";
    char https_protocol[] = "https://";
    if (strstr(url, protocol) == 0 && strstr(url, https_protocol) == 0) {
        printf("%s", https_protocol);
    }

    char * host = strstr(url, "://") + 3;
    if (host != NULL) {
        if (strstr(host, "www.") == 0) {
            printf("www.");
        }

        int length = strlen(host);
        for (int i = 0; i < length; i++) {
            if (!(host[i] == '.' || isalnum(host[i]))) {
                host[i] = '-';
            }
            printf("%c", tolower(host[i]));
        }
    }

    printf("\n");

    return 0;
}