//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
// Hello there geek, are you tired of constantly checking if your website is up and running? 
// Fear no more, because I am here to introduce you to the latest C Website Uptime Monitor! 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h> // Make sure to install libcurl library before compiling. 

int main(int argc, char* argv[]) {

    if(argc != 2) {
        printf("⚠️ Oops! Invalid Input! Please enter URL to monitor as argument.\n");
        exit(1); // Oops! looks like we have an error here. But do not worry, I will handle it. 
    }

    CURL *curl;
    CURLcode res;

    while(1) { // Let's start monitoring the website!

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
            res = curl_easy_perform(curl);

            if(res != CURLE_OK) { // Oh No! It seems our website is down. Shame on them. 
                printf("🛑 The website is down!\n");
                printf("Retrying in 10 seconds...\n");
                sleep(10); // Let's wait for a while and then retry again.
            } else { // Yay! The website is up and running
                printf("✅ The website is up!\n");
                break; // We got our answer, time to stop monitoring now. 
            }
            curl_easy_cleanup(curl);
        }
    }

    return 0; // That was easy, right? Thank me later!
}