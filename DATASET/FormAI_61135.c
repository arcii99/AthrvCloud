//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 100
#define TIMEOUT_SECONDS 10

struct UrlAvailability {
    char url[MAX_URL_LENGTH];
    int availableStatus;
};

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int check_url_availability(char *url) {
    CURL *curl;
    CURLcode res;
    long http_code = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl == NULL) {
        printf("Failed to initialize easy curl!\n");
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT_SECONDS);

    res = curl_easy_perform(curl);

    if (res == CURLE_OK) {
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        if (http_code >= 200 && http_code < 300) {
            curl_easy_cleanup(curl);
            return 1;
        }
    }

    curl_easy_cleanup(curl);
    return 0;
}

void monitor_urls(struct UrlAvailability *urls, int numUrls) {
    while (1) {
        for (int i = 0; i < numUrls; i++) {
            int availability = check_url_availability(urls[i].url);

            if (availability == 1 && urls[i].availableStatus == 0) {
                printf("%s is now available!\n", urls[i].url);
                urls[i].availableStatus = 1;
            }
            else if (availability == 0 && urls[i].availableStatus == 1) {
                printf("%s is now unavailable!\n", urls[i].url);
                urls[i].availableStatus = 0;
            }
        }
    }
}

int main() {
    struct UrlAvailability urls[] = {
        {"https://www.google.com", 0},
        {"https://www.github.com", 0},
        {"https://www.facebook.com", 0},
        {"https://www.stackoverflow.com", 0},
        {"https://www.netflix.com", 0}
    };

    int numUrls = sizeof(urls) / sizeof(struct UrlAvailability);

    monitor_urls(urls, numUrls);

    return 0;
}