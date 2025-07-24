//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#define URL "https://www.example.com"

size_t write_callback(void *buffer, size_t size, size_t nmemb, void *userp) {
    /* This function is called by libcurl when data is received from the server */
    return size * nmemb;
}

int main(void) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");
    curl = curl_easy_init(); /* Initialize curl */
    if(curl) {
        /* Set curl options */
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        /* Perform the request */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return EXIT_FAILURE;
        }
        /* Clean up */
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        /* Success! */
        printf("Website %s is up.\n", URL);
        return EXIT_SUCCESS;
    }
    else {
        /* Initialization failed */
        fprintf(stderr, "curl_easy_init() failed.\n");
        return EXIT_FAILURE;
    }
}