//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

/* structure to hold website information */
typedef struct _website {
    char* url;
    double last_uptime;
} website;

/* recursive website uptime monitor function */
void monitor_website(website* w) {

    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    
    if(curl) {
        /* set website URL */
        curl_easy_setopt(curl, CURLOPT_URL, w->url);

        /* perform the request */
        res = curl_easy_perform(curl);
        
        if(res == CURLE_OK) {
            /* get the response code */
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            
            /* check response code for successful connection */
            if(response_code == 200) {
                /* update last uptime */
                w->last_uptime = time(NULL);
                printf("%s is up!\n", w->url);
            } else {
                printf("%s is down :(\n", w->url);
            }
        }
        
        /* clean up */
        curl_easy_cleanup(curl);
    }
    
    /* wait 60 seconds */
    sleep(60);
    
    /* recursively call monitor_website function */
    monitor_website(w);
}

int main() {
    /* create array of websites to monitor */
    website websites[3];
    
    /* set website URLs */
    websites[0].url = "https://www.google.com";
    websites[1].url = "https://www.apple.com";
    websites[2].url = "https://www.microsoft.com";
    
    /* initialize last uptime for each website */
    for(int i = 0; i < 3; i++) {
        websites[i].last_uptime = time(NULL);
    }
    
    /* start monitoring each website recursively */
    for(int i = 0; i < 3; i++) {
        monitor_website(&websites[i]);
    }
    
    return 0;
}