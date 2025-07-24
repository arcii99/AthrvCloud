//FormAI DATASET v1.0 Category: System boot optimizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a given string is a number
bool isNumber(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        else
            return false;
    }
    return true;
}

int main() {
    char* bootTimeStr = getenv("BOOT_TIME");
    if (bootTimeStr == NULL) {
        printf("Error: BOOT_TIME environment variable not set\n");
        return 1;
    }

    int bootTime = atoi(bootTimeStr);

    // If the boot time is less than 30 seconds, nothing needs to be optimized
    if (bootTime < 30) {
        printf("Boot time is already optimized\n");
        return 0;
    }

    char* usersStr = getenv("USERS");
    if (usersStr == NULL) {
        printf("Error: USERS environment variable not set\n");
        return 1;
    }

    // Split the usersStr into an array of usernames
    char* userNames[20];
    char* pch;
    pch = strtok(usersStr, ",");
    int numUsers = 0;

    while (pch != NULL) {
        userNames[numUsers++] = pch;
        pch = strtok(NULL, ",");
    }

    // Check if there are more than 10 users
    if (numUsers > 10) {
        printf("More than 10 users found. Removing excess users..\n");
        numUsers = 10;
    }

    char* serviceName = getenv("SERVICE_NAME");
    if (serviceName == NULL) {
        printf("Error: SERVICE_NAME environment variable not set\n");
        return 1;
    }

    // Check if the service name is valid
    if (strcmp(serviceName, "sshd") != 0) {
        printf("Boot optimization only works for the sshd service. Aborting..\n");
        return 1;
    }

    char* sshdPortStr = getenv("SSHD_PORT");
    if (sshdPortStr == NULL) {
        printf("Error: SSHD_PORT environment variable not set\n");
        return 1;
    }

    // Check if the sshd port is valid
    if (!isNumber(sshdPortStr)) {
        printf("Error: Invalid SSHD_PORT number\n");
        return 1;
    }

    int sshdPort = atoi(sshdPortStr);

    printf("Boot optimization successful!\n");
    printf("Boot time: %d seconds\n", bootTime);
    printf("User names: ");
    for (int i = 0; i < numUsers; i++) {
        printf("%s ", userNames[i]);
    }
    printf("\n");
    printf("Service name: %s\n", serviceName);
    printf("SSHD port: %d\n", sshdPort);

    return 0;
}