//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

char* url = "https://www.example.com";
time_t current_time;

size_t write_callback(char *ptr, size_t size, size_t nmemb, char *stream) {
    return size * nmemb;
}

void check_website() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            printf("%s: Error - %s\n", asctime(localtime(&current_time)), curl_easy_strerror(res));
        } else {
            printf("%s: Success\n", asctime(localtime(&current_time)));
        }

        curl_easy_cleanup(curl);
    }
}

int main(void) {
    while(1) {
        time(&current_time);

        check_website();

        sleep(60);
    }

    return 0;
}