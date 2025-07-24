//FormAI DATASET v1.0 Category: File Synchronizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 512
#define MAX_FILE_CONTENT_LEN 65535

int synchronize_files(char *filename1, char *filename2);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [file1] [file2]\n", argv[0]);
        exit(1);
    }

    char *filename1 = argv[1];
    char *filename2 = argv[2];

    int result = synchronize_files(filename1, filename2);

    if (result == 0) {
        printf("Files synchronized successfully!\n");
    } else if (result == 1) {
        printf("Could not open file '%s'.\n", filename1);
    } else if (result == 2) {
        printf("Could not open file '%s'.\n", filename2);
    } else {
        printf("An error occurred while synchronizing files.\n");
    }

    return 0;
}

int synchronize_files(char *filename1, char *filename2) {
    FILE *file1 = fopen(filename1, "r");
    if (file1 == NULL) {
        return 1;
    }

    FILE *file2 = fopen(filename2, "r");
    if (file2 == NULL) {
        fclose(file1);
        return 2;
    }

    char file1_content[MAX_FILE_CONTENT_LEN];
    char file2_content[MAX_FILE_CONTENT_LEN];

    memset(file1_content, 0, sizeof(file1_content));
    memset(file2_content, 0, sizeof(file2_content));

    size_t file1_len = fread(file1_content, sizeof(char), MAX_FILE_CONTENT_LEN, file1);
    size_t file2_len = fread(file2_content, sizeof(char), MAX_FILE_CONTENT_LEN, file2);

    fclose(file1);
    fclose(file2);

    if (file1_len != file2_len || strcmp(file1_content, file2_content) != 0) {
        FILE *file1 = fopen(filename1, "w");
        if (file1 == NULL) {
            return 1;
        }

        FILE *file2 = fopen(filename2, "w");
        if (file2 == NULL) {
            fclose(file1);
            return 2;
        }

        fwrite(file1_content, sizeof(char), file1_len, file1);
        fwrite(file2_content, sizeof(char), file2_len, file2);

        fclose(file1);
        fclose(file2);

        return 0;
    }

    return 0;
}