//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

// This function checks if the website is up or down
int check_website_status(char *url) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            curl_easy_cleanup(curl);
            return (int)response_code;
        }
        else {
            curl_easy_cleanup(curl);
            return -1;
        }
    }
}

// Main function which runs every 10 seconds
int main() {
    char *website = "http://example.com";
    while(1) {
        int status = check_website_status(website);
        if(status == 200) {
            printf("%s is up\n", website);
        }
        else if(status == -1) {
            printf("%s is unreachable\n", website);
        }
        else {
            printf("%s is down, status code: %d\n", website, status);
        }
        sleep(10);
    }
    return 0;
}