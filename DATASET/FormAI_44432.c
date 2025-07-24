//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <time.h>
#include <curl/curl.h>

#define TEST_SIZE 1048576
#define TEST_URL "http://www.speedtest.net/1MB.dat"

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *stream)
{
    return size * nmemb;
}

int main(void)
{
    double ellapsed_time;
    CURL *curl_handle;
    CURLcode res;
    time_t start_time, end_time;
    unsigned char test_data[TEST_SIZE];

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, TEST_URL);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);

        time(&start_time);
        res = curl_easy_perform(curl_handle);
        time(&end_time);
        ellapsed_time = difftime(end_time, start_time);

        if(res == CURLE_OK) {
            printf("Download speed: %.2fMbps\n", (double) TEST_SIZE / 1000000.0 / ellapsed_time);
        }
        else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl_handle);
    }

    curl_global_cleanup();
    return 0;
}