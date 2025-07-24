//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define URL "https://www.example.com"
#define INTERVAL 30

int main(void) {
    CURL *curl;
    CURLcode res;
    long http_code;
    int status = 1;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        while (status) {
            curl_easy_setopt(curl, CURLOPT_URL, URL);
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));
                status = 0;
            }
            else {
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
                if (http_code != 200) {
                    fprintf(stderr, "HTTP code: %ld\n", http_code);
                    status = 0;
                }
                else {
                    printf("URL is up and running.\n");
                }
            }
            sleep(INTERVAL);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}