//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include <string.h>

#define PROC_DIR "/proc/"

int is_directory(const char *path) {
    DIR *directory = opendir(path);
    if (directory != NULL) {
        closedir(directory);
        return 1;
    }
    return 0;
}

void print_proc_info(int pid) {
    char buffer[1024];

    sprintf(buffer, PROC_DIR "%d/cmdline", pid);

    FILE *cmdline_file = fopen(buffer, "rb");

    if (cmdline_file != NULL) {
        int i = 0, c;
        char cmdline[1024] = { 0 };
        while ((c = fgetc(cmdline_file)) != EOF) {
            cmdline[i++] = (char) c;
        }

        printf("%-4d %s\n", pid, cmdline);
        fclose(cmdline_file);
    }
}

int main() {
    DIR *proc_dir = opendir(PROC_DIR);
    struct dirent *ent;
    while ((ent = readdir(proc_dir)) != NULL) {
        char *entry_name = ent->d_name;
        if (isdigit(*entry_name)) {
            int pid = atoi(entry_name);
            print_proc_info(pid);
        }
    }
    closedir(proc_dir);
    return 0;
}