//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_STRING_SIZE 100
    
// Define a structure to collect some system resource info
typedef struct SysInfo {
    int usedRAM;
    int totalRAM;
} SysInfo;

// Generate random data for testing purposes
void generateTestData() {
    int fd;
    fd = open("/dev/urandom", O_RDONLY);
    char buffer[MAX_STRING_SIZE];
    for(int i = 0; i < 1000; i++) {
        read(fd, buffer, MAX_STRING_SIZE - 1);
        printf("%s\n", buffer);
        usleep(1000);
    }
}

// Function that calculates the RAM usage
void getRAMUsage(SysInfo* sysInfo) {
    FILE* fp;
    char cmd[MAX_STRING_SIZE];
    int totalRAM, usedRAM;
    char unit[3]; // used to store the units used in the RAM values

    sprintf(cmd, "cat /proc/meminfo | grep Mem");
    fp = popen(cmd, "r");
    if(fp == NULL) {
        perror("Unable to open '/proc/meminfo'");
        return;
    }

    fscanf(fp, "%*s %d %s %*s", &totalRAM, unit);
    fscanf(fp, "%*s %d %s %*s", &usedRAM, unit);
    pclose(fp);

    sysInfo->usedRAM = usedRAM;
    sysInfo->totalRAM = totalRAM;
}

// Monitor the RAM usage
void monitorRAMUsage() {
    SysInfo sysInfo;
    while(1) {
        getRAMUsage(&sysInfo);
        printf("Used RAM: %d KB / Total RAM: %d KB\n", sysInfo.usedRAM, sysInfo.totalRAM);
        sleep(1);
    }
}

int main() {
    // Generate some test data
    generateTestData();

    // Monitor RAM usage
    monitorRAMUsage();

    return 0;
}