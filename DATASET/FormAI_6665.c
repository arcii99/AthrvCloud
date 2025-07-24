//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Touring
// Alan Turing style C program for website uptime monitor 
#include <stdio.h>
#include <curl/curl.h>
#include <time.h>

// function to check if website is up
int check_website(char *url) {
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        // perform the request
        res = curl_easy_perform(curl);

        // check for errors
        if(res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code == 200) {
                curl_easy_cleanup(curl);
                return 1;
            }
        }
        // cleanup curl
        curl_easy_cleanup(curl);
    }

    return 0;
}

int main() {
    char *url = "https://www.example.com";
    int status;
    time_t current_time;
    struct tm * time_info;
    char time_string[9];

    while(1) {
        // get current time
        time(&current_time);
        time_info = localtime(&current_time);
        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
        
        // check website status
        status = check_website(url);
        if(status == 1) {
            printf("%s: Website is up and running!\n", time_string);
        } else {
            printf("%s: Error - Website is down!\n", time_string);
        }

        // sleep for 30 seconds
        sleep(30);
    }

    return 0;
}