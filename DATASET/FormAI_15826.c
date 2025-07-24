//FormAI DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR* proc_dir = opendir("/proc");
    struct dirent* ent;
    
    // traverse each directory in /proc
    while ((ent = readdir(proc_dir))) {
        // check if the name is a number (i.e., process ID)
        if (isdigit(*ent->d_name)) {
            char path[256];
            FILE* fp;
            char line[256];
            sprintf(path, "/proc/%s/stat", ent->d_name);
            fp = fopen(path, "r");
            if (fp) {
                // read the process information from /proc/[pid]/stat file
                fgets(line, sizeof(line), fp);
                fclose(fp);
                // extract the process name and status
                char name[256];
                char status;
                sscanf(line, "%*d (%[^)]%c", name, &status);
                // print the process ID, name, and status
                printf("PID=%5s\tName=%-20s\tStatus=%c\n", ent->d_name, name, status);
            }
        }
    }
    
    closedir(proc_dir);
    return 0;
}