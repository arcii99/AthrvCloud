//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

int main(void) 
{
    CURL *curl;
    CURLcode res;
    char url[] = "https://www.example.com"; // replace with your website url
    long response_code;
    double total_time;

    curl = curl_easy_init();
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) 
        {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &total_time);
            printf("Website: %s\n", url);
            printf("Status code: %ld\n", response_code);
            printf("Total time: %f seconds\n", total_time);
            // check if response code is 200 (OK)
            if(response_code == 200)
            {
                printf("Website is up and running!\n");
            }
            else
            {
                printf("Website is unavailable!\n");
            }
        }
        else
        {
            printf("Failed to connect to website: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}