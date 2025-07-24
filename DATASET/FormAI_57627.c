//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>

//function to check website status
int check_website(char *url){
    CURL *curl;
    CURLcode res;
    int response_code;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK){
            return -1;
        }
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return response_code;
}

int main(void){
    int status;
    char *url = "www.google.com";

    status = check_website(url);

    if (status == 200){
        printf("Website is up and running.\n");
    }
    else {
        printf("Website is down.\n");
    }

    return 0;
}