//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filepath[1000];
    printf("Enter the filepath to be scanned: ");
    scanf("%s", filepath);

    FILE *fp;
    fp = fopen(filepath, "r");

    if(fp == NULL) {
        printf("Could not open file.");
        exit(0);
    }

    char buffer[100];
    int virus_found = 0;
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        if(strstr(buffer, "virus")) {
            printf("Virus found!\n");
            virus_found = 1;
            break;
        }
    }
    fclose(fp);

    if(virus_found == 0) {
        printf("File is clean!\n");
    }

    return 0;
}