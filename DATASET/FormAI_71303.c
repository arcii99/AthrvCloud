//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int scan_directory(char*);

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    int infections = scan_directory(argv[1]);

    if(infections == 0) {
        printf("No infections found.\n");
        return 0;
    }
    else {
        printf("%d infections found.\n", infections);
        return 1;
    }
}

int scan_directory(char* directory) {
    DIR* dir;
    struct dirent* entry;
    int infections = 0;
    char* extension = ".exe"; // only scan .exe files

    if((dir = opendir(directory)) == NULL) {
        perror("Error opening directory");
        return 0;
    }

    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char* filename = entry->d_name;
        if(strcmp(&filename[strlen(filename)-4], extension) == 0) {
            char filepath[512];
            sprintf(filepath, "%s/%s", directory, filename);

            FILE* file;
            long size;
            char* buffer;

            file = fopen(filepath, "rb");
            if(file == NULL) {
                printf("Could not open file: %s\n", filepath);
                continue;
            }

            fseek(file, 0L, SEEK_END);
            size = ftell(file);

            buffer = calloc(size, sizeof(char));
            if(buffer == NULL) {
                printf("Could not allocate memory for file: %s\n", filepath);
                continue;
            }

            fseek(file, 0L, SEEK_SET);
            fread(buffer, sizeof(char), size, file);

            if(strstr(buffer, "trojan") != NULL) {
                infections++;
                printf("Infection found in file %s\n", filepath);
            }

            free(buffer); // don't forget to free memory!
            fclose(file);
        }
    }

    closedir(dir);
    return infections;
}