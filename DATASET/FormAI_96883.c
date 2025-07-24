//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    
    srand(time(NULL));
    
    char *urls[5] = {"www.googly.com", "www.yikes.net", "www.hilarious.edu", "www.jolly.co.uk", "www.crazy.org"};
    int status_codes[3] = {200, 400, 500};
    
    printf("Welcome to the website uptime monitor!\n");
    printf("We will randomly select a website and display its status code.\n");
    printf("If the status code is anything other than 200, the website is down.\n");
    printf("\n");
    
    while (true) {
        int index = rand() % 5;
        char *url = urls[index];
        int status_code = status_codes[rand() % 3];
        
        printf("Checking %s... Status Code: %d\n", url, status_code);
        
        if (status_code != 200) {
            printf("Uh-oh! The website is down!\n");
        }
        printf("\n");
        
        int wait_time = rand() % 6 + 5;
        printf("Waiting %d seconds...\n", wait_time);
        sleep(wait_time);
    }
    
    return 0;
}