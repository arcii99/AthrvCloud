//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_URL_LENGTH 100

int check_website(char* url) {
    // simulate website uptime check by generating random numbers
    return rand() % 2;
}

int main() {
    char websites[5][MAX_URL_LENGTH] = {"www.google.com", "www.yahoo.com", "www.github.com", "www.facebook.com", "www.twitter.com"};
    time_t t;
    srand((unsigned) time(&t)); // seed for random number generation
    printf("Retro Website Uptime Monitor\n\n");
    while(true) {
        for(int i=0; i<5; i++) {
            printf("Checking %s... ", websites[i]);
            if(check_website(websites[i])) {
                printf("Website is up!\n");
            } else {
                printf("Website is down!\n");
            }
        }
        printf("\n");
        // sleep for 5 seconds
        for(int i=0; i<5; i++) {
            printf(". ");
            fflush(stdout); // force output to be printed immediately
            // sleep for 1 second
            clock_t start_time = clock();
            while(clock() < start_time + CLOCKS_PER_SEC); // wait for 1 second
        }
        printf("\n\n");
    }
    return 0;
}