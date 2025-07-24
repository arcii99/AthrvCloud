//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

bool isWebsiteUp(char *url){
    FILE *fp;
    int status;
    char path[1024];

    // Curl command to check website status
    sprintf(path, "curl -s -o /dev/null -w '%%{http_code}' %s", url);

    // Execute the command
    fp = popen(path, "r");

    if (fp == NULL) {
        printf("Unable to execute the command\n");
        exit(1);
    }

    // Get the status code from the command output
    fscanf(fp, "%d", &status);

    // Close the pipe
    pclose(fp);

    // If status is less than 400, website is up
    if (status < 400) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char* url = "https://www.google.com";
    bool isUp = isWebsiteUp(url);
    if(isUp) {
        printf("%s is up!\n", url);
    } else {
        printf("%s is down :(\n", url);
    }
    // Wait for 60 seconds before checking again
    sleep(60);
    // Recursive call to main()
    main();
    return 0;
}