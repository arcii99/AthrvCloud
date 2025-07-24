//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 100

// Function to check if a file is infected with a virus
int fileContainsVirus(char* fileName) {
    FILE* fp;
    char buffer[MAX_FILENAME_LENGTH];
    char* virusSignature = "I_am_a_virus"; // Sample virus signature
    int virusSignatureLen = strlen(virusSignature);

    fp = fopen(fileName, "rb");
    if (fp == NULL) {
        return 0;
    }

    while(!feof(fp)) {
        size_t length = fread(buffer, 1, MAX_FILENAME_LENGTH, fp);
        for (int i = 0; i < length - virusSignatureLen; i++) {
            if (memcmp(buffer+i, virusSignature, virusSignatureLen) == 0) {
                fclose(fp);
                return 1; // File contains virus
            }
        }
    }

    fclose(fp);
    return 0; // File is clean
}

// Function to scan a directory for infected files
void scanDirectory(char* path) {
    DIR* dp = opendir(path);
    if (dp == NULL) {
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dp))) {
        char fileName[MAX_FILENAME_LENGTH];
        strcpy(fileName, path);
        strcat(fileName, "/");
        strcat(fileName, entry->d_name);

        struct stat fileInfo;
        if (lstat(fileName, &fileInfo) == 0 && S_ISDIR(fileInfo.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Recursive call to scan sub-directory
            scanDirectory(fileName);
        } else {
            // Check if file is infected with virus
            if (fileContainsVirus(fileName) == 1) {
                printf("Virus found in file: %s\n", fileName);
            }
        }
    }

    closedir(dp);
}

int main() {
    char* path = "/home/user/Documents"; // Sample directory path to scan
    scanDirectory(path);
    printf("Scan complete.\n");
    return 0;
}