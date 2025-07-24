//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF 256

int main(int argc, char* argv[]) {
    char buf[MAX_BUF];
    char* cmd = "cat /proc/meminfo | grep \"MemAvailable\" | awk '{print $2/1024}'";
    FILE* pipe = popen(cmd, "r");
    double available_mem;
    fgets(buf, MAX_BUF, pipe);
    available_mem = atof(buf);
    printf("Available memory: %5.2f MB\n", available_mem);
    pclose(pipe);
    return 0;
}