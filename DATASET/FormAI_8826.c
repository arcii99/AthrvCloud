//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

int read_sys_file(const char *filename, char buffer[]) {
    FILE *fp;
    int length;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    length = fread(buffer, 1, BUFFER_SIZE, fp);
    buffer[length] = '\0';

    fclose(fp);

    return length;
}

int parse_meminfo(const char *buffer, int *total_mem, int *free_mem) {
    char *ptr;

    ptr = strstr(buffer, "MemTotal:");
    if (ptr == NULL) {
        return -1;
    }
    *total_mem = strtol(ptr + strlen("MemTotal:"), NULL, 10);

    ptr = strstr(buffer, "MemAvailable:");
    if (ptr == NULL) {
        return -1;
    }
    *free_mem = strtol(ptr + strlen("MemAvailable:"), NULL, 10);

    return 0;
}

int calc_percent(int total, int used) {
    return 100 * (total - used) / total;
}

int main() {
    char buffer[BUFFER_SIZE];
    int total_mem, free_mem, percent_used;
    const char *memory_file = "/proc/meminfo";

    while (1) {
        if (read_sys_file(memory_file, buffer) < 0) {
            print_error("Failed to read memory file /proc/meminfo");
        }

        if (parse_meminfo(buffer, &total_mem, &free_mem) < 0) {
            print_error("Failed to parse memory file /proc/meminfo");
        }

        percent_used = calc_percent(total_mem, free_mem);

        printf("RAM usage: %d%%\n", percent_used);

        sleep(1);
    }

    return 0;
}