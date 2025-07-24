//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100];
    char line[1024];
    
    printf("Enter CSV filename: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    // Read header line and print to console
    fgets(line, 1024, fp);
    printf("Header: %s", line);
    
    // Read remaining lines and print data to console
    while (fgets(line, 1024, fp)) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}