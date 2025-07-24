//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

// Function to handle CURL request
static int writer_callback(char *data, size_t size, size_t nmemb, void *writer_data) {
    size_t realSize = size * nmemb;
    char *str = (char *) malloc(realSize + 1);
    if(str) {
        memcpy(str, data, realSize);
        str[realSize] = 0;
        printf("%s\n", str);
        free(str);
    }

    return realSize;
}

// Function to check if website is up or down
bool check_website_alive(const char *url) {
    CURL *curl;
    CURLcode response;
    bool is_alive = false;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer_callback);
        response = curl_easy_perform(curl);
        if(response != CURLE_OK) {
            is_alive = false;
        } else {
            int http_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if(http_code == 200 || http_code == 301 || http_code == 302) {
                is_alive = true;
            }
        }
        curl_easy_cleanup(curl);
    }

    return is_alive;
}

int main() {
    // Enter Website URL
    const char *url = "https://www.google.com";
    bool is_alive = check_website_alive(url);  // Check website is up or down
    if(is_alive) {
        printf("Website '%s' is UP.\n", url);
    } else {
        printf("Website '%s' is DOWN.\n", url);
    }

    return 0;
}