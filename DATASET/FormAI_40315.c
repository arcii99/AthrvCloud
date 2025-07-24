//FormAI DATASET v1.0 Category: Browser Plugin ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to extract domain name from an URL
char* get_domain(char* url) {
    char* p = strstr(url, "//") + 2;
    char* end = strchr(p, '/');
    if (end == NULL) {
        end = p + strlen(p);
    }
    char* domain = (char*) malloc((end - p) + 1);
    strncpy(domain, p, end - p);
    domain[end - p] = '\0';
    return domain;
}

// function to check if a URL is safe
int is_safe(char* url) {
    char* domain = get_domain(url);
    // add your check for safe domains here
    int safe = strcmp(domain, "google.com") == 0 || strcmp(domain, "wikipedia.org") == 0;
    free(domain);
    return safe;
}

// main function to handle browser events
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: browser-plugin <url>\n");
        return 1;
    }
    char* url = argv[1];
    if (!is_safe(url)) {
        printf("Unsafe URL: %s\n", url);
        return 1;
    }
    printf("Opening URL: %s\n", url);
    // add your code to open the URL in the browser here
    return 0;
}