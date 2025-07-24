//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char virus[] = "BadVirus";
    int virusSize = strlen(virus);
    char filename[50];

    printf("Enter the filename to scan: ");
    scanf("%s", filename);
    
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    char content[500];
    char temp;

    int i = 0;
    while ((temp = fgetc(fp)) != EOF && i < 500) {
        content[i] = temp;
        i++;
    }
    content[i] = '\0';
    fclose(fp);

    for (int i = 0; i < strlen(content) - virusSize; i++) {
        int j;
        for (j = 0; j < virusSize; j++) {
            if (content[i + j] != virus[j]) {
                break;
            }
        }
        if (j == virusSize) {
            printf("This file is infected with the BadVirus! DO NOT EXECUTE!\n");
            return 0;
        }
    }

    printf("This file is clean and safe to execute!\n");
    return 0;
}