//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    // Define the websites to monitor and their corresponding URLs
    char website_names[3][20] = {"Google", "Facebook", "Twitter"};
    char website_urls[3][50] = {"https://www.google.com", "https://www.facebook.com", "https://www.twitter.com"};
    int num_websites = 3;

    // Define the desired interval between checks
    int check_interval = 30; //seconds
    
    // Sets up variables for monitoring
    time_t current_time;
    struct tm *time_info;
    char time_string[8];
    int website_status[3] = {0}; // 0 = Down and 1 = Up
    
    while(1) {
        for(int i=0; i<num_websites; i++) {
            // Use system command to ping the website using its URL
            char command[100];
            sprintf(command, "curl %s --max-time 15 >/dev/null 2>&1", website_urls[i]);
            int result = system(command);

            if(result == 0) {
                // Website is up
                if(website_status[i] == 0) { // website status changed from down to up
                    current_time = time(NULL);
                    time_info = localtime(&current_time);
                    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
                    printf("%s - %s is now up!\n", time_string, website_names[i]);
                    website_status[i] = 1;
                }
            } else {
                // Website is down
                if(website_status[i] == 1) { // website status changed from up to down
                    current_time = time(NULL);
                    time_info = localtime(&current_time);
                    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
                    printf("%s - %s is now down!\n", time_string, website_names[i]);
                    website_status[i] = 0;
                }
            }
        }
        // Wait for the specified interval before checking again
        sleep(check_interval);
    }

    return 0;
}