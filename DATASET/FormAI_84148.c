//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

/**
 * This example program demonstrates how to build a HTTP client using libcurl in C.
 * It makes a GET request to a given URL and prints out the response body.
 *
 * To compile this program with gcc, use the command:
 *     gcc -o httpclient httpclient.c -lcurl
 */

/* This function will be called by libcurl when there is data to be written */
static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    /* userdata is a pointer to our response buffer */
    char *response = (char *)userdata;

    /* calculate the total size of the data */
    size_t total_size = size * nmemb;

    /* append the new data to our response */
    strncat(response, ptr, total_size);

    /* return the total size of the data */
    return total_size;
}

int main(int argc, char *argv[])
{
    /* check that we have a URL argument */
    if (argc != 2) {
        printf("Usage: %s URL\n", argv[0]);
        return 1;
    }

    /* initialize libcurl */
    curl_global_init(CURL_GLOBAL_ALL);

    /* create a curl handle */
    CURL *curl = curl_easy_init();

    /* set the URL to fetch */
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    /* set the write callback function */
    char response[4096] = { 0 };
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    /* perform the request */
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("Error: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 1;
    }

    /* print the response */
    printf("%s\n", response);

    /* cleanup */
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}