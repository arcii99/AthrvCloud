//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define URL "http://www.example.com"
#define INTERVAL 60
#define TIMEOUT 5

bool isWebsiteUp(const char* url) {
    CURL *curl;
    CURLcode response;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        response = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        return response == CURLE_OK ? true : false;
    }
    return false;
}

void logStatus(bool status) {
    FILE *file;
    char *filename = "log.txt";
    time_t now = time(NULL);
    char timestamp[sizeof("YYYY-MM-DD HH:MM:SS")];
    strftime(timestamp, sizeof(timestamp), "%F %T", localtime(&now));
    file = fopen(filename, "a");
    if (file) {
        fprintf(file, "[%s] Website is %s\n", timestamp, status ? "UP" : "DOWN");
        fclose(file);
    }
    else {
        printf("Unable to open log file\n");
    }
}

int main() {
    printf("Starting website uptime monitor...\n");
    while (1) {
        if (isWebsiteUp(URL)) {
            logStatus(true);
            printf("[UP] %s\n", URL);
        }
        else {
            logStatus(false);
            printf("[DOWN] %s\n", URL);
        }
        sleep(INTERVAL);
    }
    return 0;
}