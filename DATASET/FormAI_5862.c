//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

/* Struct for storing website data */
typedef struct {
    char url[100];
    int is_up;
    time_t last_checked;
} Website;

/* Function to check website status */
int check_status(Website *site) {
    CURL *curl;
    CURLcode res;
    long http_code;

    curl = curl_easy_init();
    if(curl) {
        /* Set URL to check */
        curl_easy_setopt(curl, CURLOPT_URL, site->url);

        /* Disable output to console */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

        /* Execute request */
        res = curl_easy_perform(curl);

        /* Get HTTP response code */
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        /* Check if website is up */
        if(res == CURLE_OK && http_code == 200) {
            site->is_up = 1;
            printf("%s is up!\n", site->url);
        } else {
            site->is_up = 0;
            printf("%s is down!\n", site->url);
        }

        /* Save last checked time */
        site->last_checked = time(NULL);

        /* Clean up */
        curl_easy_cleanup(curl);

        return site->is_up;
    } else {
        /* Failed to initialize curl */
        printf("Failed to initialize curl for website: %s\n", site->url);
        return 0;
    }
}

int main() {
    Website sites[3];

    /* Initialize websites */
    strcpy(sites[0].url, "https://www.google.com");
    sites[0].is_up = 0;
    sites[0].last_checked = 0;

    strcpy(sites[1].url, "https://www.yahoo.com");
    sites[1].is_up = 0;
    sites[1].last_checked = 0;

    strcpy(sites[2].url, "https://www.facebook.com");
    sites[2].is_up = 0;
    sites[2].last_checked = 0;

    /* Check website status */
    int i;
    for(i = 0; i < 3; i++) {
        if(difftime(time(NULL), sites[i].last_checked) > 3600) {
            check_status(&sites[i]);
        }
    }

    return 0;
}