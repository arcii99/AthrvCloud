//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Function to be called by CURL to write data to memory
size_t write_to_mem(char *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize = size * nmemb;
    char *data = (char *) userdata;
    memcpy(data, ptr, realsize);
    return realsize;
}

// Function to check internet speed using CURL
void speed_test() {
    CURL *handle;
    CURLcode res;
    char *url = "http://speedtest.tele2.net/100MB.zip";
    double speed;

    handle = curl_easy_init();
    if (handle) {
        char *data = malloc(1024 * 1024 * 100); // Allocate 100 MB memory
        curl_easy_setopt(handle, CURLOPT_URL, url);
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_to_mem);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, data);
        curl_easy_setopt(handle, CURLOPT_LOW_SPEED_TIME, 10L); // Wait for at least 10 seconds
        res = curl_easy_perform(handle);
        if (res == CURLE_OK) {
            curl_easy_getinfo(handle, CURLINFO_SPEED_DOWNLOAD, &speed); // Get download speed in bytes per second
            printf("Your internet speed is %.2f MB/s\n", speed / (1024 * 1024)); // Convert bytes to megabytes
        } else {
            printf("Error: %s\n", curl_easy_strerror(res));
        }
        free(data);
        curl_easy_cleanup(handle);
    }
}

int main() {
    printf("Testing internet speed...\n");
    speed_test();
    return 0;
}