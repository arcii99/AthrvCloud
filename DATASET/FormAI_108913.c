//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define BUF_SIZE 1024

int main() {
    int pid = getpid();
    printf("PID: %d\n", pid);
    
    char cmd[BUF_SIZE];
    sprintf(cmd, "cat /proc/%d/status | grep VmRSS", pid);
    
    FILE *fp;
    char buf[BUF_SIZE];
    int rss;
    
    while (1) {
        fp = popen(cmd, "r");
        
        if (fp == NULL) {
            printf("Failed to run command\n");
            exit(1);
        }
        
        fgets(buf, BUF_SIZE, fp);
        pclose(fp);
        
        sscanf(buf, "VmRSS: %d kB", &rss);
        
        printf("Current RAM usage: %d kB\n", rss);
        sleep(1);
    }
    
    return 0;
}