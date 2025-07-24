//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define the target URL
#define URL "http://www.sherlockholmes.com/archive/"

// MAIN FUNCTION
int main(int argc, char *argv[]) 
{
    printf("The case of the missing data!\n\n");

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init(); // Initialize the libcurl library
    if(curl) {

        curl_easy_setopt(curl, CURLOPT_URL, URL); // Set the URL option
        
        // Set user agent string
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Sherlock/2.0");

        // Follow HTTP redirects if necessary
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Set timeout to 10 seconds
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        // Send all data to this function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);

        char *filename = "archive.html";
        FILE *fp = fopen(filename, "wb"); // Create file to store response data
        if (fp == NULL) {
            printf("Unknown error occurred. Could not save data.\n");
            return 1;
        }

        // Write response data to file
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Perform the request
        res = curl_easy_perform(curl);

        // Cleanup
        fclose(fp);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) { // Check for errors
            printf("Error occurred during curl request: %s\n", curl_easy_strerror(res));
        }

        printf("Data successfully retrieved and saved to %s\n", filename);
    }

    return 0;
}