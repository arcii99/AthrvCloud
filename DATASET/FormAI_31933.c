//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h> //need to install the curl library first

//function for performing the speed test
double perform_speed_test()
{
    CURL *curl;
    double speed;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://speedtest.net/");
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        CURLcode res = curl_easy_perform(curl);
        if(res == CURLE_OK)
        {
            double size;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &size);
            if(res == CURLE_OK && size > 0)
            {
                double time;
                res = curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time);
                if(res == CURLE_OK && time > 0)
                    speed = (size*8)/(time*1000000); //calculating speed in Mbps
            }
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return speed;
}

int main()
{
    double speed = perform_speed_test();
    if(speed != 0)
        printf("Your internet speed is: %.2f Mbps", speed);
    else
        printf("Internet speed test failed. Please try again.");
    return 0;
}