//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char url[100], sanitized_url[100];
    int i, j = 0, protocol_flag = 0;

    printf("Welcome to the URL Sanitizer Program!\n\n");
    printf("Enter the URL to sanitize : ");
    scanf("%s", url);

    for (i = 0; i < strlen(url); i++) {
        if (url[i] == ':') {
            protocol_flag = 1;
            continue;
        }

        if (protocol_flag == 0) {
            sanitized_url[j++] = url[i];
        } else {
            if (url[i] == '/') {
                sanitized_url[j++] = url[i];
                break;
            } else if (url[i] == '.') {
                sanitized_url[j++] = url[i];
            } else {
                sanitized_url[j++] = tolower(url[i]);
            }
        }
    }

    sanitized_url[j] = '\0';

    printf("\nSanitized URL : %s\n", sanitized_url);

    return 0;
}