//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_CHARS 100

int main(int argc, char *argv[]) {

    FILE *file_ptr;
    char file_name[MAX_CHARS], line[MAX_CHARS];
    char metadata[MAX_LINES][MAX_CHARS];

    int index = 0;
    printf("Enter the file name to extract meta data: ");
    scanf("%s", file_name);

    file_ptr = fopen(file_name, "r");

    if (file_ptr != NULL) {
        while (fgets(line, sizeof(line), file_ptr) != NULL) {
            if (strstr(line, "//") != NULL) {
                strcpy(metadata[index], line);
                index++;
            }
        }
        fclose(file_ptr);

        printf("The meta data of this file is:\n");
        for (int i = 0; i < index; i++) {
            printf("%s", metadata[i]);
        }
    }
    else {
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}