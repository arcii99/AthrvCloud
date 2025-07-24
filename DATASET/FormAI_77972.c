//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 1024
#define SECONDS_BETWEEN_CHECKS 60

int check_website(char *url) {
    char system_call[MAX_RESPONSE_LENGTH];
    snprintf(system_call, sizeof(system_call), "curl --url %s -o /dev/null -s -w '%%{http_code}'", url);
    FILE *output = popen(system_call, "r");
    if (output == NULL) {
        printf("Error opening pipe for curl command\n");
        return -1;
    }
    char response[MAX_RESPONSE_LENGTH];
    if (fgets(response, sizeof(response), output)) {
        int status_code = atoi(response);
        if (status_code >= 200 && status_code < 300) {
            return 0;
        } else {
            printf("%s returned %d status code\n", url, status_code);
            return 1;
        }
    } else {
        printf("No response from %s\n", url);
        return -1;
    }
    pclose(output);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s url\n", argv[0]);
        return 1;
    }
    char url[MAX_URL_LENGTH];
    snprintf(url, sizeof(url), "%s", argv[1]);

    while (1) {
        time_t now = time(NULL);
        printf("[%s] Checking %s...\n", ctime(&now), url);
        int status = check_website(url);
        if (status == -1) {
            // error occurred
            sleep(SECONDS_BETWEEN_CHECKS/2);
        } else {
            sleep(SECONDS_BETWEEN_CHECKS);
        }
    }
    return 0;
}