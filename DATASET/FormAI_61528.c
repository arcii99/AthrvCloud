//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

struct Data {
    char *memory;
    size_t size;
};

size_t write_callback(char *ptr, size_t size, size_t nmemb, struct Data *data)
{
    size_t realsize = size * nmemb;
    data->memory = (char *)realloc(data->memory, data->size + realsize + 1);
    if (data->memory == NULL) {
        printf("ERROR: Not enough memory to allocate.\n");
        return 0;
    }
    memcpy(&(data->memory[data->size]), ptr, realsize);
    data->size += realsize;
    data->memory[data->size] = 0;
    return realsize;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Usage: %s server username password\n", argv[0]);
        return -1;
    }
    
    CURL *curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize CURL.\n");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    struct Data data = {
        .memory = NULL,
        .size = 0
    };

    // Step 1: Connect to server.
    snprintf(buffer, BUFFER_SIZE, "IMAP://%s", argv[1]);
    curl_easy_setopt(curl, CURLOPT_URL, buffer);
    curl_easy_setopt(curl, CURLOPT_USERNAME, argv[2]);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, argv[3]);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "CAPABILITY"); // Send CAPABILITY command to check server capabilities.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    CURLcode ret = curl_easy_perform(curl);
    if (ret != CURLE_OK) {
        printf("Failed to connect to server. Error code: %d\n", ret);
        return -1;
    }
    printf("%s", data.memory);
    free(data.memory);
    data.memory = NULL;
    data.size = 0;

    // Step 2: Login.
    snprintf(buffer, BUFFER_SIZE, "LOGIN %s %s", argv[2], argv[3]);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, buffer);
    ret = curl_easy_perform(curl);
    if (ret != CURLE_OK) {
        printf("Failed to login. Error code: %d\n", ret);
        return -1;
    }
    printf("Logged in successfully.\n");

    // Step 3: Select mailbox.
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "SELECT INBOX"); // Select INBOX mailbox.
    ret = curl_easy_perform(curl);
    if (ret != CURLE_OK) {
        printf("Failed to select mailbox. Error code: %d\n", ret);
        return -1;
    }
    printf("Mailbox selected successfully.\n");

    // Step 4: Fetch message headers.
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "FETCH 1:* (BODY[HEADER])"); // Fetch headers of all messages in the mailbox.
    ret = curl_easy_perform(curl);
    if (ret != CURLE_OK) {
        printf("Failed to fetch message headers. Error code: %d\n", ret);
        return -1;
    }
    printf("Message headers fetched successfully.\n");

    // Step 5: Logout.
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "LOGOUT");
    ret = curl_easy_perform(curl);
    if (ret != CURLE_OK) {
        printf("Failed to logout. Error code: %d\n", ret);
        return -1;
    }
    printf("Logged out successfully.\n");

    curl_easy_cleanup(curl);
    return 0;
}