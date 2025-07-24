//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* website;
    int status;
} WebsiteStatus;

WebsiteStatus* check_website(char* website) {
    CURL* curl;
    CURLcode res;
    WebsiteStatus* status = malloc(sizeof(WebsiteStatus));
    status->website = website;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); 
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            status->status = -1;
        }
        else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            status->status = (int) response_code;
        }
        curl_easy_cleanup(curl);
    }
    else {
        fprintf(stderr, "Error in initializing CURL!\n");
        status->status = -1;
    }
    return status;
}

int main(int argc, char** argv) {
    int num_websites = 3;
    char* websites[] = {"https://www.google.com", "https://www.facebook.com", "https://www.twitter.com"};
    WebsiteStatus** statuses = malloc(num_websites * sizeof(WebsiteStatus*));
    for(int i=0;i<num_websites;i++) {
        statuses[i] = check_website(websites[i]);
        printf("%s returns %d \n", statuses[i]->website, statuses[i]->status);
    }
    free(statuses);
    return 0;
}