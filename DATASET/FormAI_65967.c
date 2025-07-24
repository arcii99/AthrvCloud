//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
/* A Unique C Website Uptime Monitor */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define variables to hold website response time and status */
int response_time;
int status;

/* Define function to check website status */
void check_website_status(char *website_url) {
    /* Use system() function to ping website */
    char command[100] = "ping -c 1 ";
    strcat(command, website_url);
    int result = system(command);

    /* If website is not reachable, set status to 0 */
    if (result != 0) {
        status = 0;
        printf("Ah me! Can I not access %s?\n", website_url);
    }
    /* If website is reachable, set status to 1 and calculate response time */
    else {
        status = 1;
        clock_t start_time = clock();
        system(command);
        response_time = (int) (clock() - start_time) / CLOCKS_PER_SEC;
        printf("My love! %s responds in %d seconds!\n", website_url, response_time);
    }
}

int main() {
    /* Declare an array of website URLs to monitor */
    char *websites[] = {"www.google.com", "www.facebook.com", "www.twitter.com", "www.youtube.com"};
    
    /* Continuously check website status every 10 seconds */
    while(1) {
        for (int i = 0; i < 4; i++) {
            check_website_status(websites[i]);
        }
        printf("------------------------------\n");
        sleep(10);
    }
    return 0;
}