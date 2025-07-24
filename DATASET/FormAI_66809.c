//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define NUM_WEBSITES 3
#define FAILURE_THRESHOLD 3

typedef struct {
    char* url;
    int failure_count;
    bool is_up;
} website_t;

website_t websites[NUM_WEBSITES] = {
    {"www.google.com", 0, true},
    {"www.apple.com", 0, true},
    {"www.github.com", 0, true}
};

void* ping_website(void* arg) {
    website_t* website = (website_t*) arg;
    while (true) {
        int status = system(website->url);
        if (status != 0) {
            website->failure_count++;
            if (website->failure_count >= FAILURE_THRESHOLD) {
                website->is_up = false;
                printf("Website %s is down!\n", website->url);
            }
        } else {
            website->failure_count = 0;
            if (!website->is_up) {
                website->is_up = true;
                printf("Website %s is back up!\n", website->url);
            }
        }
        sleep(5);
    }
}

int main(void) {
    pthread_t threads[NUM_WEBSITES];
    for (int i = 0; i < NUM_WEBSITES; i++) {
        pthread_create(&threads[i], NULL, ping_website, (void*) &websites[i]);
    }
    for (int i = 0; i < NUM_WEBSITES; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}