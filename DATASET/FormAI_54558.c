//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: statistical
#include <stdio.h>
#include <string.h>

int main() {
    char virusDatabase[10][10] = {{"virus1"}, {"virus2"}, {"virus3"}, {"virus4"}, {"virus5"}, {"virus6"}, {"virus7"}, {"virus8"}, {"virus9"}, {"virus10"}};
    char scannedFile[100];
    int virusCount = 0;

    printf("Enter the name of the file to be scanned: ");
    scanf("%s", scannedFile);

    FILE *fp;
    fp = fopen(scannedFile, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strstr(line, virusDatabase[i])) {
                virusCount++;
                printf("Virus %d found: %s", virusCount, virusDatabase[i]);
            }
        }
    }

    if (virusCount == 0) {
        printf("No viruses found in file.\n");
    } else {
        printf("Total number of viruses found in file: %d", virusCount);
    }

    fclose(fp);
    return 0;
}