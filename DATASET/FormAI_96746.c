//FormAI DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256

// Function to backup a file
void backupFile(char *filename) {
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        return;
    }

    // Create the backup filename
    char backupFilename[MAX_FILENAME_SIZE];
    strncpy(backupFilename, filename, MAX_FILENAME_SIZE-1);
    char *extensionIndex = strrchr(backupFilename, '.');
    if (extensionIndex != NULL) {
        *extensionIndex = '\0';
    }
    strncat(backupFilename, ".bak", MAX_FILENAME_SIZE-strlen(backupFilename)-1);

    FILE *out = fopen(backupFilename, "wb");
    if (out == NULL) {
        printf("Error: Cannot create backup file '%s'\n", backupFilename);
        fclose(in);
        return;
    }

    // Copy the contents of the file to the backup file
    int c;
    while ((c = fgetc(in)) != EOF) {
        if (fputc(c, out) == EOF) {
            printf("Error: Failed to write to backup file '%s'\n", backupFilename);
            fclose(in);
            fclose(out);
            return;
        }
    }

    fclose(in);
    fclose(out);

    printf("Successfully backed up file '%s' to '%s'\n", filename, backupFilename);
}

int main() {
    char filename[] = "example.txt";
    backupFile(filename);
    return 0;
}