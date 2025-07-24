//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to check if website is up or down
bool check_website_status(char* url) {
    // code to ping url and check response
    // return true if website is up, else false
}

// function to send email notification if website is down
void send_notification(char* email) {
    // code to send email to the provided email address
}

int main(int argc, char** argv) {
    // check if website URL is provided as program argument
    if (argc < 2) {
        printf("Error: Please provide website URL as argument.\n");
        exit(1);
    }

    char* website_url = argv[1];
    char* notification_email = NULL;

    // check if notification email is provided as optional argument
    if (argc == 3) {
        notification_email = argv[2];
    }

    while (true) {
        // check website status
        bool website_up = check_website_status(website_url);

        // if website is down, send notification
        if (!website_up && notification_email) {
            send_notification(notification_email);
        }

        // wait for 1 minute before checking again
        sleep(60);
    }

    return 0;
}