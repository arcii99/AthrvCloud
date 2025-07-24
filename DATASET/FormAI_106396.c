//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int virus_check(char *str) {
    char signature[] = "VIRUSSIG";
    int len = strlen(signature);
    int i, j;

    for (i = 0; i < strlen(str); i++) {
        for (j = 0; j < len; j++) {
            //check for match between str and signature
            if (str[i+j] != signature[j]) {
                break;
            }
        }
        if (j == len) {
            printf("WARNING! Virus Found!\n");
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *fp;
    char filename[100];
    char buffer[1000];

    printf("Enter file name:\n");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found!");
        exit(1);
    }

    while(fgets(buffer, 1000, fp)) {
        virus_check(buffer);
    }

    printf("Antivirus scan complete. No viruses found.\n");

    fclose(fp);
    return 0;
}