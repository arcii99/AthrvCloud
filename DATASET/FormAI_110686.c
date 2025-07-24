//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1000
#define MAX_DOMAIN_LENGTH 100
#define MAX_PATH_LENGTH 800

void sanitize_url(char* url, char* sanitized_url);

int main() {
    char url[MAX_URL_LENGTH];
    char sanitized_url[MAX_URL_LENGTH];
    
    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0'; // remove trailing newline character from fgets
    
    sanitize_url(url, sanitized_url);
    
    printf("Sanitized URL: %s\n", sanitized_url);
    
    return 0;
}

void sanitize_url(char* url, char* sanitized_url) {
    char* protocol_end = strstr(url, "://");
    
    // Remove protocol (http:// or https://)
    if (protocol_end != NULL) {
        strcpy(sanitized_url, &protocol_end[3]);
    } else {
        strcpy(sanitized_url, url);
    }
    
    // Get domain name
    char* domain_end = strstr(sanitized_url, "/");
    if (domain_end == NULL) {
        domain_end = sanitized_url + strlen(sanitized_url);
    }
    
    char domain[MAX_DOMAIN_LENGTH];
    strncpy(domain, sanitized_url, domain_end - sanitized_url);
    domain[domain_end - sanitized_url] = '\0';
    
    // Remove www. subdomain
    if (strncmp(domain, "www.", 4) == 0) {
        strcpy(domain, &domain[4]);
    }
    
    // Convert domain to lowercase
    for (int i = 0; domain[i]; i++) {
        domain[i] = tolower(domain[i]);
    }
    
    // Remove any dots from end of domain
    char* dot = strrchr(domain, '.');
    while (dot != NULL && dot[1] == '\0') {
        *dot = '\0';
        dot = strrchr(domain, '.');
    }
    
    // Remove any path after domain
    char* path_start = domain_end;
    if (*path_start == '/') {
        char path[MAX_PATH_LENGTH];
        strncpy(path, path_start, MAX_PATH_LENGTH);
        path[MAX_PATH_LENGTH - 1] = '\0';
        strcat(domain, path);
    }
    
    strcat(sanitized_url, "/");
    strcat(sanitized_url, domain);
}