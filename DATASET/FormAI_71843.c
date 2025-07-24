//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>

// This function will be called when the curl_easy_perform() fails
// and it will print the specific error message on the console.
static void error_message(CURLcode error)
{
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(error));
}

// This function will be called when we perform CURL HTTP request
// and it will return the HTTP response code
size_t http_response_code(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int *http_response = (int*) stream;
    curl_easy_getinfo((CURL*) ptr, CURLINFO_RESPONSE_CODE, http_response);
    return size * nmemb;
}

int main()
{
    // Websites URLs to be monitored, update this list with your own websites to monitor
    char *websites[] = {
        "https://www.google.com",
        "https://www.facebook.com",
        "https://github.com",
        "https://en.wikipedia.org/wiki/Main_Page"
    };

    int website_count = sizeof(websites)/sizeof(websites[0]);

    // Initialize CURL 
    CURL *curl_handle = curl_easy_init();

    if(curl_handle)
    {
        // Loop through each website and perform the CURL request
        for(int i=0; i<website_count; i++)
        {
            CURLcode curl_code;
            int http_response;

            // Set website URL
            curl_easy_setopt(curl_handle, CURLOPT_URL, websites[i]);

            // Set the http_response_code function to get http response code
            curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, http_response_code);

            // Pass pointer to http_response variable
            curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &http_response);

            // Perform the CURL HTTP request
            curl_code = curl_easy_perform(curl_handle);

            // Check if any error occured
            if(curl_code != CURLE_OK)
            {
                error_message(curl_code);
            }

            // Check if http response code is not 200
            if(http_response != 200)
            {
                printf("%s is DOWN with HTTP response code %d\n", websites[i], http_response);
            }
            else
            {
                printf("%s is UP and RUNNING!\n", websites[i]);
            }
        }

        // Cleanup CURL handle
        curl_easy_cleanup(curl_handle);
    }
    else
    {
        printf("Could not initialize CURL\n");
    }

    return 0;
}