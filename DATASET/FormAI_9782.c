//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <stdbool.h>

#define MAX_URL_LEN 1000
#define MAX_EMAIL_LEN 1000

char url[MAX_URL_LEN];
char email[MAX_EMAIL_LEN];

/* function to check website availability */
int check_website(char* url) {
    CURLcode res;
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            curl_easy_cleanup(curl);
            return 0;
        }
        long response_code;
        res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_cleanup(curl);
        if(res == CURLE_OK && response_code == 200) {
            return 1;
        }
    }
    return 0;
}

/* function to send email notification */
void send_email(char* email, char* url) {
    printf("Email sent to %s: Website %s is down!\n", email, url);
}

/* main function */
int main() {
    // retrieve user input for website url and email
    printf("Enter website url to monitor: ");
    fgets(url, MAX_URL_LEN, stdin);
    printf("Enter email to receive notifications: ");
    fgets(email, MAX_EMAIL_LEN, stdin);

    // remove new line character from user input
    url[strcspn(url, "\n")] = 0;
    email[strcspn(email, "\n")] = 0;

    // set initial website status to up
    int is_down = 0;
    while (true) {
        // check website status
        int is_up = check_website(url);
        if (!is_up && !is_down) {
            // website just went down
            send_email(email, url);
            is_down = 1;
        } else if (is_up && is_down) {
            // website just came back up
            is_down = 0;
        }
        // sleep for 30 seconds before checking again
        sleep(30);
    }
    return 0;
}