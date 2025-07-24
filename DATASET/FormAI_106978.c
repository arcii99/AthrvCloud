//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)

void analyze_disk_space(char* path);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s [PATH]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    analyze_disk_space(argv[1]);

    return EXIT_SUCCESS;
}

void analyze_disk_space(char* path) {
    printf("Analyzing disk space for %s...\n", path);

    FILE* fp = popen("du -sm ", "r");
    if (fp == NULL) {
        printf("Failed to run 'du' command.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    unsigned long total_size = 0, file_size;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%lu", &file_size);
        total_size += file_size * MB;
    }
    pclose(fp);

    printf("Total disk space used by %s: ", path);
    if (total_size > GB) {
        printf("%.2f GB\n", (double)total_size / GB);
    } else if (total_size > MB) {
        printf("%.2f MB\n", (double)total_size / MB);
    } else {
        printf("%lu KB\n", total_size / KB);
    }
}