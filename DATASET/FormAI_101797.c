//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

// function to handle the response data
static size_t handle_response(char *ptr, size_t size, size_t nmemb, void *userdata) {
    // cast userdata
    double *speed = (double*)userdata;
    // calculate speed in Megabits per second (Mbps) based on received data size and elapsed time
    *speed = ((double)size * (double)nmemb * 8.0) / ((double)CLOCKS_PER_SEC * difftime(time(NULL), *speed));
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    double speed = 0.0;
    clock_t start;
    char url[100] = "http://speedtest.net/speedtest/random4000x4000.jpg";
    
    // initialize cURL
    curl = curl_easy_init();
    if(curl) {
        // set the URL to connect to
        curl_easy_setopt(curl, CURLOPT_URL, url);
        // set the callback function to handle response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);
        // pass userdata to the callback function to save speed result
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &speed);
        
        // start measuring time
        start = clock();
        
        // execute the HTTP request
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            // if there is an error during request, print error message
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // if the request is successful, print the result
            printf("Download speed: %.2f Mbps\n", speed);
        }
        
        // cleanup
        curl_easy_cleanup(curl);
    }
    return 0;
}