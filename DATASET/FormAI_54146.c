//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include<stdio.h>
#include<time.h>
#include<curl/curl.h>

int main()
{
    CURL *curl;
    CURLcode res;
    double time_spent;
    struct timespec start, end;

    curl = curl_easy_init();
    clock_gettime(CLOCK_REALTIME, &start);

    curl_easy_setopt(curl, CURLOPT_URL, "https://speedtest.net");
    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
    {
        printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } 
    else 
    {
        printf("\n\nYour internet speed is good!\n\n");
    }

    curl_easy_cleanup(curl);
    clock_gettime(CLOCK_REALTIME, &end);

    time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("\n\nTime elapsed is %f seconds", time_spent);

    return 0;
}