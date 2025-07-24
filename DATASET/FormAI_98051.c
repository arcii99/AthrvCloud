//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <math.h>
#include <time.h>

// function declarations
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
int check_website(char *url);

int main(int argc, char **argv)
{
    // list of URLs to monitor
    char *urls[] = {"https://www.google.com", "https://www.facebook.com", "https://www.twitter.com", "https://www.github.com", "https://www.linkedin.com", "https://www.reddit.com"};
    int num_urls = sizeof(urls)/sizeof(char*);

    // initialize Curl
    curl_global_init(CURL_GLOBAL_ALL);

    // get current time
    time_t current_time;
    time(&current_time);

    // print header
    printf("Website Uptime Monitor\n");
    printf("Monitoring websites at %s\n\n", ctime(&current_time));

    // loop through URLs and check website status
    int i;
    for (i = 0; i < num_urls; i++) {
        int status = check_website(urls[i]);

        // print website status
        printf("%s - ", urls[i]);
        if (status == 200) {
            printf("Online\n");
        } else {
            printf("Offline (%d)\n", status);
        }

        // wait for 1 second
        usleep(1000000);

        // flush output stream
        fflush(stdout);
    }

    // cleanup
    curl_global_cleanup();
    return 0;
}

// function to write Curl response to memory
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    return size * nmemb;
}

// function to check website status using Curl
int check_website(char *url)
{
    CURL *curl = curl_easy_init();
    if (curl) {
        // set Curl options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        // perform Curl request
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            // return failure status code
            return -1;
        }

        // check response code
        long response_code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        // cleanup
        curl_easy_cleanup(curl);

        // return response code
        return (int)response_code;
    }

    // fallback failure status code
    return -1;
}