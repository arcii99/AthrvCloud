//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define SIZE 1000 // Maximum size of the URL string
#define DELAY 300 // Delay between each check (in seconds)

void getUrl(char *url, char *response) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
}

int main() {
    char url[SIZE];
    char response[SIZE];
    time_t now;
    struct tm *local;
    FILE *log_file;
    log_file = fopen("log.txt","a+");
    if(log_file==NULL) {
        printf("Error creating log file.\n");
        exit(1);
    }
    fprintf(log_file, "Starting Website Uptime Monitor:\n\n");
    fflush(log_file);
    while(1) {
        // Get current time
        now = time(NULL);
        local = localtime(&now);
        // Add your website URL here
        sprintf(url, "https://www.example.com");
        // Check URL
        getUrl(url, response);
        if(!response[0]) { // If no response received
            fprintf(log_file, "Website is down | Time: %s", asctime(local));
        }
        else { // If response received
            fprintf(log_file, "Website is up | Time: %s", asctime(local));
        }
        fflush(log_file);
        sleep(DELAY);
    }
    fclose(log_file);
    return 0;
}