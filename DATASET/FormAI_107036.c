//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// function to check website uptime
int check_website(char *url) {
    CURL *curl;
    CURLcode res;
 
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        return (int)res;
    }
    return -1;
}

int main() {
    int status;
    char website_url[100];
    
    printf("Enter the URL of the website you want to monitor: ");
    scanf("%s", website_url);

    while(1) {
        status = check_website(website_url);

        if(status == 0) {
            printf("%s is UP\n", website_url);
        } 
        else {
            printf("%s is DOWN\n", website_url);
        }

        // sleep for 30 seconds
        sleep(30);
    }

    return 0;
}