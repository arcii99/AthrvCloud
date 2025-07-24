//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

void checkAvailability(CURL *curl, char *url) {
    CURLcode res;
    double time_taken;
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);

    if(res == CURLE_OK) {
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time_taken);
        printf("%s is up! Response time: %f ms\n", url, time_taken*1000);
    } 
    else {
        printf("%s is down!\n", url);
    }
}

int main() {
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        char *urls[] = {"http://www.google.com", "http://www.github.com", "http://www.facebook.com"};
        int num_of_urls = sizeof(urls)/sizeof(char*);
        int i=0;
        time_t current_time;
        while(1) {
            for(i=0; i<num_of_urls; i++) {
                checkAvailability(curl, urls[i]);
            }
            current_time = time(NULL);
            printf("Last checked at: %s\n", ctime(&current_time));
            printf("===========================================\n");
            //Sleep for 5 seconds
            sleep(5);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}