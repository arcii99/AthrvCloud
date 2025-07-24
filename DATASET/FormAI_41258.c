//FormAI DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backup_file(char *filename) {
    char backup_name[50];
    sprintf(backup_name, "%s.bak", filename);

    FILE *src = fopen(filename, "rb");
    FILE *dest = fopen(backup_name, "wb");

    if (src == NULL || dest == NULL) {
        printf("Error: Unable to open files.\n");
        exit(1);
    }

    size_t n;
    char buffer[1024];
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }

    fclose(src);
    fclose(dest);

    printf("%s has been backed up as %s.\n", filename, backup_name);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: No filenames specified.\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        backup_file(argv[i]);
    }

    return 0;
}