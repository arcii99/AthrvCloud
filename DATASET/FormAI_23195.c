//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char filename[50];
    char file_ext[10];
    int size;
} file_header;

int main() {
    FILE *fp;
    char buffer[1024];
    file_header header;
    int num_files, i, j, byte_count = 0;

    printf("Enter the number of files to recover: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("\nEnter the file name: ");
        scanf("%s", header.filename);
        printf("Enter the file extension: ");
        scanf("%s", header.file_ext);
        printf("Enter the file size (in bytes): ");
        scanf("%d", &header.size);

        fp = fopen(header.filename, "wb");
        if (fp == NULL) {
            printf("Error creating file %s.%s\n", header.filename, header.file_ext);
            continue;
        }

        fwrite(&header, sizeof(file_header), 1, fp);

        for (j = 0; j < header.size; j++) {
            fread(buffer, sizeof(char), 1, stdin);
            byte_count++;
            fwrite(buffer, sizeof(char), 1, fp);
        }

        printf("File %s.%s recovered successfully.\n", header.filename, header.file_ext);
        fclose(fp);
    }

    printf("\n%d bytes recovered in total.\n", byte_count);

    return 0;
}