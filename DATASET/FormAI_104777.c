//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* sanitize_url(char* url);

int main()
{
    // initialize the URL to be sanitized
    char url[100] = "   hTTpS://www.example.com:443/path//    ";

    // print the original URL
    printf("Original URL: %s\n", url);

    // sanitize the URL
    char* sanitized_url = sanitize_url(url);

    // print the sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // free the dynamically allocated memory
    free(sanitized_url);

    return 0;
}

char* sanitize_url(char* url)
{
    // remove whitespace before and after the URL
    char* start = url;
    char* end = url + strlen(url) - 1;
    while (*start == ' ')
    {
        start++;
    }
    while (*end == ' ')
    {
        end--;
    }
    *(end + 1) = '\0';

    // remove trailing slashes
    end = url + strlen(url) - 1;
    while (*end == '/')
    {
        *end = '\0';
        end--;
    }

    // convert the scheme to lowercase
    char* scheme_end = strstr(url, "://");
    if (scheme_end != NULL)
    {
        for (char* p = url; p < scheme_end; p++)
        {
            *p = tolower(*p);
        }
    }

    // remove default port numbers
    char* port_start = strstr(url, ":");
    if (port_start != NULL)
    {
        int port = atoi(port_start + 1);
        if ((strcmp(url, "http") == 0 && port == 80) || (strcmp(url, "https") == 0 && port == 443))
        {
            *port_start = '\0';
        }
    }

    // remove duplicate forward slashes after the scheme
    char* p1 = strstr(url, "://");
    char* p2 = strstr(p1 + 3, "//");
    while (p2 != NULL)
    {
        memmove(p1 + 3, p2 + 1, strlen(p2));
        p2 = strstr(p1 + 3, "//");
    }

    // allocate memory for the sanitized URL
    char* sanitized_url = (char*) malloc(strlen(url) + 1);

    // copy the sanitized URL into the dynamically allocated memory
    strcpy(sanitized_url, url);

    return sanitized_url;
}