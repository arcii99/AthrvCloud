//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char fileName[50];
    int fileSize;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("File not found!\n");
        return 0;
    }

    fseek(file, 0L, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0L, SEEK_SET);

    char fileContent[fileSize];
    fread(fileContent, sizeof(char), fileSize, file);

    int virusDetected = 0;

    char virusStrings[5][20] = {
        "hack",
        "crack",
        "cyber",
        "virus",
        "trojan"
    };

    for (int i = 0; i < 5; i++) {
        if (strstr(fileContent, virusStrings[i]) != NULL) {
            printf("Virus detected: %s\n", virusStrings[i]);
            virusDetected = 1;
        }
    }

    if (virusDetected == 0) {
        printf("No viruses detected.\n");
    }

    fclose(file);

    return 0;
}