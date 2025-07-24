//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define URL "https://www.example.com"

// Struct for storing the website details
typedef struct website {
    char *url;
    long response_code;
} website_t;

// Check website status
int check_website_status(website_t *w) {
    CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, w->url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error checking URL: %s\n", w->url);
            curl_easy_cleanup(curl);
            return 1;
        }
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &w->response_code);
        curl_easy_cleanup(curl);
        return 0;
    }
    return 1;
}

int main() {
    website_t website = {
        .url = URL,
        .response_code = 0
    };

    check_website_status(&website);
    printf("Website: %s\n", website.url);
    printf("Response code: %ld\n", website.response_code);

    return 0;
}