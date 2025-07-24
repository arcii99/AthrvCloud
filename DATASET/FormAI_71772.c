//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h> //make sure to install the libcurl package before running this program

#define MAX_URL_LENGTH 1024
#define MAX_TIME_LENGTH 64

//Callback function to handle CURL response
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int main(int argc, char** argv) {

    //Variables to store URL and time interval
    char url[MAX_URL_LENGTH] = "";
    char time_interval[MAX_TIME_LENGTH] = "";

    //Prompt user for URL and time interval
    printf("Enter URL to monitor: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    printf("Enter time interval (in seconds): ");
    fgets(time_interval, MAX_TIME_LENGTH, stdin);

    //Remove newline character from input
    url[strcspn(url, "\n")] = 0;
    time_interval[strcspn(time_interval, "\n")] = 0;

    //Variables to store CURL response and error messages
    CURL *curl;
    CURLcode res;
    char errbuf[CURL_ERROR_SIZE];

    //Initialize CURL
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing CURL\n");
        return 1;
    }

    //Set URL to monitor
    curl_easy_setopt(curl, CURLOPT_URL, url);

    //Set callback function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    //Set error buffer
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);

    //Infinite loop to monitor website until user interrupts program
    while (1) {

        //Perform CURL request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "CURL error: %s\n", errbuf);
        } else {
            printf("Website %s is up!\n", url);
        }

        //Wait for specified time interval
        int time = atoi(time_interval);
        sleep(time);
    }

    //Cleanup
    curl_easy_cleanup(curl);
    return 0;
}