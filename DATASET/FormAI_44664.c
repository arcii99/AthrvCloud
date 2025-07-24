//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 100

void check_website(char *url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 200) {
                printf("%s is UP! Response code: %ld\n", url, response_code);
            } else {
                printf("%s is DOWN! Response code: %ld\n", url, response_code);
            }
        } else {
            printf("%s is DOWN with error message: %s\n", url, curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    int num_urls;

    printf("Enter the number of URLs to monitor: ");
    scanf("%d", &num_urls);
    printf("Enter the URLs to monitor:\n");

    for(int i=0; i<num_urls; i++) {
        scanf("%s", url);
        check_website(url);
    }

    return 0;
}