//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[MAX_LENGTH];
    int line_number = 0;
    int virus_found = 0;

    while(fgets(line, MAX_LENGTH, fp)) {
        line_number++;

        if(strstr(line, "virus") != NULL || strstr(line, "malware") != NULL) {
            printf("Found virus on line %d: %s", line_number, line);
            virus_found = 1;
        }
    }

    if(!virus_found) {
        printf("No viruses found in file.\n");
    }

    fclose(fp);

    return 0;
}