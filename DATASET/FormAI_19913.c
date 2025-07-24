//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<time.h>

//function to check website status
int websiteStatusCheck(char *url){
    CURL *curl;
    CURLcode res;

    //initialize curl
    curl = curl_easy_init();

    //set url
    curl_easy_setopt(curl, CURLOPT_URL, url);

    //perform request
    res = curl_easy_perform(curl);

    //cleanup curl
    curl_easy_cleanup(curl);

    return res;
}

int main(){
    //start time
    time_t startTime = time(NULL);

    //website urls to check
    char websites[3][50] = {"https://google.com", "https://youtube.com", "https://facebook.com"};

    printf("Starting website uptime monitoring...\n");

    while(1){
        //check website status and print status message
        printf("\n%s:\t", websites[0]);
        if(websiteStatusCheck(websites[0]) == CURLE_OK){
            printf("Site is up and running!");
        }else{
            printf("Site is down!");
        }
        printf("\n%s:\t", websites[1]);
        if(websiteStatusCheck(websites[1]) == CURLE_OK){
            printf("Site is up and running!");
        }else{
            printf("Site is down!");
        }
        printf("\n%s:\t", websites[2]);
        if(websiteStatusCheck(websites[2]) == CURLE_OK){
            printf("Site is up and running!");
        }else{
            printf("Site is down!");
        }

        //delay to check website status once every 30 seconds
        sleep(30);

        //check total uptime duration and print message
        time_t currentTime = time(NULL);
        double uptimeDuration = difftime(currentTime, startTime);
        printf("\n\nWebsite uptime duration: %.0lf seconds\n", uptimeDuration);
    }

    return 0;
}