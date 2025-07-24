//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_STATUS 20

struct status {
    char url[MAX_URLS];
    char code[MAX_STATUS];
    double response_time;
};

struct url_list {
    char url[MAX_URLS];
};

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

void monitor_url(struct url_list url, struct status *status) {
    CURL *curl;
    CURLcode res;
    double response_time;
    char *code;
    time_t start, end;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        time(&start);
        curl_easy_setopt(curl, CURLOPT_URL, url.url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
            time(&end);
            response_time = difftime(end, start);
            sprintf(status->code, "%s", code);
            status->response_time = response_time;
        } else {
            sprintf(status->code, "%s", curl_easy_strerror(res));
            status->response_time = -1.0;
        }
        sprintf(status->url, "%s", url.url);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main() {
    struct url_list urls[MAX_URLS] = {
        {"https://www.google.com/"},
        {"https://www.facebook.com/"},
        {"https://www.twitter.com/"},
        {"https://www.amazon.com/"},
        {"https://www.youtube.com/"},
        {"https://www.github.com/"},
        {"https://www.apple.com/"},
        {"https://www.microsoft.com/"},
        {"https://www.instagram.com/"},
        {"https://www.wikipedia.org/"}
    };

    struct status statuses[MAX_URLS];
    int i;

    for (i = 0; i < MAX_URLS; i++) {
        monitor_url(urls[i], &statuses[i]);
        printf("%s returned status %s in %f seconds\n", statuses[i].url, statuses[i].code, statuses[i].response_time);
    }

    return 0;
}