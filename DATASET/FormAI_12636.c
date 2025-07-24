//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);

int main(int argc, char **argv) {
    CURL *curl;
    CURLcode res;
    char url[MAX_URL_LEN], input[MAX_URL_LEN], output[MAX_URL_LEN];

    printf("Enter the URL to fetch: ");
    fflush(stdout);
    fgets(input, MAX_URL_LEN, stdin);
    input[strcspn(input, "\n")] = 0;

    if (strlen(input) >= MAX_URL_LEN) {
        fprintf(stderr, "ERROR: URL too long\n");
        return 1;
    }

    strcpy(url, input);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else {
            printf("%s", output);
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize = size * nmemb;
    char *output = (char *)userdata;
    strncat(output, ptr, realsize);
    return realsize;
}