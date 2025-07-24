//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

// global variables for storing the result and timestamp
char result[10];
time_t timestamp;

// function to write the response data from the http request
static size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    // convert the response to a string and store in result
    snprintf(result, sizeof(result), "%.*s", (int)(size * nmemb), (char *)contents);
    // store the timestamp of the response
    timestamp = time(NULL);
    return size * nmemb;
}

int main(int argc, char **argv) {
    // check if the url argument is passed
    if (argc != 2) {
        printf("Usage: ./uptime_monitor <url>\n");
        return 1;
    }

    // initialize curl
    CURL *curl = curl_easy_init();
    if (!curl) {
        printf("Error: Failed to initialize curl\n");
        return 1;
    }

    // set the url for the http request
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // set the timeout for the http request
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 5000L);

    // set the function for handling the http response
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    // perform the http request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("Error: Failed to perform http request: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    // check the http response code
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    if (http_code != 200) {
        printf("Error: Unexpected http response code: %ld\n", http_code);
        curl_easy_cleanup(curl);
        return 1;
    }

    // check the response data
    bool is_up = strncmp(result, "Up", 2) == 0;
    if (!is_up) {
        printf("Error: Website is down!\n");
        curl_easy_cleanup(curl);
        return 1;
    }

    // print the uptime status and timestamp
    printf("Website is up, last checked at: %s", ctime(&timestamp));

    // cleanup curl
    curl_easy_cleanup(curl);
    return 0;
}