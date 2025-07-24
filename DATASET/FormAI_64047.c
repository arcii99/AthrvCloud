//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
    char fileName[50];
    printf("Enter the name of the file to scan: ");
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");

    if (!file) {
        printf("File not found\n");
        return 1;
    }

    char virus[100] = "malware";
    char line[1000];
    int virusFound = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, virus)) {
            virusFound = 1;
            break;
        }
    }

    if (virusFound) {
        printf("Virus found in file!\n");
    } else {
        printf("File is clean\n");
    }

    fclose(file);
    return 0;
}