//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h> // To send HTTP requests
#include <stdbool.h> // To use boolean data type
#include <time.h> // To get epoch time

// Constants
#define MAX_URLS 10 // Maximum number of URLs that can be monitored
#define MAX_URL_LENGTH 100 // Maximum length of a single URL
#define MAX_BUFFER_SIZE 65536 // Maximum size of response buffer
#define UPTIME_THRESHOLD 60 // Threshold in seconds for uptime
#define INTERVAL_SECONDS 10 // Interval between checks in seconds

// Struct to hold URL information
typedef struct
{
    char url[MAX_URL_LENGTH];
    bool is_up;
    long last_response_time;
} UrlInfo;

// Function to get epoch time in seconds
long get_epoch_time()
{
    return (long) time(NULL);
}

// Function to check if URL is up
bool is_url_up(char* url)
{
    CURL* curl = curl_easy_init();
    CURLcode res;
    char buffer[MAX_BUFFER_SIZE];
    long http_code = 0;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, NULL);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
    {
        curl_easy_cleanup(curl);
        return false;
    }
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);

    if(http_code == 200)
    {
        return true;
    }
    return false;
}

// Function to print current time
void print_time()
{
    time_t now = time(NULL);
    printf("%s", ctime(&now));
}

int main()
{
    char input_buffer[MAX_URL_LENGTH];
    UrlInfo urls[MAX_URLS];
    int num_urls = 0;
    int i, j;
    bool any_url_down;
    long current_time;

    // Initialize URLs
    printf("Enter the URLs to monitor (separated by spaces):\n");
    fgets(input_buffer, MAX_BUFFER_SIZE, stdin);
    char* token = strtok(input_buffer, " \n");
    while(token != NULL && num_urls < MAX_URLS)
    {
        strncpy(urls[num_urls].url, token, MAX_URL_LENGTH);
        urls[num_urls].is_up = true;
        urls[num_urls].last_response_time = 0;
        num_urls++;
        token = strtok(NULL, " \n");
    }

    // Monitor URLs indefinitely
    while(1)
    {
        print_time();
        any_url_down = false;
        for(i = 0; i < num_urls; i++)
        {
            printf("Checking %s: ", urls[i].url);
            if(is_url_up(urls[i].url))
            {
                printf("UP\n");
                urls[i].is_up = true;
                urls[i].last_response_time = get_epoch_time();
            }
            else
            {
                printf("DOWN\n");
                urls[i].is_up = false;
            }
        }
        printf("\n");

        // Check if any URL is down for more than threshold time
        for(i = 0; i < num_urls; i++)
        {
            if(!urls[i].is_up)
            {
                current_time = get_epoch_time();
                if(current_time - urls[i].last_response_time > UPTIME_THRESHOLD)
                {
                    any_url_down = true;
                    printf("ALERT: %s has been down for more than %d seconds!\n\n", urls[i].url, UPTIME_THRESHOLD);
                }
            }
        }

        // Sleep for specified interval between checks
        sleep(INTERVAL_SECONDS);

        // Exit program if any URL is down for more than threshold time
        if(any_url_down)
        {
            exit(1);
        }
    }

    return 0;
}