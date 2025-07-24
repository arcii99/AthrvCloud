//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define MAX_VIRUS_DB_ENTRIES 100

typedef struct {
    char signature[100];
    int length;
} VirusDefinition;

typedef struct {
    char name[MAX_FILE_NAME];
    bool infected;
} FileInfo;

VirusDefinition virusDb[MAX_VIRUS_DB_ENTRIES];
int numVirusDbEntries = 0;

// function to add virus definitions to the database
void addVirusDef(char signature[], int length) {
    if (numVirusDbEntries < MAX_VIRUS_DB_ENTRIES) {
        VirusDefinition vd = { .length = length };
        strcpy(vd.signature, signature);
        virusDb[numVirusDbEntries] = vd;
        numVirusDbEntries++;
    }
}

// function to scan a file and set infection status
void scanFile(FileInfo *fileInfo) {
    FILE *file = fopen(fileInfo->name, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file: %s\n", fileInfo->name);
        return;
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);

    char buffer[fileSize];
    fread(buffer, 1, fileSize, file);
    fclose(file);

    for (int i = 0; i < numVirusDbEntries; i++) {
        if (strstr(buffer, virusDb[i].signature)) {
            fileInfo->infected = true;
            return;
        }
    }

    fileInfo->infected = false;
}

int main() {
    // add virus definitions to the database
    addVirusDef("Trojan Horse", 12);
    addVirusDef("Malware", 7);
    addVirusDef("Worm", 4);

    // scan files for viruses
    FileInfo files[] = {
        { .name = "file1.exe" },
        { .name = "file2.jpg" },
        { .name = "file3.txt" },
        { .name = "file4.docx" },
        { .name = "file5.pdf" }
    };
    int numFiles = sizeof(files) / sizeof(FileInfo);

    for (int i = 0; i < numFiles; i++) {
        scanFile(&files[i]);
        printf("%s: %s\n", files[i].name, files[i].infected ? "Infected" : "Clean");
    }

    return 0;
}