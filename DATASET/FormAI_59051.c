//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000

int scan_file(char *file_name) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return -1;
    }

    fread(buffer, MAX_FILE_SIZE, 1, fp);

    int virus_flag = 0;

    // check for virus signature
    if (strstr(buffer, "virus_signature") != NULL) {
        virus_flag = 1;
    }

    fclose(fp);

    return virus_flag;
}

int main() {
    char file_name[100];
    int virus_found;

    printf("Enter the name of the file to scan: ");
    gets(file_name);

    virus_found = scan_file(file_name);

    if (virus_found == 1) {
        printf("Virus found in file %s\n", file_name);
    } else {
        printf("No virus found in file %s\n", file_name);
    }

    return 0;
}