//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

/*Declaration of struct that holds the response data*/
struct ResponseData {
    char* data;
    size_t size;
};

/*Write callback function used by curl*/
static size_t write_response(void *ptr, size_t size, size_t nmemb, void* userdata) {
    size_t response_size = size * nmemb;
    struct ResponseData* response_data = (struct ResponseData*) userdata;

    /*Reallocate memory to store the response data*/
    response_data->data = realloc(response_data->data, response_data->size+response_size+1);

    if (response_data->data == NULL) {
        printf("Error: Failed to allocate memory\n");
        return 0;
    }

    /*Copy response data to memory*/
    memcpy(&(response_data->data[response_data->size]), ptr, response_size);
    response_data->size+=response_size;
    response_data->data[response_data->size] = '\0';

    return response_size;
}

int main() {
    CURL* curl;
    CURLcode res;
    struct ResponseData response_data;

    /*Initialize curl*/
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        /*Set options for curl*/

        /*Set target URL*/
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

        /*Follow redirects*/
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /*Set callback function to handle response data*/
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        /*Perform curl request*/
        res = curl_easy_perform(curl);

        /*Check if there were any errors*/
        if (res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            printf("Website is up and running!\n");
        }

        /*Clean up after curl*/
        curl_easy_cleanup(curl);
    }

    /*Clean up global curl resources*/
    curl_global_cleanup();

    return 0;
}