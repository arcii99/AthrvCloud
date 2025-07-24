//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *token;
    const char *delimiter = ",";
    int line_num = 0;

    if(argc != 2) {
        printf("Usage: csvreader <csv file path>\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    while(fgets(line, MAX_LINE_LEN, fp) != NULL) {
        if(line_num == 0) {
            printf("Header: %s", line);
        } else {
            printf("Line %d:\n", line_num);

            token = strtok(line, delimiter);
            while(token != NULL) {
                printf(" - %s\n", token);
                token = strtok(NULL, delimiter);
            }
        }
        line_num++;
    }

    fclose(fp);

    return 0;
}