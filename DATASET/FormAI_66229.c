//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: beginner-friendly
#include<stdio.h>
#include<curl/curl.h>  // For making HTTP requests
#include<unistd.h>    // For sleep function
#include<stdlib.h>   

// function to check URL availability
int check_url(char *url){
   
    CURL *curl = curl_easy_init();  // Initializing curl session
    CURLcode response; 
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // HTTP HEAD request, not downloading anything
        response = curl_easy_perform(curl);
        if(response == CURLE_OK)
        {
            curl_easy_cleanup(curl);
            return 1;
        }
        curl_easy_cleanup(curl);
        return 0;
    }
    return -1;
}

int main(){
    char url[100];
    printf("Enter the URL to monitor: ");
    scanf("%s", url);
    while(1){
        int status = check_url(url);
        if(status){
            printf("Website is up and running!\n");
        }else{
            printf("Website is down!\n");
        }
        sleep(30); // sleep for 30 seconds
    }
    return 0;
}