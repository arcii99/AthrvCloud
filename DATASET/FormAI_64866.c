//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

// function to scan the file for viruses
int scan_file(char *filename) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    int ret = 0;
    int len;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Couldn't open file: %s\n", filename);
        return -1;
    }

    len = fread(buffer, sizeof(char), MAX_FILE_SIZE, fp);
    buffer[len] = '\0';

    // scanning for the virus signature
    if(strstr(buffer, "virus_signature") != NULL) {
        printf("File %s is infected with a virus!\n", filename);
        ret = 1;
    }
    else {
        printf("File %s is clean.\n", filename);
        ret = 0;
    }

    fclose(fp);

    return ret;
}

int main(int argc, char *argv[]) {
    int i;

    if(argc < 2) {
        printf("Usage: %s <file1> [<file2> ...]\n", argv[0]);
        return -1;
    }

    for(i = 1; i < argc; i++) {
        scan_file(argv[i]);
    }

    return 0;
}