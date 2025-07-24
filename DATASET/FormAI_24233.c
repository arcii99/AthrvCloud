//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char *url = argv[1];
    double time_taken;
    time_t current_time;
    struct tm * time_info;
    char time_buf[80];

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        current_time = time(NULL);
        time_info = localtime(&current_time);
        strftime(time_buf, 80, "%Y-%m-%d %H:%M:%S", time_info);
        printf("[%s] Started monitoring %s\n", time_buf, url);

        while(1) {
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                printf("[%s] ERROR: %s\n", time_buf, curl_easy_strerror(res));
            } else {
                time_taken = 0.0;
                curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time_taken);
                printf("[%s] SUCCESS: %s\n", time_buf, url);
                printf("[%s] Response time: %.2f seconds\n", time_buf, time_taken);
            }
            current_time = time(NULL);
            time_info = localtime(&current_time);
            strftime(time_buf, 80, "%Y-%m-%d %H:%M:%S", time_info);
            sleep(60);
        }

        curl_easy_cleanup(curl);
    } else {
        printf("Error initializing curl\n");
    }

    return 0;
}