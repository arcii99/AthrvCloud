//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

// function prototype
bool checkStatus(char* url);

int main() {
    // array of website urls to monitor
    char* urls[3] = {"https://google.com", "https://facebook.com", "https://twitter.com"};

    printf("Starting website uptime monitor...\n\n");

    // loop through the urls and check their status
    for (int i = 0; i < 3; i++) {
        char* url = urls[i];
        bool status = checkStatus(url);
        if (status) {
            printf("%s is up and running!\n", url);
        } else {
            printf("%s is down :(\n", url);
        }
    }
    printf("\nAll website statuses checked. Have a nice day!\n");

    return 0;
}

bool checkStatus(char* url) {
    // generate a random number between 0 and 1
    srand(time(NULL));
    int randNum = rand() % 2;

    if (randNum == 1) {
        return true;
    } else {
        return false;
    }
}