//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("C Antivirus Scanner\n");

    if(argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    int is_virus = 0;
    char buffer[1024];
    char signature[] = "evil_code";

    while(fgets(buffer, sizeof(buffer), fp)) {
        if(strstr(buffer, signature) != NULL) {
            is_virus = 1;
            break;
        }
    }

    fclose(fp);

    if(is_virus) {
        printf("Warning: Virus detected!\n");
        // Insert actions to take on virus detection
    } else {
        printf("No virus found.\n");
    }

    return 0;
}