//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFERSIZE 1024

int get_cpu_usage() {
    FILE* fp;
    char buffer[BUFFERSIZE];
    int user, nice, system, idle;

    fp = fopen("/proc/stat", "r");
    fgets(buffer, BUFFERSIZE, fp);
    fclose(fp);

    sscanf(buffer, "cpu %d %d %d %d", &user, &nice, &system, &idle);
    return (user + nice + system) * 100 / (user + nice + system + idle);
}

int main() {
    int usage = 0;

    while(1) {
        usage = get_cpu_usage();
        printf("CPU Usage: %d%%\n", usage);
        sleep(1);
    }

    return 0;
}