//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1000

/*
 * Function prototypes
 */
bool valid_protocol(char* url);
void remove_trailing_slash(char* url);
void remove_duplicate_slashes(char* url);
char* sanitize_url(char* url);

/*
 * Main function
 */
int main()
{
    char url[MAX_URL_LENGTH];

    // Get URL input from user
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove newline character from input
    url[strcspn(url, "\n")] = 0;

    // Sanitize URL and print result
    printf("Sanitized URL: %s\n", sanitize_url(url));

    return 0;
}

/*
 * Checks if URL has a valid protocol.
 * Currently supported protocols: http, https, ftp
 */
bool valid_protocol(char* url)
{
    char* supported_protocols[] = {"http", "https", "ftp"};
    int num_supported_protocols = sizeof(supported_protocols) / sizeof(supported_protocols[0]);
    char* protocol = strtok(url, ":");
    for (int i = 0; i < num_supported_protocols; i++) {
        if (strcasecmp(supported_protocols[i], protocol) == 0) {
            return true;
        }
    }
    return false;
}

/*
 * Removes trailing slash from URL.
 */
void remove_trailing_slash(char* url)
{
    size_t url_len = strlen(url);
    if (url_len > 0 && url[url_len - 1] == '/') {
        url[url_len - 1] = '\0';
    }
}

/*
 * Removes duplicate slashes from URL.
 */
void remove_duplicate_slashes(char* url)
{
    char* source = url;
    char* destination = url;
    bool saw_slash = false;
    while (*source != '\0') {
        if (*source == '/') {
            if (!saw_slash) {
                *destination++ = *source;
                saw_slash = true;
            }
        } else {
            *destination++ = *source;
            saw_slash = false;
        }
        source++;
    }
    *destination = '\0';
}

/*
 * Sanitizes URL by removing unsupported protocols,
 * removing trailing slash, and removing duplicate slashes.
 */
char* sanitize_url(char* url)
{
    if (!valid_protocol(url)) {
        return "";
    }

    // Skip past colon to get to protocol
    strsep(&url, ":");

    remove_trailing_slash(url);
    remove_duplicate_slashes(url);

    return url;
}