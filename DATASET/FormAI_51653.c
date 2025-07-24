//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Please provide a filename!\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file!\n");
        return 1;
    }

    char metadata[100][100];
    int count = 0;

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Metadata:")) {
            char* ptr = strtok(line, " ");
            ptr = strtok(NULL, " ");
            while (ptr != NULL) {
                strcpy(metadata[count], ptr);
                count++;
                ptr = strtok(NULL, " ");
            }
        }
    }

    printf("Metadata:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", metadata[i]);
    }

    fclose(file);
    return 0;
}