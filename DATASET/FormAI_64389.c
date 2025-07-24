//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Function callback for processing HTTP response from server
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    size_t actual_size = size * nmemb;
    char response[actual_size + 1];
    memcpy(response, ptr, actual_size);
    printf("HTTP Response: %s\n", response);
    return actual_size;
}

int main(void)
{
    CURL *curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize CURL!\n");
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/todos/1"); // set URL for the request

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json"); // set headers for the request
    headers = curl_slist_append(headers, "Authorization: Bearer <<YOUR_TOKEN>>");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers); // set header options for the request
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback); // set callback function to process HTTP response

    CURLcode response_code = curl_easy_perform(curl); // execute the request
    if (response_code != CURLE_OK) {
        printf("Failed to execute HTTP request! Error: %s\n", curl_easy_strerror(response_code));
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}