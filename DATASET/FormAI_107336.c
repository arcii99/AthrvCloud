//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>

int main(void) {

    CURL *client; // Initialize the client object
    CURLcode errorCode; // Store any potential errors that may occur

    client = curl_easy_init(); // Begin the session
    if (client) {

        // Set the URL we are going to be requesting
        curl_easy_setopt(client, CURLOPT_URL, "https://example.com");

        // Follow redirects if they're available
        curl_easy_setopt(client, CURLOPT_FOLLOWLOCATION, 1L);

        // Write the output from the request to stdout
        curl_easy_setopt(client, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(client, CURLOPT_WRITEDATA, stdout);

        // Perform the request
        errorCode = curl_easy_perform(client);

        if (errorCode != CURLE_OK) { // Something went wrong

            fprintf(stderr, "An error occurred: %s\n", curl_easy_strerror(errorCode));

        } else { // The request was successful

            printf("The request was successful!\n");

        }

        curl_easy_cleanup(client); // Clean up the client object
    }
    return 0;
}