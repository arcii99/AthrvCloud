//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>

// function to check website status
int check_website_status(char* url) {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res == CURLE_OK)
            return 1; // website is up
        else
            return 0; // website is down
    }
    return -1; // error occurred
}

// function to send alert email
void send_alert_email(char* recipient, char* website) {
    // implementation of sending alert email
    printf("An alert email has been sent to %s! The website %s is down.\n", recipient, website);
}

int main() {
    char* website_url = "http://www.example.com";
    char* recipient_email = "admin@example.com";
    int status = check_website_status(website_url);
    if(status == 0) {
        send_alert_email(recipient_email, website_url);
    }
    return 0;
}