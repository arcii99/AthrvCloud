//FormAI DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please provide a file name\n");
        return 1;
    }
    
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Unable to open file %s\n", filename);
        return 1;
    }
    
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        num_lines++;
        // do analysis on each line here
    }
    fclose(fp);
    
    printf("Total number of lines in file: %d\n", num_lines);
    return 0;
}