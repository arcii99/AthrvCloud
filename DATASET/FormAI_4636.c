//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

//Function to check if the file exists
int isFileExists(const char* path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

//Function to write the contents of a file to another file
void copyFile(const char* sourcePath,const char* destinationPath) {
    FILE* sourceFile = fopen(sourcePath, "r");
    FILE* destinationFile = fopen(destinationPath, "w");
    char ch;
    while((ch = fgetc(sourceFile)) != EOF)
        fputc(ch, destinationFile);
    fclose(sourceFile);
    fclose(destinationFile);
}

//Function to synchronize the two directories recursively
void syncDirectories(const char* sourcePath, const char* destinationPath) {
    DIR* sourceDir = opendir(sourcePath);
    DIR* destinationDir = opendir(destinationPath);
    if(sourceDir == NULL || destinationDir == NULL) {
        printf("Error: Directory not found\n");
        return;
    }
    struct dirent *sourceEntry, *destinationEntry;
    while((sourceEntry = readdir(sourceDir))) {
        if(strcmp(sourceEntry->d_name, ".") != 0 && strcmp(sourceEntry->d_name, "..") != 0) {
            char sourceEntryPath[strlen(sourcePath) + strlen(sourceEntry->d_name) + 2];
            snprintf(sourceEntryPath, sizeof sourceEntryPath, "%s/%s", sourcePath, sourceEntry->d_name);
            char destinationEntryPath[strlen(destinationPath) + strlen(sourceEntry->d_name) + 2];
            snprintf(destinationEntryPath, sizeof destinationEntryPath, "%s/%s", destinationPath, sourceEntry->d_name);
            destinationEntry = NULL;
            if((destinationEntry = readdir(destinationDir))) {
                char destinationEntryType[strlen(destinationEntryPath) + 2];
                snprintf(destinationEntryType, sizeof destinationEntryType, "%s/", destinationEntryPath);
                if(destinationEntry->d_type == DT_DIR) {
                    if(strcmp(destinationEntryPath, destinationEntryType) == 0)
                        syncDirectories(sourceEntryPath, destinationEntryPath);
                    else {
                        printf("Error: Directory name conflict detected\n");
                        closedir(sourceDir);
                        closedir(destinationDir);
                        return;
                    }
                }
                else {
                    if((isFileExists(destinationEntryPath) == 1)) {
                        struct stat sourceStat, destinationStat;
                        stat(sourceEntryPath, &sourceStat);
                        stat(destinationEntryPath, &destinationStat);
                        if((sourceStat.st_mtime > destinationStat.st_mtime))
                            copyFile(sourceEntryPath, destinationEntryPath);
                    }
                    else
                        copyFile(sourceEntryPath, destinationEntryPath);
                }
            }
            else {
                mkdir(destinationEntryPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
                syncDirectories(sourceEntryPath, destinationEntryPath);
            }
        }
    }
    while((destinationEntry = readdir(destinationDir))) {
        if(strcmp(destinationEntry->d_name, ".") != 0 && strcmp(destinationEntry->d_name, "..") != 0) {
            char destinationEntryPath[strlen(destinationPath) + strlen(destinationEntry->d_name) + 2];
            snprintf(destinationEntryPath, sizeof destinationEntryPath, "%s/%s", destinationPath, destinationEntry->d_name);
            if(isFileExists(destinationEntryPath) == 1) {
                char sourceEntryPath[strlen(sourcePath) + strlen(destinationEntry->d_name) + 2];
                snprintf(sourceEntryPath, sizeof sourceEntryPath, "%s/%s", sourcePath, destinationEntry->d_name);
                if(isFileExists(sourceEntryPath) == 0)
                    remove(destinationEntryPath);
            }
            else {
                printf("Error: File not found\n");
                closedir(sourceDir);
                closedir(destinationDir);
                return;
            }
        }
    }
    closedir(sourceDir);
    closedir(destinationDir);
    return;
}

//Main function
int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <source_directory_path> <destination_directory_path>\n", argv[0]);
        return 0;
    }
    syncDirectories(argv[1], argv[2]);
    printf("Directories Synchronized Successfully\n");
    return 0;
}