//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024
#define MAX_DOMAIN_LENGTH 256
#define MAX_PATH_LENGTH 512
#define MAX_QUERYSTRING_LENGTH 256

char* sanitizeURL(char* url);

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    char* sanitizedURL = sanitizeURL(url);
    printf("The sanitized URL is: %s", sanitizedURL);
    free(sanitizedURL);
    return 0;
}

char* sanitizeURL(char* url) {
    // Check for NULL input
    if (url == NULL || strlen(url) == 0) {
        return NULL;
    }

    char* temp = calloc(MAX_URL_LENGTH, sizeof(char)); // Allocate memory to store sanitized URL
    if (temp == NULL) {
        fprintf(stderr, "Error allocating memory for sanitized URL.\n");
        return NULL;
    }

    // Remove leading and trailing whitespace
    char* start = url;
    while (isspace(*start)) {
        start++;
    }
    char* end = url + strlen(url) - 1;
    while (end > start && isspace(*end)) {
        end--;
    }
    *(end+1) = '\0';

    // Check for HTTP/HTTPS protocol
    if (strncmp(start, "http://", 7) != 0 && strncmp(start, "https://", 8) != 0) {
        strcpy(temp, "http://"); // Add HTTP protocol
    }

    start += (strncmp(start, "http://", 7) == 0) ? 7 : 8; // Move start pointer past protocol

    char domain[MAX_DOMAIN_LENGTH];
    char path[MAX_PATH_LENGTH];
    char querystring[MAX_QUERYSTRING_LENGTH];

    // Extract domain from URL
    int i = 0;
    while (*start && *start != '/' && *start != '?' && i < MAX_DOMAIN_LENGTH-1) {
        if (*start == ':' && strncmp(start+1, "//", 2) == 0) { // Skip port number
            start += 3;
            continue;
        }
        domain[i] = *start;
        start++;
        i++;
    }
    domain[i] = '\0';
    
    // Extract path from URL
    i = 0;
    if (*start && *start != '?') {
        path[i] = '/';
        i++;
        while (*start && *start != '?' && i < MAX_PATH_LENGTH-1) {
            path[i] = *start;
            start++;
            i++;
        }
    }
    path[i] = '\0';
    
    // Extract querystring from URL
    i = 0;
    if (*start == '?') {
        while (*start && i < MAX_QUERYSTRING_LENGTH-1) {
            querystring[i] = *start;
            start++;
            i++;
        }
    }
    querystring[i] = '\0';

    // Sanitize domain
    char* p = domain;
    char* q = temp + strlen(temp);
    while (*p) {
        *q = tolower(*p);
        p++;
        q++;
    }

    // Copy sanitized domain, path and querystring to temp
    strcat(temp, domain);
    strcat(temp, path);
    strcat(temp, querystring);
    
    return temp;
}