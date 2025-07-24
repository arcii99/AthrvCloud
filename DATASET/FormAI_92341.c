//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to process HTTP response
size_t write_callback(char *data, size_t size, size_t nmemb, void *userdata) {
    char *response = (char*) userdata;
    strcat(response, data);
    return size * nmemb;
}

// Function to check website availability
int check_website(char *site_url) {
    CURL *curl;
    CURLcode res;
    char response[1500] = "";
    long http_code = 0;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        res = curl_easy_perform(curl);

        // Check if request has completed successfully
        if(res != CURLE_OK) {
            curl_easy_cleanup(curl);
            return -1;
        }

        // Get HTTP response code
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        curl_easy_cleanup(curl);
    }

    // Check if website is up. HTTP response codes 200 - 399 indicate success.
    if(http_code >= 200 && http_code < 400) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char website_url[100] = "";
    int is_website_up = 0;

    // Get website URL from user input
    printf("Enter website URL (Example: https://www.example.com): ");
    fgets(website_url, 100, stdin);

    // Remove newline character at end of string
    website_url[strcspn(website_url, "\n")] = 0;

    // Check website availability
    is_website_up = check_website(website_url);

    // Display appropriate message based on availability
    if(is_website_up) {
        printf("\n%s is up and running!\n", website_url);
    } else {
        printf("\n%s is down. Please try again later.\n", website_url);
    }

    return 0;
}