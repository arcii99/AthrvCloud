//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define API_KEY "your_api_key_here"

/* function to handle API response from the server */
size_t handle_response(char *buffer, size_t size, size_t nmemb, void *userp) {
    /* print the response */
    printf("%s", buffer);
    return size * nmemb;
}

int main(int argc, char **argv) {
    /* check if the user has entered a stock symbol */
    if(argc != 2) {
        printf("Please enter a stock symbol as argument!\n");
        return 1;
    }

    /* generate the URL to query the API */
    char *url = (char*) malloc(300 * sizeof(char));
    snprintf(url, 300, "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=%s&apikey=%s", argv[1], API_KEY);

    /* create a CURL object and set the URL and handle_response function */
    CURL *curl;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);

    /* execute the CURL request */
    CURLcode res = curl_easy_perform(curl);

    /* check if the request was successful */
    if(res != CURLE_OK) {
        printf("Error while querying the API: %s\n", curl_easy_strerror(res));
        return 1;
    }

    curl_easy_cleanup(curl);
    free(url);
    return 0;
}