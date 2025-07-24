//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define CHECK_INTERVAL 60 // seconds

void check_website(const char *url){
    CURL *curl;
    CURLcode res;
    long http_code = 0;
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK){
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if(http_code == 200){
                printf("%s is up!\n", url);
            } else {
                printf("%s is down with error code %ld\n", url, http_code);
            }
        } else {
            printf("%s is down with error %s\n", url, curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
}

int main(int argc, char **argv){
    char url[MAX_URL_LENGTH];
    bool running = true;
    while(running){
        printf("Enter website url to monitor: ");
        fgets(url, MAX_URL_LENGTH, stdin);
        url[strcspn(url, "\n")] = 0; // remove newline character
        check_website(url);
        sleep(CHECK_INTERVAL);
    }
    return 0;
}