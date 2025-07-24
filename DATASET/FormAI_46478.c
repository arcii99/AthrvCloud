//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

// function to check website status
int checkWebsiteStatus(char *url) {
    CURL *curl;
    CURLcode res;
    long http_code;

    // initialize libcurl
    curl = curl_easy_init();
    if(curl) {
        // set the URL to monitor
        curl_easy_setopt(curl, CURLOPT_URL, url);
        // perform the request
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            // get HTTP status code
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            // cleanup libcurl
            curl_easy_cleanup(curl);
            // return HTTP status code
            return (int)http_code;
        }
        else {
            // if request fails, return -1
            curl_easy_cleanup(curl);
            return -1;
        }
    }
    else {
        // if libcurl initialization fails, return -1
        return -1;
    }
}

int main() {
    char *url = "https://www.example.com";
    int status;
    time_t current_time;

    // loop infinitely to monitor website status every 30 seconds
    while (1) {
        // get current time
        current_time = time(NULL);
        // check website status
        status = checkWebsiteStatus(url);
        // check if website is up or down
        if (status == -1) {
            printf("%s is down at %s\n", url, ctime(&current_time));
        }
        else if (status == 200) {
            printf("%s is up and running at %s\n", url, ctime(&current_time));
        }
        else {
            printf("%s returned HTTP status code %d at %s\n", url, status, ctime(&current_time));
        }
        // wait for 30 seconds before checking again
        sleep(30);
    }

    return 0;
}