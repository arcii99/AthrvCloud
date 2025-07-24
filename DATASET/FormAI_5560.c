//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

// Callback function for handling response from IMAP server
size_t handle_response(void *ptr, size_t size, size_t nmemb, void *userp) {
    char **response_ptr = (char**)userp;
    *response_ptr = (char*)malloc(size * nmemb + 1);
    strncpy(*response_ptr, (char*)ptr, size * nmemb);
    return size * nmemb;
}

int main(void) {
    CURL *curl;
    CURLcode res;
    char *response = NULL;

    curl = curl_easy_init();
    if(curl) {
        // Set IMAP server URL and authentication information
        curl_easy_setopt(curl, CURLOPT_URL, "imap://example.com");
        curl_easy_setopt(curl, CURLOPT_USERNAME, "username");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "password");

        // Send command to server to fetch list of folders in mailbox
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "LIST \"\" \"*\"");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Send request to server and handle response
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            printf("List of folders:\n%s\n", response);
        } else {
            printf("Error: %s\n", curl_easy_strerror(res));
        }

        // Free response memory and clean up
        free(response);
        curl_easy_cleanup(curl);
    }
    return 0;
}