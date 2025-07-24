//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 256

int main(){
    FILE* fp;
    char path[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    char* ptr;

    int total, free;

    while(1){
        fp = fopen("/proc/meminfo", "r");
        if(fp == NULL){
            printf("Failed to open meminfo file\n");
            exit(1);
        }

        while(fgets(line, BUFFER_SIZE, fp)){
            if(strncmp(line, "MemTotal:", 9) == 0){
                ptr = line + 9;
                total = atoi(ptr);
            }

            if(strncmp(line, "MemFree:", 8) == 0){
                ptr = line + 8;
                free = atoi(ptr);
            }
        }

        fclose(fp);

        float usage = (total - free) * 1.0 / total;
        printf("Current RAM usage: %.2f%%\n", usage * 100);

        sleep(1);
    }

    return 0;
}