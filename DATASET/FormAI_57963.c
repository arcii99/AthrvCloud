//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void) {
    CURL *curl;
    CURLcode res;
    const char *url = "https://www.example.com";
    long response_code;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // follow any redirects
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // use HEAD request
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return 1;
        }

        // get the response code
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        if(response_code == 200) {
            printf("Website is up and running!\n");
        } else {
            printf("Website is down! Response code: %ld\n", response_code);
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}