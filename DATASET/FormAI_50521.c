//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int main() {
    int i = 0;
    char buffer[MAX_LEN];
    
    while(1) {
        sprintf(buffer, "cat /proc/%d/status | grep -e 'VmRSS'", getpid());
        FILE* fp = popen(buffer, "r");
        if(fp == NULL) {
            printf("Error: could not open process status file.\n");
            exit(EXIT_FAILURE);
        }
        
        char usage[MAX_LEN];
        fgets(usage, MAX_LEN, fp);
        pclose(fp);
        
        char* value_start = strchr(usage, ':') + 2;
        char* value_end = strchr(value_start, 'k');
        value_end[0] = '\0';
        int memory_usage = atoi(value_start);
        
        printf("\rRAM usage: ");
        for(i = 0; i < memory_usage / 10; i++) {
            printf("█");
        }
        for(; i < 50; i++) {
            printf("_");
        }
        fflush(stdout);
        
        sleep(1);
    }
    
    return 0;
}