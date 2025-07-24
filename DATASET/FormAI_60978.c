//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_URL_LENGTH 100

struct URL {
    char name[MAX_URL_LENGTH];
    bool is_up;
    time_t last_checked;
};

void check_url(struct URL *url) {
    int status = rand() % 2; // randomly generate status
    if (status == 0) {
        url->is_up = false;
    } else {
        url->is_up = true;
        url->last_checked = time(NULL);
    }
}

int main() {
    struct URL google = {"www.google.com", true, time(NULL)};
    struct URL yahoo = {"www.yahoo.com", true, time(NULL)};
    struct URL reddit = {"www.reddit.com", true, time(NULL)};
    
    printf("Starting website uptime monitor...\n");
    printf("------------------------------------\n");
    
    while (true) {
        check_url(&google);
        check_url(&yahoo);
        check_url(&reddit);
        
        printf("Status of %s: ", google.name);
        if (google.is_up) {
            printf("UP\n");
        } else {
            printf("DOWN\n");
        }
        
        printf("Status of %s: ", yahoo.name);
        if (yahoo.is_up) {
            printf("UP\n");
        } else {
            printf("DOWN\n");
        }
        
        printf("Status of %s: ", reddit.name);
        if (reddit.is_up) {
            printf("UP\n");
        } else {
            printf("DOWN\n");
        }
        
        printf("------------------------------------\n");
        sleep(10); // sleep for 10 seconds before checking again
    }
    
    return 0;
}