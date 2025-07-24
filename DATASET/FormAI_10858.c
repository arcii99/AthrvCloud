//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanFile(char *filename);

int main() {
    char *filename = malloc(sizeof(char) * 50);
    printf("Please enter the filename: \n");
    scanf("%s", filename);
    scanFile(filename);

    return 0;
}

void scanFile(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found\n");
        return;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int virusCount = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == 'c' && line[i + 1] == 'o' && line[i + 2] == 'v' && line[i + 3] == 'i' && line[i + 4] == 'd') {
                virusCount++;
                printf("Virus detected on line %d: %s", virusCount, line);
                break;
            }
        }
    }

    fclose(file);

    printf("\nScan complete. %d virus(es) found.\n", virusCount);
}