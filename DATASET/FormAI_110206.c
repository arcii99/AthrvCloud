//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

void process_viewer(char *path, char *indentation) {

    DIR *directory = opendir(path);
    if (directory) {
        struct dirent *entry;
        while ((entry = readdir(directory)) != NULL) {
            if (isdigit(entry->d_name[0])) {
                char sub_path[100];
                sprintf(sub_path, "%s/%s", path, entry->d_name);
                char command_path[200];
                sprintf(command_path, "%s/cmdline", sub_path);

                FILE *file = fopen(command_path, "r");
                if (file) {
                    char command[500];
                    fgets(command, sizeof(command), file);
                    printf("%s[%s]\n", indentation, command);
                    process_viewer(sub_path, strcat(indentation, "  "));
                    fclose(file);
                }
            }
        }
        closedir(directory);
    }
}

int main() {
    char indentation[500] = "";
    process_viewer("/proc", indentation);
    return 0;
}