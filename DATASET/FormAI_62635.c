//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>

// Global variables 
char *m_url = ""; // URL for monitoring
int m_interval = 30; // Interval between checks
int m_timeout = 5; // Timeout for the request
int m_max_fails = 3; // Maximum allowed failed requests
int m_consecutive_fails = 0; // Consecutive failed requests counter

// Function to handle request
static size_t handle_request(void *buffer, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

// Function to check the URL
void check_url()
{
    CURL *curl = curl_easy_init();
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, m_url);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, m_timeout);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_request);
    
        CURLcode result = curl_easy_perform(curl);
        
        if(result != CURLE_OK)
        {   
            // Failed request
            m_consecutive_fails++;
            if(m_consecutive_fails >= m_max_fails)
            {
                // Alert message
                printf("Website is down: %s\n", m_url);
                m_consecutive_fails = 0;
            }
        }
        else
        {
            // Successful request
            m_consecutive_fails = 0;
        }
        
        curl_easy_cleanup(curl);
    }
}

// Main function to run the monitor
int main()
{
    while(1)
    {
        check_url();
        sleep(m_interval);
    }
    
    return 0;
}