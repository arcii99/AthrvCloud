//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <arpa/inet.h>

#define FILENAME "/proc/meminfo"
#define MAX_LEN 1024

typedef struct sys_mem_info {
    long total_ram;
    long available_ram;
    long free_ram;
    long total_swap;
    long free_swap;
} sys_mem_info_t;

void parse_mem_info(char *buf, sys_mem_info_t *mem_info)
{
    char *line = strtok(buf, "\n");

    while (line != NULL) {
        if (strstr(line, "MemTotal:") != NULL) {
            mem_info->total_ram = strtol(line + strlen("MemTotal:"),
                    NULL, 10) / 1024;
        } else if (strstr(line, "MemAvailable:") != NULL) {
            mem_info->available_ram = strtol(line + strlen("MemAvailable:"),
                    NULL, 10) / 1024;
        } else if (strstr(line, "MemFree:") != NULL) {
            mem_info->free_ram = strtol(line + strlen("MemFree:"),
                    NULL, 10) / 1024;
        } else if (strstr(line, "SwapTotal:") != NULL) {
            mem_info->total_swap = strtol(line + strlen("SwapTotal:"),
                    NULL, 10) / 1024;
        } else if (strstr(line, "SwapFree:") != NULL) {
            mem_info->free_swap = strtol(line + strlen("SwapFree:"),
                    NULL, 10) / 1024;
        }

        line = strtok(NULL, "\n");
    }
}

void print_mem_info(sys_mem_info_t *mem_info)
{
    printf("Total RAM: %ld MB\n", mem_info->total_ram);
    printf("Free RAM: %ld MB\n", mem_info->free_ram);
    printf("Available RAM: %ld MB\n", mem_info->available_ram);
    printf("Total Swap: %ld MB\n", mem_info->total_swap);
    printf("Free Swap: %ld MB\n", mem_info->free_swap);
}

int main(int argc, char *argv[])
{
    int ch;
    int interval = 1; /* interval (in seconds) to refresh mem info */
    sys_mem_info_t mem_info = {0};
    char buf[MAX_LEN];
    struct utsname os_info;
    struct sysinfo si;

    while ((ch = getopt(argc, argv, "i:")) != -1) {
        switch (ch) {
            case 'i':
                interval = atoi(optarg);
                break;
            default:
                printf("Usage: %s [-i interval (in seconds)]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (uname(&os_info) < 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }
    
    printf("Operating System: %s %s %s\n", os_info.sysname,
            os_info.release, os_info.machine);

    while (1) {
        if (sysinfo(&si) < 0) {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }

        printf("Uptime: %ld seconds\n", si.uptime);
        printf("Load Average (1/5/15 min): %.2f %.2f %.2f\n", 
            (float) si.loads[0] / (1 << SI_LOAD_SHIFT),
            (float) si.loads[1] / (1 << SI_LOAD_SHIFT),
            (float) si.loads[2] / (1 << SI_LOAD_SHIFT));

        FILE *fp = fopen(FILENAME, "r");

        if (fp == NULL) {
            perror(FILENAME);
            exit(EXIT_FAILURE);
        }

        fgets(buf, MAX_LEN, fp);
        parse_mem_info(buf, &mem_info);
        fclose(fp);

        print_mem_info(&mem_info);

        memset(buf, 0, MAX_LEN);
        sleep(interval);
    }

    return 0;
}