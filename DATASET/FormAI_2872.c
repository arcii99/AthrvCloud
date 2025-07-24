//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// function to execute curl request
int execute_curl_request(char *url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 0;
        }
        curl_easy_cleanup(curl);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int interval, i;
    char url[100];

    if (argc != 3) {
        printf("Invalid arguments. Usage: %s <URL> <Interval>\n", argv[0]);
        return 0;
    }

    strcpy(url, argv[1]);
    interval = atoi(argv[2]);

    printf("Monitoring %s every %d seconds\n", url, interval);

    while (1) {
        int status = execute_curl_request(url);
        if (status == 0) {
            printf("Error: Unable to reach %s\n", url);
        }
        sleep(interval);
    }

    return 0;
}