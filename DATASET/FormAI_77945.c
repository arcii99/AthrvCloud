//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL "https://www.google.com"

void check_website_status(CURL *curl, CURLcode res);

int main()
{
    CURL *curl;
    CURLcode res;

    // Initialize the curl session
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    // Set the URL to check
    curl_easy_setopt(curl, CURLOPT_URL, URL);

    // Set the timeout for the request
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

    // Perform the website check
    res = curl_easy_perform(curl);

    check_website_status(curl, res);

    // Cleanup the curl session
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}

void check_website_status(CURL *curl, CURLcode res)
{
    int http_status_code = 0;
    char *effective_url;

    // Get the HTTP status code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_status_code);

    // Get the effective URL
    curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &effective_url);

    printf("Effective URL: %s\n", effective_url);
    printf("HTTP Status Code: %d\n\n", http_status_code);

    // Check the result of the request
    if (res != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    else
    {
        switch (http_status_code)
        {
        case 200:
            printf("Website is up and running\n");
            break;
        case 404:
            printf("Website is down (404 Not Found)\n");
            break;
        case 500:
            printf("Website is down (500 Internal Server Error)\n");
            break;
        default:
            printf("Website is down (HTTP Status Code %d)\n", http_status_code);
            break;
        }
    }
}