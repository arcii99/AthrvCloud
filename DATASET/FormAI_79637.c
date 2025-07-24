//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Ada Lovelace
// Ada Lovelace style C Website Uptime Monitor example program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LEN 256
#define MAX_TIME_STR_LEN 26

typedef struct {
    char url[MAX_URL_LEN];
    time_t last_check;
    bool is_up;
} Website;

void check_website(Website *website) {
    CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            website->is_up = (http_code == 200 || http_code == 301 || http_code == 302);
            website->last_check = time(NULL);
        } else {
            website->is_up = false;
        }
        curl_easy_cleanup(curl);
    }
}

char *current_time_str() {
    char *time_str = (char *) malloc(sizeof(char) * MAX_TIME_STR_LEN);
    time_t t = time(NULL);
    strftime(time_str, MAX_TIME_STR_LEN, "%c", localtime(&t));
    return time_str;
}

int main() {
    // Define the list of websites to monitor
    Website websites[] = {
        {"https://www.google.com", 0, false},
        {"https://www.facebook.com", 0, false},
        {"https://www.twitter.com", 0, false}
    };
    int num_websites = sizeof(websites) / sizeof(Website);

    // Check the websites and print the results
    printf("Ada Lovelace Website Uptime Monitor\n");
    printf("----------------------------------\n");
    printf("Checking %d websites...\n", num_websites);
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_websites; i++) {
        check_website(&websites[i]);
        char *time_str = current_time_str();
        printf("Website: %s\n", websites[i].url);
        if (websites[i].is_up) {
            printf("Status: up\n");
        } else {
            printf("Status: down\n");
        }
        printf("Last check: %s\n", time_str);
        printf("--------------------------------------------------\n");
        free(time_str);
    }

    return 0;
}