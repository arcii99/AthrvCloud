//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// This function will be passed to libcurl as a callback function for writing received data
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    // Write received data to a file
    FILE *file = (FILE *)userdata;
    size_t written = fwrite(ptr, size, nmemb, file);
    return written;
}

int main(int argc, char *argv[])
{
    // Check the number of arguments
    if (argc < 2) {
        printf("Usage: %s [url]\n", argv[0]);
        return -1;
    }

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_ALL);

    // Initialize a curl handle
    CURL *curl = curl_easy_init();

    // Set the URL to test
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Set the follow location option
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Set the write callback function and pass a file to save received data
    FILE *file = fopen("test_download_speed", "wb");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Perform the request and get the result code
    CURLcode result = curl_easy_perform(curl);

    // Get the download speed and print it to the console
    double speed = 0.0;
    curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
    printf("Download speed: %.2f bytes/sec\n", speed);

    // Clean up
    curl_easy_cleanup(curl);
    fclose(file);
    curl_global_cleanup();
    return 0;
}