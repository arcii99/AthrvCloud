//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char *argv[]) {

    CURL *curl_handle; /* Handle of CURL object */
    CURLcode curl_res; /* Result of curl operation */

    printf("Welcome to the HTTP HELPER :) \n");
    printf("Enter a URL to connect: ");
    char url[1000];
    fgets(url, 1000, stdin); /* Get the URL from user */

    /* Remove the newline character from the input */
    if ((strlen(url) > 0) && (url[strlen(url) - 1] == '\n'))
        url[strlen(url) - 1] = '\0';

    printf("Connecting to %s ...\n", url);
    curl_handle = curl_easy_init(); /* Initialize the CURL object */

    if (curl_handle) {

        /* Set the URL */
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);

        /* Set the callback function */
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, fwrite);

        /* Set the data to the output file */
        FILE *outfile = fopen("output.txt", "w");
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, outfile);

        /* Perform the HTTP request */
        curl_res = curl_easy_perform(curl_handle);
        if (curl_res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(curl_res));
        }

        /* Save the response code */
        long response_code;
        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);

        printf("Response code: %ld\n", response_code);

        /* Cleanup the CURL object */
        curl_easy_cleanup(curl_handle);
        fclose(outfile);
    }

    return 0;
}