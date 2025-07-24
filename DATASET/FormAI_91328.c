//FormAI DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int is_number(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE], pid[10], proc[BUFFER_SIZE], cmdline[BUFFER_SIZE];
    FILE *fp;
    
    printf("PID\tCMD\n");
    
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error");
        exit(1);
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            sprintf(path, "/proc/%s/cmdline", entry->d_name);
            fp = fopen(path, "r");
            if (fp != NULL) {
                fread(cmdline, 1, BUFFER_SIZE, fp);
                fclose(fp);
                sprintf(proc, "/proc/%s", entry->d_name);
                printf("%s\t%s\n", entry->d_name, cmdline);
            }
        }
    }
    closedir(dir);
    
    return 0;
}