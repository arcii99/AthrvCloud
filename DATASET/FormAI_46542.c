//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#define MAX_LINE_LENGTH 256

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int num_lines = 0, num_errors = 0;

    fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;   
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {  
        num_lines++;
        if (strstr(line, "ERROR") != NULL) {
            num_errors++;
            printf("ERROR found at line %d: %s", num_lines, line);
        }
    }

    printf("Total number of lines read: %d\n", num_lines);
    printf("Total number of errors found: %d\n", num_errors);
    fclose(fp);
    return 0;
}