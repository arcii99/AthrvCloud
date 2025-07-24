//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MAX_URL_LENGTH = 1000; // maximum URL length
const int MAX_QUERY_LENGTH = 200; // maximum query parameter length
const int MAX_PARAM_COUNT = 10; // maximum number of query parameters
const char* RESERVED_CHARACTERS = "!*'();:@&=+$,/?#[]";
const int RESERVED_CHAR_COUNT = 18;

// sanitize the input URL
char* sanitizeURL(char* url) {

    char* sanitizedURL = (char*)malloc(sizeof(char) * MAX_URL_LENGTH); // allocate memory for output URL
    char* queryParameters[MAX_PARAM_COUNT]; // array to store query parameter key-value pairs

    // check if URL is too long
    if (strlen(url) > MAX_URL_LENGTH) {
        printf("ERROR: The input URL is too long!");
        return NULL;
    }

    // check if URL scheme is present
    if (strstr(url, "http://") == NULL && strstr(url, "https://") == NULL) {
        printf("ERROR: The input URL is missing a scheme!");
        return NULL;
    }

    // separate URL into parts
    char* scheme = strtok(url, ":");
    char* rest = strtok(NULL, "");

    // add scheme to output URL
    strcat(sanitizedURL, scheme);
    strcat(sanitizedURL, "://");

    // extract the domain and path
    char* domain = strtok(rest, "/");
    char* path = strtok(NULL, "");

    // check if domain is present
    if (domain == NULL) {
        printf("ERROR: The input URL is missing a domain!");
        return NULL;
    }

    // add domain to output URL
    strcat(sanitizedURL, domain);

    // sanitize path
    if (path != NULL) {
        strcat(sanitizedURL, "/");
        char* sanitizedPath = (char*)malloc(sizeof(char) * strlen(path));
        strcpy(sanitizedPath, path);

        // replace reserved characters with percent-encoded equivalents
        for (int i = 0; i < strlen(RESERVED_CHARACTERS); i++) {
            char* c = strchr(sanitizedPath, RESERVED_CHARACTERS[i]);
            while (c != NULL) {
                int index = c - sanitizedPath;
                char* temp = (char*)malloc(sizeof(char) * (strlen(sanitizedPath) + 2));
                strncpy(temp, sanitizedPath, index);
                strcat(temp, "%");
                char encoding[3];
                sprintf(encoding, "%X", (int)RESERVED_CHARACTERS[i]);
                strcat(temp, encoding);
                strcat(temp, sanitizedPath + index + 1);
                sanitizedPath = temp;
                c = strchr(c + 3, RESERVED_CHARACTERS[i]);
            }
        }

        strcat(sanitizedURL, sanitizedPath);
        free(sanitizedPath);
    }

    // check if there are any query parameters
    char* queryIndex = strchr(rest, '?');
    if (queryIndex != NULL) {
        char* queryString = queryIndex + 1;
        char* queryParams = strtok(queryString, "&");

        int paramCount = 0;
        while (queryParams != NULL && paramCount < MAX_PARAM_COUNT) {
            char* key = strtok(queryParams, "=");
            char* value = strtok(NULL, "");

            // sanitize key and value
            char* sanitizedKey = (char*)malloc(sizeof(char) * MAX_QUERY_LENGTH);
            char* sanitizedValue = (char*)malloc(sizeof(char) * MAX_QUERY_LENGTH);
            int keyLength = strlen(key);
            int valueLength = strlen(value);

            for (int i = 0; i < keyLength; i++) {
                if (key[i] == '+' || key[i] == ' ') {
                    sanitizedKey[i] = '%';
                    sanitizedKey[i+1] = '2';
                    sanitizedKey[i+2] = '0';
                } else {
                    sanitizedKey[i] = key[i];
                }
            }
            sanitizedKey[keyLength] = '\0';

            for (int i = 0; i < valueLength; i++) {
                if (value[i] == '+' || value[i] == ' ') {
                    sanitizedValue[i] = '%';
                    sanitizedValue[i+1] = '2';
                    sanitizedValue[i+2] = '0';
                } else {
                    sanitizedValue[i] = value[i];
                }
            }
            sanitizedValue[valueLength] = '\0';

            // store key-value pair in array
            queryParameters[paramCount] = (char*)malloc(sizeof(char) * (strlen(sanitizedKey) + strlen(sanitizedValue) + 1));
            sprintf(queryParameters[paramCount], "%s=%s", sanitizedKey, sanitizedValue);
            paramCount++;

            free(sanitizedKey);
            free(sanitizedValue);

            queryParams = strtok(NULL, "&");
        }

        // add sanitized query parameters to output URL
        strcat(sanitizedURL, "?");
        for (int i = 0; i < paramCount; i++) {
            strcat(sanitizedURL, queryParameters[i]);
            if (i != paramCount - 1) {
                strcat(sanitizedURL, "&");
            }
            free(queryParameters[i]);
        }
    }

    return sanitizedURL;
}

int main() {

    // test cases
    char* testURL1 = "http://www.example.com/path/file.html?name=John+Doe&age=30";
    char* testURL2 = "https://www.example.com/path/file2.html?foo=bar%20baz&test=true";
    char* testURL3 = "www.example.com/path/file3.html";
    char* testURL4 = "http://www.example.com/path/file4.html?name=Frank&age=45&phone=999-999-9999&username=jdoe";

    // sanitize test URLs and print results
    char* sanitizedURL1 = sanitizeURL(testURL1);
    printf("Sanitized URL 1: %s\n", sanitizedURL1);
    free(sanitizedURL1);

    char* sanitizedURL2 = sanitizeURL(testURL2);
    printf("Sanitized URL 2: %s\n", sanitizedURL2);
    free(sanitizedURL2);

    char* sanitizedURL3 = sanitizeURL(testURL3);
    printf("Sanitized URL 3: %s\n", sanitizedURL3);
    free(sanitizedURL3);

    char* sanitizedURL4 = sanitizeURL(testURL4);
    printf("Sanitized URL 4: %s\n", sanitizedURL4);
    free(sanitizedURL4);

    return 0;
}