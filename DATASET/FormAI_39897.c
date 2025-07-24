//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

//function to scan a file for viruses
void scan_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: Cannot open file %s\n\n", filename);
        return;
    }
    char buffer[100];
    char* virus = "virus";
    while(fgets(buffer, 100, file)) {
        if(strstr(buffer, virus)) {
            printf("Virus detected in file %s\n\n", filename);
            return;
        }
    }
    printf("File %s is clean\n\n", filename);
}

//function to scan a directory for files
void scan_directory(char* directory) {
    DIR* dir = opendir(directory);
    if(dir == NULL) {
        printf("Error: Cannot open directory %s\n\n", directory);
        return;
    }
    struct dirent* entry;
    char filename[100];
    while((entry = readdir(dir)) != NULL) {
        if(entry->d_type == DT_REG) {
            strcpy(filename, directory);
            strcat(filename, "/");
            strcat(filename, entry->d_name);
            scan_file(filename);
        }
    }
    closedir(dir);
}

int main() {
    char* directory = "/home/user/Documents";
    scan_directory(directory);
    return 0;
}