//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

typedef struct 
{
    char *website;
    long timeout;
} website_monitor;

size_t curl_write_func(void *data, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int check_website_status(website_monitor *monitor)
{
    CURL *curl_handle;
    CURLcode res;
    int status;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();
    if (curl_handle) 
    {
        curl_easy_setopt(curl_handle, CURLOPT_URL, monitor->website);
        curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT_MS, monitor->timeout);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, curl_write_func);

        res = curl_easy_perform(curl_handle);

        if (res == CURLE_OK)
        {
            curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &status);
        }
        else 
        {
            status = res;
        }

        curl_easy_cleanup(curl_handle);
    }
    else 
    {
        status = 1;
    }

    curl_global_cleanup();

    return status;
}

void monitor_websites(website_monitor *monitors, int monitor_count)
{
    int i, status;

    while (1) 
    {
        for (i = 0; i < monitor_count; i++) 
        {
            status = check_website_status(&monitors[i]);

            if (status == 200) 
            {
                printf("%s is up!\n", monitors[i].website);
            } 
            else 
            {
                printf("%s is down (error %d)!\n", monitors[i].website, status);
            }
        }

        sleep(5);
    }
}

int main(int argc, char const *argv[])
{
    website_monitor monitors[2] = {
        {"https://www.google.com", 3000},
        {"https://www.facebook.com", 3000},
    };

    monitor_websites(monitors, 2);

    return 0;
}