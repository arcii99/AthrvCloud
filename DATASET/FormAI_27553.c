//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

// function prototypes
void printSystemInfo();
void printRAMInfo();

int main() {

    // print system information
    printSystemInfo();

    // print RAM usage information every 5 seconds
    while(1) {
        system("clear");
        printRAMInfo();
        sleep(5);
    }

    return 0;
}

void printSystemInfo() {
    struct utsname unameData;
    if(uname(&unameData) != -1) {
        printf("System information:\n");
        printf("\tOperating system: %s\n", unameData.sysname);
        printf("\tNode name: %s\n", unameData.nodename);
        printf("\tRelease level: %s\n", unameData.release);
        printf("\tVersion information: %s\n", unameData.version);
        printf("\tMachine type: %s\n", unameData.machine);
    }
}

void printRAMInfo() {
    struct sysinfo RAMData;
    if(sysinfo(&RAMData) != -1) {
        printf("RAM usage information:\n");
        printf("\tTotal RAM: %ld\t\tFree RAM: %ld\n", RAMData.totalram / 1024, RAMData.freeram / 1024);
        printf("\tRAM usage: %f%%\n", ((float)RAMData.totalram - RAMData.freeram) / (float)RAMData.totalram * 100);
    }
}