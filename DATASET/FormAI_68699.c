//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_URLS 10
#define MAX_URL_LENGTH 100

int main()
{
    char urls[MAX_URLS][MAX_URL_LENGTH] = {"www.google.com", "www.facebook.com", "www.twitter.com", "www.linkedin.com", "www.youtube.com"};
    int num_urls = 5;

    bool urls_online[MAX_URLS] = {false};
    int offline_count = 0;

    printf("Website Uptime Monitor\n");

    while(true) {
        offline_count = 0;
        printf("Checking...\n");

        for (int i = 0; i < num_urls; i++) {
            char url_check[200];
            sprintf(url_check, "ping -c 1 %s > /dev/null", urls[i]);
            int return_code = system(url_check);

            if (return_code == 0) {
                if (!urls_online[i]) {
                    printf("%s is back online!\n", urls[i]);
                }
                urls_online[i] = true;
            }
            else {
                if (urls_online[i]) {
                    printf("ALERT: %s is offline!\n", urls[i]);
                }
                urls_online[i] = false;
                offline_count++;
            }
        }

        if (offline_count == num_urls) {
            printf("ALERT: All monitored websites are offline!\n");
        }

        sleep(60);
    }

    return 0;
}