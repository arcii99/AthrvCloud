//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

#define NUM_WEBSITES 3

struct website {
    char *url;
    int status;
};

void check_website(struct website *w) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, w->url);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            w->status = 1;
        } else {
            w->status = 0;
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    struct website websites[NUM_WEBSITES];
    websites[0].url = "https://www.google.com";
    websites[0].status = 0;
    websites[1].url = "https://www.facebook.com";
    websites[1].status = 0;
    websites[2].url = "https://www.amazon.com";
    websites[2].status = 0;
    
    int i;
    for(i=0;i<NUM_WEBSITES;i++) {
        check_website(&websites[i]);
        if(websites[i].status == 1) {
            printf("Website %s is up!\n", websites[i].url);
        } else {
            printf("Website %s is down!\n", websites[i].url);
        }
    }
    
    return 0;
}