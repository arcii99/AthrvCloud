//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100];
    char virus_db[] = "virus_list.txt";
    char line[1024];
    int virus_found = 0;

    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }

    FILE* vp = fopen(virus_db, "r");
    if (vp == NULL) {
        printf("Error: Unable to open virus definition file!\n");
        fclose(fp);
        exit(1);
    }

    while (fgets(line, sizeof(line), vp)) {
        if (strstr(line, filename)) {
            virus_found = 1;
            break;
        }
    }

    fclose(vp);

    if (virus_found) {
        printf("Virus detected!\n");
    } else {
        printf("No viruses found.\n");
    }

    fclose(fp);

    return 0;
}