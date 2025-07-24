//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

int main(void) {

    char *url = "https://www.google.com";
    int timeout = 5;
    double response_time;
    CURL *curl;
    CURLcode res;

    while(1) {
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        res = curl_easy_perform(curl);

        gettimeofday(&end_time, NULL);

        if(res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        }
        else {
            response_time = (double)((end_time.tv_sec * 1000000 + end_time.tv_usec) - (start_time.tv_sec * 1000000 + start_time.tv_usec)) / 1000000;
            printf("%s is UP, Response time: %.2lf seconds.\n", url, response_time);
        }
        
        curl_easy_cleanup(curl);
        sleep(60);
    }
    return 0;
}