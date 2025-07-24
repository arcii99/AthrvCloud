//FormAI DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Super Awesome File Backup System!\n");

    char source[100];
    char destination[100];

    printf("\nEnter the name of the source file: ");
    scanf("%s", source);

    printf("\nEnter the name of the destination file: ");
    scanf("%s", destination);

    FILE *src_file = fopen(source, "rb");
    FILE *dst_file = fopen(destination, "wb");

    if (src_file == NULL || dst_file == NULL) {
        printf("\nError: Could not open file.\n");
        exit(1);
    }

    char buffer[1024];
    size_t num_read;

    while ((num_read = fread(buffer, 1, 1024, src_file))) {
        fwrite(buffer, 1, num_read, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    printf("\nSuccess: File backup created!\n");

    return 0;
}