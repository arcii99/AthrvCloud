//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <curl/curl.h>
#include <time.h>

void check_website(char *url, int interval) {
    CURL *curl;
    CURLcode res;
    struct timespec start, end;

    while (1) {
        curl = curl_easy_init();
        if (curl) {
            clock_gettime(CLOCK_MONOTONIC, &start);
            curl_easy_setopt(curl, CURLOPT_URL, url);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                printf("%s is down!\n", url);
            } else {
                clock_gettime(CLOCK_MONOTONIC, &end);
                double time_taken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1000;
                printf("%s is up! Response time: %.2f microseconds\n", url, time_taken);
            }
            curl_easy_cleanup(curl);
        } else {
            printf("Could not initialize cURL!\n");
        }
        sleep(interval);
    }
}

int main() {
    char *url = "https://www.google.com/";
    int interval = 5; // Check every 5 seconds

    printf("Checking website %s every %d seconds...\n", url, interval);
    check_website(url, interval);

    return 0;
}