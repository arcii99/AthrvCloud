//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

/* Write data callback */
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    double speed, time;
    char speed_unit[3], response_time_unit[3];

    /* Initialize curl */
    curl = curl_easy_init();

    if(curl)
    {
        /* Set URL to google.com */
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");

        /* Set write callback */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        /* Set timeout to 10 seconds */
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        /* Perform the request */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        }
        else
        {
            /* Get transfer speed information */
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
            curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time);

            /* Determine speed unit */
            if(speed >= 1000000) 
            {
                speed /= 1000000;
                sprintf(speed_unit, "%s", "MB/s");
            }
            else if(speed >= 1000)
            {
                speed /= 1000;
                sprintf(speed_unit, "%s", "KB/s");
            }
            else 
            {
                sprintf(speed_unit, "%s", "B/s");
            }

            /* Determine response time unit */
            if(time >= 1000) 
            {
                time /= 1000;
                sprintf(response_time_unit, "%s", "s");
            }
            else 
            {
                sprintf(response_time_unit, "%s", "ms");
            }

            /* Print results */
            printf("Transfer Speed: %0.2f %s\n", speed, speed_unit);
            printf("Response Time: %0.2f %s\n", time, response_time_unit);
        }

        /* Clean up */
        curl_easy_cleanup(curl);
    }

    return 0;
}