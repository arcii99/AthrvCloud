//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_COUNT 1000

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    long size;
} File;

int compare_files(const void* a, const void* b)
{
    const File* file_a = (const File*) a;
    const File* file_b = (const File*) b;
    if (file_a->size < file_b->size) {
        return 1;
    } else if (file_a->size > file_b->size) {
        return -1;
    } else {
        return 0;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char* directory_name = argv[1];

    char command[MAX_FILENAME_LENGTH + 16];
    snprintf(command, sizeof(command), "du -a '%s' | sort -nr", directory_name);

    FILE* pipe = popen(command, "r");
    if (!pipe) {
        perror("popen failed");
        return 1;
    }

    File files[MAX_FILE_COUNT];
    int file_count = 0;
    char line[MAX_FILENAME_LENGTH + 32];
    while (file_count < MAX_FILE_COUNT && fgets(line, sizeof(line), pipe)) {
        char* size_end = strchr(line, '\t');
        if (!size_end) {
            continue;
        }
        *size_end = '\0';
        char* name_start = size_end + 1;
        char* name_end = strchr(name_start, '\n');
        if (name_end) {
            *name_end = '\0';
        }
        strncpy(files[file_count].name, name_start, sizeof(files[file_count].name));
        files[file_count].size = atol(line);
        ++file_count;
    }
    pclose(pipe);

    qsort(files, file_count, sizeof(File), compare_files);

    printf("Top 10 files in '%s' by size:\n", directory_name);
    for (int i = 0; i < 10 && i < file_count; ++i) {
        printf("%ld\t%s\n", files[i].size, files[i].name);
    }

    return 0;
}