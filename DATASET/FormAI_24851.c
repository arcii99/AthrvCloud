//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define MINUTE_IN_SECONDS 60

struct website_info {
    char url[MAX_URL_LENGTH];
    int interval;
};

void check_website(struct website_info *w) {
    CURL *curl;
    CURLcode res;
    double time_elapsed;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, w->url);

        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            printf("%s is up and running!\n", w->url);
        } else {
            printf("%s is down!\n", w->url);
        }
        
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time_elapsed);
        printf("Time elapsed: %.2f seconds\n", time_elapsed);
        
        curl_easy_cleanup(curl);
    }
}

int main() {
    struct website_info website1 = {"https://example1.com", 3};
    struct website_info website2 = {"https://example2.com", 5};
    
    while (1) {
        check_website(&website1);
        check_website(&website2);
        sleep(MINUTE_IN_SECONDS);
    }
    
    return 0;
}