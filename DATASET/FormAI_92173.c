//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "https://www.example.com" //URL to monitor
#define INTERVAL 30 //Interval time in seconds

//Global variables to store previous and current status
bool prev_status = true;
bool current_status = true;

//Function to check website availability
bool check_availability()
{
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        CURLcode res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if(http_code == 200)
                return true;
        }
        curl_easy_cleanup(curl);
    }
    return false;
}

//Function to get current time
char* get_current_time()
{
    time_t current_time = time(NULL);
    return ctime(&current_time);
}

int main()
{
    while(true)
    {
        current_status = check_availability();
        if(current_status != prev_status) //If status changes
        {
            if(current_status)
                printf("[INFO] %s - Website is now available.\n", get_current_time());
            else
                printf("[WARNING] %s - Website is now down.\n", get_current_time());
        }
        prev_status = current_status;

        sleep(INTERVAL); //Sleep for interval time
    }
    return 0;
}