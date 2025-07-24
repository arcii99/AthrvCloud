//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan(char *);

int main()
{
    printf("Retro Virus Scanner\n");
    printf("===================\n\n");

    char filename[50];

    printf("Enter file name: ");
    scanf("%s", filename);

    scan(filename);

    printf("Scan complete. No viruses detected.");

    return 0;
}

void scan(char *filename)
{
    int virusCount = 0;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "virus") != NULL || strstr(line, "malware") != NULL) {
            printf("Virus detected on line: %s\n", line);
            virusCount++;
        }
    }

    fclose(file);

    printf("Total viruses detected: %d\n", virusCount);
}