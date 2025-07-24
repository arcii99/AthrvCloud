//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

// Function to calculate time difference
double time_diff(struct timespec *start, struct timespec *end)
{
    double start_sec = (double)start->tv_sec*1000000000.0 + (double)start->tv_nsec;
    double end_sec = (double)end->tv_sec*1000000000.0 + (double)end->tv_nsec;
    if (end_sec < start_sec) {
        return 0;
    } else {
        return end_sec - start_sec;
    }
}

// Function to send HTTP GET request and return response time
double check_site(char *url)
{
    CURL *curl_handle;
    CURLcode res;
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "User-Agent: My amazing website monitor");

    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 10L);

    // Measure start time
    struct timespec start_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Perform request
    res = curl_easy_perform(curl_handle);

    // Measure end time
    struct timespec end_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calculate elapsed time
    double elapsed_time = time_diff(&start_time, &end_time);

    if (res == CURLE_OK) {
        long response_code;
        double total_time;
        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl_handle, CURLINFO_TOTAL_TIME, &total_time);
        printf("%s responded with a code %ld in %f seconds.\n", url, response_code, total_time);
        return total_time;
    } else {
        printf("Error checking website: %s\n", url);
        return -1;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s url1 [url2 ...]\n", argv[0]);
        exit(1);
    }

    // Loop through all URLs provided as arguments
    for (int i = 1; i < argc; i++) {
        char *url = argv[i];
        double response_time = check_site(url);
        if (response_time < 0) {
            printf("%s is down!\n", url);
        } else if (response_time > 2) {
            printf("%s is slow!\n", url);
        }
    }

    return 0;
}