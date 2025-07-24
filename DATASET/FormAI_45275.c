//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char fileName[100];
    char virusDB[5][16] = {"start", "detect", "remove", "block", "alert"};
    char virus[16];
    int i, j, k, n, infectedCount = 0;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file!");
        return 0;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        n = strlen(line);
        if (line[n-1] == '\n') {
            line[n-1] = '\0';
        }

        for (i = 0; i < 5; i++) {
            strcpy(virus, virusDB[i]);
            if (strstr(line, virus) != NULL) {
                printf("Virus found: %s\n", virus);
                infectedCount++;
            }
        }
    }

    if (infectedCount > 0) {
        printf("File is infected with %d viruses!\n", infectedCount);
    } else {
        printf("File is safe!\n");
    }

    fclose(file);

    return 0;
}