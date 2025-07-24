//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: minimalist
#include <stdio.h>
#include <string.h>

void sanitizeURL(char *url)
{
    // remove leading and trailing white spaces
    int leading_space_count = 0;
    while (isspace(*url))
    {
        leading_space_count++;
        url++;
    }
    int url_len = strlen(url);
    while (url_len > 0 && isspace(url[url_len - 1]))
    {
        url_len--;
    }
    url[url_len] = '\0';

    // remove scheme
    char *colon = strchr(url, ':');
    if (colon != NULL)
    {
        if (strstr(url, "http://") == url || strstr(url, "https://") == url)
        {
            url = colon + 3;
        }
    }

    // remove query string and fragment identifier
    char *question_mark = strchr(url, '?');
    if (question_mark != NULL)
    {
        *question_mark = '\0';
    }
    char *hash_mark = strchr(url, '#');
    if (hash_mark != NULL)
    {
        *hash_mark = '\0';
    }

    // remove duplicate slashes
    char *src = url;
    char *dst = url;
    int slash_count = 0;
    while (*src != '\0')
    {
        if (*src == '/')
        {
            slash_count++;
            if (slash_count >= 2)
            {
                src++;
                continue;
            }
        }
        else
        {
            slash_count = 0;
        }
        *dst++ = *src++;
    }
    *dst = '\0';
    
    // remove trailing slash
    if (dst > url && *(dst - 1) == '/')
    {
        *(dst - 1) = '\0';
    }

    // remove dot segments
    char *beg = url;
    char *end = url;
    while (*beg != '\0')
    {
        if (beg[0] == '.' && (beg[1] == '/' || beg[1] == '\0'))
        {
            beg += 2;
        }
        else if (beg[0] == '.' && beg[1] == '.' && (beg[2] == '/' || beg[2] == '\0'))
        {
            while (end > url && *--end != '/');
            if (end == url)
            {
                end++;
            }
            beg += 3;
        }
        else
        {
            while (*beg != '/' && *beg != '\0')
            {
                *end++ = *beg++;
            }
            if (*beg == '/')
            {
                *end++ = *beg++;
            }
        }
    }
    *end = '\0';
    
    // remove trailing dot segment
    if (end > url + 1 && *(end - 1) == '.' && *(end - 2) == '/')
    {
        *(end - 1) = '\0';
        end--;
        while (end > url && *(end - 1) != '/')
        {
            end--;
        }
    }

    // add leading "http://" if no scheme is present
    if (strstr(url, "://") == NULL)
    {
        char *new_url = malloc(strlen(url) + 8);
        if (new_url != NULL)
        {
            strcpy(new_url, "http://");
            strcat(new_url, url);
            free(url);
            url = new_url;
        }
    }

    printf("Sanitized URL: %s\n", url);
}

int main()
{
    char url[] = "   hTTp://exAMPLe.cOm:80/x/./y/../z/.?a=1&b=2#ref   ";
    sanitizeURL(url);
    return 0;
}