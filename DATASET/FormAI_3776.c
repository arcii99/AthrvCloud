//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL_LENGTH 1024
#define DATA_LENGTH 1024
#define TIMEOUT 30

struct Userdata {
    char url[URL_LENGTH];
    int status;
    double responsetime;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    return size * nmemb;
}

int check_website(char* url, struct Userdata *userdata) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;

    long response_code;
    double response_time = 0.0;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        headers = curl_slist_append(headers, "Accept: */*");
        headers = curl_slist_append(headers, "User-Agent: uptime-checker/1.0");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

        struct timespec start_time, end_time;
        clock_gettime(CLOCK_MONOTONIC, &start_time);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            clock_gettime(CLOCK_MONOTONIC, &end_time);
            response_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;

            userdata->status = response_code;
            userdata->responsetime = response_time;
        } else {
            userdata->status = -1;
            userdata->responsetime = TIMEOUT * 1000;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        curl_global_cleanup();
    } else {
        return -1;
    }
    return 0;
}

int main() {
    char url[URL_LENGTH];
    printf("Enter URL to check: ");
    fgets(url, URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;

    struct Userdata userdata;
    memset(userdata.url, 0, sizeof(userdata.url));
    strncpy(userdata.url, url, sizeof(userdata.url) - 1);

    int code = check_website(url, &userdata);

    if (code == -1) {
        printf("Error: Cannot initialize CURL!\n");
        exit(1);
    }

    printf("Website Status: %d\n", userdata.status);
    printf("Website Response Time: %g ms\n", userdata.responsetime);

    return 0;
}