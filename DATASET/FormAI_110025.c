//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

void check_website(const char* url) {
    CURL* curl = curl_easy_init(); // initialize CURL library 
    if(curl) { 
        CURLcode res;       
        curl_easy_setopt(curl, CURLOPT_URL, url); // set URL option 
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // set to only fetch HTTP header
        res = curl_easy_perform(curl); // perform check
        if(res != CURLE_OK) { // check for error
            printf("[%s] is DOWN.\n", url);
        }
        else { // website is up
            printf("[%s] is UP.\n", url);
        }
        curl_easy_cleanup(curl); // clean up CURL library 
    }
}

void iterate_over_urls(const char** urls, int len) {
    for(int i = 0; i < len; i++) {
        check_website(urls[i]); // check each website
    }   
}

int main(void) {
    const char* urls[] = {"https://www.google.com", "https://www.facebook.com", "https://www.amazon.com"}; // list of urls to check
    const int num_urls = sizeof(urls)/sizeof(urls[0]); // get number of urls
    
    printf("Website Uptime Monitor started...\n");
    time_t t = time(NULL); // get current time
    struct tm* lt = localtime(&t); // convert time to local
    printf("Current time: %d/%d/%d %d:%d:%d\n", lt->tm_mon+1, lt->tm_mday, lt->tm_year+1900, lt->tm_hour, lt->tm_min, lt->tm_sec); // print current time
    iterate_over_urls(urls, num_urls); // iterate over each url
    
    getchar(); // pause console before exit
    return 0;
}