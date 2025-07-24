//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define WEBSITE "https://www.google.com"

int main()
{
    CURL *curl;
    CURLcode res;
    int status;

    while(1)
    {
        curl = curl_easy_init();
        if(curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, WEBSITE);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

            res = curl_easy_perform(curl);
            if(res != CURLE_OK)
            {
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
                curl_easy_cleanup(curl);
                exit(EXIT_FAILURE);
            }
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
            if(status != 200)
            {
                fprintf(stderr, "%s is not available (HTTP status code %d)\n",
                    WEBSITE, status);
            }
            else
            {
                printf("%s is up (HTTP status code %d)\n", WEBSITE, status);
            }

            curl_easy_cleanup(curl);
        }
        sleep(60); // Check the website every minute
    }

    return 0;
}