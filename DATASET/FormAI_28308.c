//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define MAX_URLS 5
#define TIMEOUT 10
#define RESPONSE_OK 200

int timeout = TIMEOUT;

typedef struct {
    int response;
    long connect_time;
    char* url;
} URLStatus;

void display_status(const URLStatus status) {
    printf("URL : %s\n", status.url);
    if (status.response == RESPONSE_OK) {
        printf("Status : UP\n");
    } else {
        printf("Status : DOWN\n");
    }
    printf("Connect time : %ld seconds\n", status.connect_time);
    printf("================================\n");
}

void check_url(const char* url, URLStatus* status) {
    CURL* easy_handle = curl_easy_init();
    if (easy_handle) {
        curl_easy_setopt(easy_handle, CURLOPT_URL, url);
        curl_easy_setopt(easy_handle, CURLOPT_CONNECTTIMEOUT, timeout);
        curl_easy_setopt(easy_handle, CURLOPT_TIMEOUT, timeout);
        CURLcode response = curl_easy_perform(easy_handle);
        if (response == CURLE_OK) {
            curl_easy_getinfo(easy_handle, CURLINFO_RESPONSE_CODE, &status->response);
            curl_easy_getinfo(easy_handle, CURLINFO_CONNECT_TIME, &status->connect_time);
        } else {
            status->response = 0;
            status->connect_time = 0;
        }
        curl_easy_cleanup(easy_handle);
    }
}

void monitor_urls(const char* urls[], URLStatus* statuses, int num_urls) {
    if (num_urls == 0) {
        return;
    }
    URLStatus status;
    check_url(urls[0], &status);
    status.url = (char*) urls[0];
    statuses[0] = status;
    display_status(status);
    sleep(1);
    monitor_urls(urls+1, statuses+1, num_urls-1);
}

int main() {
    const char* urls[MAX_URLS] = {"http://example.com", "http://google.com", "http://facebook.com", "http://twitter.com", "http://linkedin.com"};
    URLStatus statuses[MAX_URLS];
    monitor_urls(urls, statuses, MAX_URLS);
    return 0;
}