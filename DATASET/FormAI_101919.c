//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: high level of detail
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_URL_LENGTH 1024
#define MAX_QUERY_LENGTH 512

void sanitize_url(char *url) {
    char clean_url[MAX_URL_LENGTH];
    char query[MAX_QUERY_LENGTH];
    int i = 0, j = 0, k = 0;
    int is_query = 0;
    int ignore_next = 0;

    // clean the URL character by character
    while(url[i] != '\0' && j < MAX_URL_LENGTH) {
        if(is_query && url[i] == ' ') {
            // ignore all spaces in query
            i++;
            continue;
        }
        if(!is_query && url[i] == '?' && k < MAX_QUERY_LENGTH) {
            // reached end of URL, now copying query
            is_query = 1;
            clean_url[j++] = url[i++];
            continue;
        }
        if(ignore_next) {
            // ignore characters that we have flagged to ignore
            ignore_next = 0;
            i++;
            continue;
        }
        if(url[i] == '\'' || url[i] == '\"' || url[i] == ';') {
            // ignore these special characters to prevent SQL injection
            i++;
            continue;
        }
        if(url[i] == '<') {
            // ignore all characters until we reach '>'
            while(url[i] != '>' && url[i] != '\0')
                i++;
            if(url[i] == '\0')
                break;
            i++;
            continue;
        }
        if(url[i] == '/' && url[i+1] == '/') {
            // ignore entire URL if it starts with // to prevent command injection
            return;
        }
        if(url[i] == '\\') {
            // ignore the next character
            ignore_next = 1;
            i++;
            continue;
        }
        if(url[i] == '&') {
            // replace & with %26 to prevent cross-site scripting attacks
            clean_url[j++] = '%';
            clean_url[j++] = '2';
            clean_url[j++] = '6';
            i++;
            continue;
        }
        if(isalpha(url[i])) {
            // convert uppercase characters to lowercase
            clean_url[j++] = tolower(url[i++]);
            continue;
        }
        clean_url[j++] = url[i++];
    }
    if(is_query) {
        // append a null terminator at the end of the query
        query[k++] = '\0';
    }
    printf("Clean URL: %s\n", clean_url);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to sanitize: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    //remove new line character from input
    url[strcspn(url, "\n")] = 0;

    sanitize_url(url);

    return 0;
}