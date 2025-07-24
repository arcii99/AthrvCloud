//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check website status
bool checkWebsite(char* url) {
    char cmd[100] = "curl --silent --head ";
    strcat(cmd, url);
    strcat(cmd, " | grep HTTP");
    char result[1000];
    bool status = false;
    FILE* output = popen(cmd, "r");
    if (output != NULL) {
        fgets(result, sizeof(result), output);
        pclose(output);
    }
    if (strstr(result, "200 OK")) {
        status = true;
    }
    return status;
}

int main() {
    char url[100];
    printf("Enter website URL: ");
    scanf("%s", url);
    printf("\n");

    while (true) {
        bool status = checkWebsite(url);
        if (status) {
            printf("%s is UP!\n", url);
        } else {
            printf("%s is DOWN!\n", url);
        }
        printf("Checking again in 5 seconds...\n");
        sleep(5);
    }

    return 0;
}