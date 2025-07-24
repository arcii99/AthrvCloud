//FormAI DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

int main() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            char path[1000];
            sprintf(path, "/proc/%s/cmdline", entry->d_name);

            FILE *file = fopen(path, "r");
            if (file != NULL) {
                char line[1000];
                fgets(line, sizeof(line), file);
                fclose(file);

                printf("%s: %s\n", entry->d_name, line);
            }
        }
    }

    closedir(dir);
    return 0;
}