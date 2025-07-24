//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <curl/curl.h>

// Global variables
int status_code;
double elapsed_time;

// Callback function for CURL
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    // Do nothing with the response data
    return size * nmemb;
}

// Function to check URL uptime
void check_url(char *url) {
    CURL *curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 10L);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L);

    // Perform the request and get the response
    CURLcode response = curl_easy_perform(curl_handle);

    // Get details about the request and print it to the console
    curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &status_code);
    curl_easy_getinfo(curl_handle, CURLINFO_TOTAL_TIME, &elapsed_time);
    printf("URL: %s\n", url);
    printf("Status Code: %d\n", status_code);
    printf("Elapsed Time: %.2f seconds\n", elapsed_time);

    // Clean up the CURL handle
    curl_easy_cleanup(curl_handle);
}

int main() {
    // List of URLs to check uptime for
    char *urls[] = {
        "https://www.google.com/",
        "https://www.facebook.com/",
        "https://www.twitter.com/",
        "https://www.github.com/",
        "https://www.amazon.com/"
    };
    int num_urls = sizeof(urls) / sizeof(urls[0]);

    // Check uptime for each URL
    for (int i = 0; i < num_urls; i++) {
        check_url(urls[i]);
    }

    return 0;
}