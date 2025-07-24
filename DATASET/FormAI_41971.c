//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100

// function to check website status code
int getStatusCode(char *url) {
    char command[MAX_URL_LENGTH + 20];
    sprintf(command, "curl -I --silent %s | head -n 1 | cut -d ' ' -f 2", url);
    FILE *pipe = popen(command, "r");
    if (pipe) {
        char buffer[4];
        fgets(buffer, 4, pipe);
        pclose(pipe);
        return atoi(buffer);
    }
    return -1;
}

int main() {
    char url[MAX_URL_LENGTH];
    int timeInterval;
    int status = 0;

    // get user inputs
    printf("Enter the URL to monitor: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;
    printf("Enter time interval (seconds): ");
    scanf("%d", &timeInterval);

    while(1) {
        // check website status code
        status = getStatusCode(url);

        // print status message
        if (status == 200) {
            printf("%s is up and running!\n", url);
        } else {
            printf("%s is down. Status code: %d\n", url, status);
        }

        // wait for specified time interval
        sleep(timeInterval);
    }

    return 0;
}