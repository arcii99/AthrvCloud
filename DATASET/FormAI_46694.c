//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Function to perform the speed test
double performSpeedTest(void) {
    CURL *curlHandle;
    CURLcode res;
    double speed;

    // Initialize the curl library
    curl_global_init(CURL_GLOBAL_ALL);

    // Create a new curl session
    curlHandle = curl_easy_init();

    // Check if the curl session has been created successfully
    if (curlHandle != NULL) {
        // Set the URL to test the speed against
        curl_easy_setopt(curlHandle, CURLOPT_URL, "http://speedtest.net/");

        // Set the timeout for the request
        curl_easy_setopt(curlHandle, CURLOPT_TIMEOUT, 10L);

        // Perform the request and capture the time it took
        res = curl_easy_perform(curlHandle);
        if (res == CURLE_OK) {
            // Retrieve the speed in bytes per second
            curl_easy_getinfo(curlHandle, CURLINFO_SPEED_DOWNLOAD, &speed);
        }
        // Free the curl session
        curl_easy_cleanup(curlHandle);
    }

    // Cleanup the curl library
    curl_global_cleanup();

    // Convert the speed from bytes per second to megabits per second
    speed = (speed / (1024 * 1024)) * 8;

    return speed;
}

int main(void) {
    double speed;

    printf("Starting internet speed test...\n");

    // Perform the speed test
    speed = performSpeedTest();

    // Print the results
    if (speed > 10) {
        printf("Your internet speed is very fast at %.2f Mbps!\n", speed);
    } else if (speed > 5) {
        printf("Your internet speed is decent at %.2f Mbps.\n", speed);
    } else if (speed > 1) {
        printf("Your internet speed is slow at %.2f Mbps.\n", speed);
    } else {
        printf("Your internet speed is very slow at %.2f Mbps. Please consider upgrading your internet plan.\n", speed);
    }

    return 0;
}