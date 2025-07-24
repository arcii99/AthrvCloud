//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return ERROR;
    }

    char* directory = argv[1];

    // Create the command to get the disk usage of the directory
    char* command = (char*) malloc(sizeof(char) * (strlen(directory) + 16));
    sprintf(command, "du -s %s", directory);

    // Execute the command and store the output in the variable output
    FILE* file = popen(command, "r");
    if (file == NULL) {
        printf("Error: Unable to execute command.\n");
        return ERROR;
    }

    char output[256];
    fgets(output, sizeof(output), file);

    // Parse the output to get the disk usage in kilobytes
    char* size_str = strtok(output, "\t");
    if (size_str == NULL) {
        printf("Error: Unable to parse output.\n");
        return ERROR;
    }

    int size_kb = atoi(size_str);

    // Print the disk usage in kilobytes and megabytes
    printf("Disk usage of %s:\n", directory);
    printf("%d KB\n", size_kb);
    printf("%.2f MB\n", size_kb / 1024.0);

    pclose(file);
    free(command);

    return 0;
}