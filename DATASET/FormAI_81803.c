//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file_data {
    char name[256];
    int size;
    char *data;
};

int main(void) {
    printf("Enter file name: ");
    char filename[256];
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error reading file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(size);
    if (!data) {
        printf("Error allocating memory.\n");
        return 1;
    }

    fread(data, 1, size, file);

    printf("File contents: \n%s", data);

    fclose(file);
    free(data);

    return 0;
}