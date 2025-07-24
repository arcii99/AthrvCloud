//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<unistd.h>

// Function to check website status
int check_website_status(char* url){
    CURL *curl;
    CURLcode res;
    long response_code;
    
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only want the status code
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return -1;
        }
        
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code); // Get the status code
        
        curl_easy_cleanup(curl);        
    }
    
    return (int)response_code;
}

// Function to display website status
void display_website_status(int status, char* url){
    switch(status){
        case 200:
            printf("The website %s is up and running smoothly\n", url);
            break;
        case 0:
            printf("The website %s could not be resolved\n", url);
            break;
        default:
            printf("The website %s returned a status code of %d\n", url, status);
            break;
    }
}

int main(){
    char* urls[3] = {"https://www.google.com", "https://www.facebook.com", "https://www.github.com"};
    
    while(1){
        for(int i=0; i<3; i++){
            int status = check_website_status(urls[i]);
            display_website_status(status, urls[i]);
        }
        sleep(60); // Check again after a minute
    }
    
    return 0;
}