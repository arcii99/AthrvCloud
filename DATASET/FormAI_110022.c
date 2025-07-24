//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char *argv[]) {
    CURL *curl_handle;
    CURLcode res;
    char url[256];
    char buffer[1024];

    printf("Enter the URL to retrieve: ");
    fgets(url, 256, stdin);

    if (url[strlen(url) - 1] == '\n') {
        url[strlen(url) - 1] = '\0';
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    if (curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, buffer);
        res = curl_easy_perform(curl_handle);

        if (res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl_handle);
        curl_global_cleanup();
    }

    printf("HTTP response:\n%s\n", buffer);

    return 0;
}