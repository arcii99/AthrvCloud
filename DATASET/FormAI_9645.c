//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

struct DirEntry
{
    char name[256];
    long size;
};

int main(int argc, char **argv)
{
    struct DirEntry *entries;
    int n_entries = 0;

    if (argc < 2)
    {
        printf("usage: %s <dir_to_analyze>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dir_path = argv[1];
    printf("Analyzing directory '%s'...\n", dir_path);

    // TODO: implement code to recursively traverse the directory 
    // and collect necessary information to populate entries array

    // File Size Rounding for display
    void roundSize(int mult, long *size) {
        if ((*size)%mult == 0) {
            *size /= mult;
        } else {
            *size = (*size / mult) + 1;
        }
    }

    // Display
    printf("\n");

    printf("|%-40s | |%20s |\n", "Filename", "Size");
    printf("|%-40s-|-|%20s-|\n", "----------------------------------------", "--------------------");
    for (int i = 0; i < n_entries; i++)
    {
        // Round size for display
        if (entries[i].size > GB) {
            roundSize(GB, &entries[i].size);
            printf("| %38s | |%20ld GB |\n", entries[i].name, entries[i].size);
        }
        else if (entries[i].size > MB) {
            roundSize(MB, &entries[i].size);
            printf("| %38s | |%20ld MB |\n", entries[i].name, entries[i].size);
        } 
        else if (entries[i].size > KB) {
            roundSize(KB, &entries[i].size);
            printf("| %38s | |%20ld KB |\n", entries[i].name, entries[i].size);
        } else {
            printf("| %38s | |%20ld B  |\n", entries[i].name, entries[i].size);
        }
    }

    printf("\n%d directory entries in total.\n", n_entries);

    free(entries);
    return 0;
}