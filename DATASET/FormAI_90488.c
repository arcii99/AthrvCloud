//FormAI DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char filename[MAX_SIZE];
    int size;
} file;

void recover_data(char* filename, int size) {
    FILE *fp;

    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }

    unsigned char *data = (unsigned char*) malloc(size);
    fread(data, sizeof(unsigned char), size, fp);

    printf("Recovered data: %s\n", data);

    free(data);
    fclose(fp);
}

int main() {
    file files[2];

    strcpy(files[0].filename, "file1.txt");
    files[0].size = 10;

    strcpy(files[1].filename, "file2.txt");
    files[1].size = 8;

    for (int i = 0; i < 2; i++) {
        printf("Recovering data from %s...\n", files[i].filename);
        recover_data(files[i].filename, files[i].size);
    }

    return 0;
}