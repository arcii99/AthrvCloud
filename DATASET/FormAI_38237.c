//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define URL_MAX_LENGTH 100
#define TIMEOUT 10

void check_website(const char* url) {
    char command[100];
    sprintf(command, "curl -Is -m %d %s >/dev/null", TIMEOUT, url);

    int response = system(command);
    if (WIFEXITED(response)) {
        if (WEXITSTATUS(response) == 0) {
            printf("%s is up!\n", url);
        } else {
            printf("%s is down!\n", url);
        }
    }
}

int main() {
    char urls[3][URL_MAX_LENGTH] = { "https://www.google.com", "https://www.github.com", "https://www.linkedin.com" };
    int i;

    for (i = 0; i < 3; i++) {
        check_website(urls[i]);
        sleep(2);
    }

    return EXIT_SUCCESS;
}