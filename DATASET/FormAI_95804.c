//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

/* Peaceful HTTP Client Example Program */

typedef struct {
    char* data;
    size_t size;
} Buffer;

/* callback function for curl to write data to buffer */
static size_t writeCallback(void* ptr, size_t size, size_t nmemb, void* data) {
    size_t realsize = size * nmemb;
    Buffer* mem = (Buffer*) data;

    mem->data = realloc(mem->data, mem->size + realsize + 1);

    if(mem->data == NULL) {
        printf("Error: Not enough memory\n");
        return 0;
    }

    memcpy(&(mem->data[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->data[mem->size] = 0;

    return realsize;
}

/* function to create and execute HTTP GET request */
void getRequest(char* url) {
    CURL* curl = curl_easy_init();
    CURLcode res;
    Buffer buffer = {NULL, 0};

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*) &buffer);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response: %s\n", buffer.data);
        }

        curl_easy_cleanup(curl);
    }
}

int main() {
    printf("Welcome to the Peaceful HTTP Client Example Program\n");

    char* url = "https://jsonplaceholder.typicode.com/posts/1";
    getRequest(url);

    return 0;
}