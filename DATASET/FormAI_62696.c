//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048

void sanitize_url(char *url) {
    // Remove whitespace from beginning and end of URL
    char *start = url;
    char *end = url + strlen(url) - 1;
    while (*start && isspace(*start)) {
        start++;
    }
    while (end > start && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    
    // Check for scheme and add if missing
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        char scheme[MAX_URL_LENGTH] = "http://";
        strncat(scheme, url, MAX_URL_LENGTH - strlen(scheme) - 1);
        strncpy(url, scheme, MAX_URL_LENGTH);
    }
    
    // Remove any fragments (#) or queries (?)
    char *fragment = strchr(url, '#');
    if (fragment != NULL) {
        *fragment = '\0';
    }
    char *query = strchr(url, '?');
    if (query != NULL) {
        *query = '\0';
    }
    
    // Normalize paths (remove ./ and ../)
    char *path = strchr(url, '/');
    if (path != NULL) {
        char *curr = path;
        char *prev = NULL;
        while (*curr) {
            if (strncmp(curr, "./", 2) == 0) {
                memmove(curr, curr + 2, strlen(curr + 2) + 1);
            } else if (strncmp(curr, "../", 3) == 0) {
                if (prev != NULL) {
                    char *slash = strrchr(url, '/');
                    if (slash != NULL) {
                        *slash = '\0';
                    }
                    memmove(prev, curr + 3, strlen(curr + 3) + 1);
                }
            } else {
                prev = curr;
                curr = strchr(curr + 1, '/');
            }
        }
    }
    
    // Convert to lowercase (except for hostnames)
    char *host_start = strstr(url, "//");
    if (host_start != NULL) {
        host_start += 2;
        char *host_end = strchr(host_start, '/');
        if (host_end == NULL) {
            host_end = url + strlen(url);
        }
        char *hostname = strdup(host_start);
        char *curr = hostname;
        while (*curr) {
            *curr = tolower(*curr);
            curr++;
        }
        memcpy(host_start, hostname, strlen(hostname));
        free(hostname);
    }
}

int main() {
    char url[MAX_URL_LENGTH] = "  Https://www.ExaMplE.coM:80/pAtH/?qUeRy=VaLuE#FrAgMeNt  ";
    printf("Original URL: %s\n", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}