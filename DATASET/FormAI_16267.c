//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 100
#define MAX_DATA_LENGTH 200
#define MAX_RESPONSE_TIME 10
#define MAX_RETRIES 3

typedef struct {
    char url[MAX_URL_LENGTH];
    char data[MAX_DATA_LENGTH];
    double response_time;
    int status_code;
    int num_retries;
} website;

// function declarations
void initialize_websites(int num_websites, website* websites);
void check_websites(int num_websites, website* websites);
int get_url_status(char* url, char* data, double* response_time);

int main() {
    int num_websites = 3;
    website websites[num_websites];
    initialize_websites(num_websites, websites);
    while (1) {
        check_websites(num_websites, websites);
        sleep(10);
    }
    return 0;
}

// Initializes the website struct array with URLs and default values
void initialize_websites(int num_websites, website* websites) {
    strcpy(websites[0].url, "https://www.google.com");
    strcpy(websites[1].url, "https://www.youtube.com");
    strcpy(websites[2].url, "https://www.facebook.com");
    for (int i = 0; i < num_websites; i++) {
        strcpy(websites[i].data, "");
        websites[i].response_time = 0.0;
        websites[i].status_code = 0;
        websites[i].num_retries = 0;
    }
}

// Loops through websites array and checks each one
void check_websites(int num_websites, website* websites) {
    for (int i = 0; i < num_websites; i++) {
        int status = get_url_status(websites[i].url, websites[i].data, &(websites[i].response_time));
        websites[i].status_code = status;
        if (status == 200) {
            printf("%s is up! Response time: %f seconds\n", websites[i].url, websites[i].response_time);
        }
        else {
            printf("%s is down! Status code: %d\n", websites[i].url, status);
            if (websites[i].num_retries < MAX_RETRIES) {
                printf("Retrying in 10 seconds...\n");
                websites[i].num_retries++;
                sleep(10);
                i--;
            }
        }
    }
}

// Sends a GET request to the specified URL and measures the response time
int get_url_status(char* url, char* data, double* response_time) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (!curl) {
        return -1;
    }
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "User-Agent: uptime_monitor/1.0");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // follow redirects
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL); // don't write data
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, MAX_RESPONSE_TIME * 1000L); // set maximum response time
    res = curl_easy_perform(curl); // perform request
    if (res != CURLE_OK) {
        curl_easy_cleanup(curl);
        return -2;
    }
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &res);
    curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, response_time);
    curl_easy_cleanup(curl);
    return res;
}