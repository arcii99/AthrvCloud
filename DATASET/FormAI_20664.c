//FormAI DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>", argv[0]);
        exit(1);
    }

    FILE* src = fopen(argv[1], "rb");
    if (src == NULL) {
        printf("Error opening source file.");
        exit(1);
    }

    FILE* dest = fopen(argv[2], "wb");
    if (dest == NULL) {
        printf("Error opening destination file.");
        fclose(src);
        exit(1);
    }

    char buffer[1024];
    size_t numread = 0;
    while ((numread = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, numread, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}