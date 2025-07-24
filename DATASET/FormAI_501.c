//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 0;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("Error: Unable to open file %s\n", filename);
        return 0;
    }

    printf("Scanning file %s for viruses...\n", filename);

    char line[256];
    bool virusFound = false;
    while(fgets(line, sizeof(line), file)) {
        if(strstr(line, "malware")) {
            virusFound = true;
            printf("Virus found in line: %s", line);
            break;
        }
    }

    fclose(file);

    if(virusFound) {
        printf("Virus detected in file %s!\n", filename);
    } else {
        printf("File %s is virus-free!\n", filename);
    }

    return 0;
}