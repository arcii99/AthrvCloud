//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024

struct FileInfo {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
};

void scanFile(struct FileInfo file) {
    int hasVirus = 0;
    char virus[] = "virus";
    if (strstr(file.content, virus) != NULL) {
        printf("Virus found in file %s\n", file.name);
        hasVirus = 1;
    }
    if (!hasVirus) {
        printf("File %s is safe\n", file.name);
    }
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    struct FileInfo file;

    printf("Enter file name: ");
    fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = 0;

    FILE* f = fopen(fileName, "rb");
    if (!f) {
        printf("Failed to open the file\n");
        return 1;
    }

    if (fread(file.content, 1, MAX_FILE_SIZE, f) < 0) {
        printf("Failed to read the file\n");
        fclose(f);
        return 1;
    }
    fclose(f);

    strncpy(file.name, fileName, MAX_FILE_NAME_LENGTH);
    scanFile(file);
    return 0;
}