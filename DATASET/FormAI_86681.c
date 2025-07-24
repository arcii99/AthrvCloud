//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    return size * nmemb; // Discard received data
}

int main(int argc, char *argv[])
{
    CURL *curl_handle = NULL;
    CURLcode res;
    double speed = 0.0;
    char url[] = "http://speedtest.net/speedtest/random350x350.jpg";
    long response_code = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    if (curl_handle)
    {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl_handle, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_LOW_SPEED_LIMIT, 1L);
        curl_easy_setopt(curl_handle, CURLOPT_LOW_SPEED_TIME, 5L);
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl_handle);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            res = curl_easy_getinfo(curl_handle, CURLINFO_SPEED_DOWNLOAD, &speed);
            if (res == CURLE_OK)
            {
                fprintf(stdout, "Download speed: %.2f bytes/sec\n", speed);
            }
            else
            {
                fprintf(stderr, "curl_easy_getinfo() failed: %s\n", curl_easy_strerror(res));
            }
        }

        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);
        if (response_code != 200)
        {
            fprintf(stderr, "Server returned HTTP error code %ld\n", response_code);
        }

        curl_easy_cleanup(curl_handle);
    }
    else
    {
        fprintf(stderr, "Could not initialize curl\n");
    }

    curl_global_cleanup();
    return 0;
}