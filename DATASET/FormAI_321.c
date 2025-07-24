//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 256
#define MAX_LEVEL 10

typedef struct 
{
    int level;
    char name[MAX_PATH];
    float size;
} FileRecord;

int searchPath(char path[], FileRecord records[], int *recordCount, 
              int curLevel, int maxLevel);

int main()
{
    char path[MAX_PATH];
    printf("Enter directory path: ");
    fgets(path, MAX_PATH, stdin);

    // Remove trailing newline character
    path[strcspn(path, "\n")] = 0;

    FileRecord records[MAX_LEVEL];
    int recordCount = 0;

    int resultCode = searchPath(path, records, &recordCount, 0, MAX_LEVEL);

    if (resultCode == -1)
    {
        printf("Error: Could not read directory.\n");
        return 1;
    }
    else if (resultCode == -2)
    {
        printf("Error: Maximum directory level reached.\n");
        return 1;
    }

    // Print file records
    printf("\n%-30s | %8s\n", "Name", "Size (KB)");
    printf("--------------------------------+----------\n");
    for (int i = 0; i < recordCount; i++)
    {
        // Indent name based on level
        for (int j = 0; j < records[i].level; j++)
        {
            printf("   ");
        }

        printf("%-26s | %8.1f\n", records[i].name, records[i].size);
    }

    return 0;
}

/*
 * Recursive function to search path and record file sizes
 *
 * path: Absolute or relative directory path
 * records: Array to store file records
 * recordCount: Pointer to number of records in array
 * curLevel: Current directory level (root directory is 0)
 * maxLevel: Maximum directory level to search
 *
 * Returns: 0 if successful or an error code (-1 cannot read directory, -2 max level reached)
 */
int searchPath(char path[], FileRecord records[], int *recordCount, 
              int curLevel, int maxLevel)
{
    // Return if maximum level has been reached
    if (curLevel >= maxLevel)
    {
        return -2;
    }

    // Open directory
    FILE *dir = popen(path, "r");
    if (dir == NULL)
    {
        return -1;
    }

    char cmd[MAX_PATH + 10];
    sprintf(cmd, "du -k %s/*", path); // Command to get file sizes

    char line[MAX_PATH * 2];
    while (fgets(line, MAX_PATH * 2, dir) != NULL)
    {
        int len = strlen(line);

        // Ignore blank lines
        if (len <= 1)
        {
            continue;
        }

        // Get file size
        char sizeStr[MAX_PATH];
        for (int i = 0; i < len - 1; i++)
        {
            if (line[i] == '\t')
            {
                strncpy(sizeStr, &line[i+1], MAX_PATH);
                break;
            }
        }
        float size = atoi(sizeStr);

        // Get file name
        char name[MAX_PATH];
        strncpy(name, &line[curLevel * 2], MAX_PATH);

        // Remove trailing newline character
        name[strcspn(name, "\n")] = 0;

        // Add file record to array
        FileRecord record = {curLevel, name, size};
        records[(*recordCount)++] = record;

        // Recursively search subdirectories
        if (name[strlen(name) - 1] == '/')
        {
            searchPath(name, records, recordCount, curLevel + 1, maxLevel);
        }
    }

    // Close directory
    pclose(dir);

    return 0;
}