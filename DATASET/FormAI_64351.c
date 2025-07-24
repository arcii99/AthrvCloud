//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 250
#define MAX_LINE_LEN 256

typedef struct FileRecord {
    char name[MAX_FILENAME_LEN];
    // add more fields here if needed
} FileRecord;

int isInfected(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("ERROR: file '%s' not found\n", filename);
        return 0;
    }

    char buffer[MAX_LINE_LEN];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // add virus check logic here
        if (strstr(buffer, "virus") != NULL) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int main() {
    // assume there are 3 files in the current directory
    FileRecord files[3];
    strcpy(files[0].name, "file1.txt");
    strcpy(files[1].name, "file2.exe");
    strcpy(files[2].name, "file3.docx");

    int numFiles = sizeof(files) / sizeof(FileRecord);

    int infected = 0;
    for (int i = 0; i < numFiles; i++) {
        printf("Checking file '%s'...\n", files[i].name);
        if (isInfected(files[i].name)) {
            printf("WARNING: file '%s' is infected!\n", files[i].name);
            infected = 1;
        }
    }

    if (!infected) {
        printf("All files are clean!\n");
    }

    return 0;
}