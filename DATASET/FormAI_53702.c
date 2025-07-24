//FormAI DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR* d;
    struct dirent* dir;
    d = opendir("/proc");
    if (d) {
        printf("PID\t\tProcess Name\n");
        while ((dir = readdir(d)) != NULL) {
            int pid = atoi(dir->d_name);
            if (pid != 0) {
                char proc_dir[100];
                sprintf(proc_dir, "/proc/%d/cmdline", pid);
                FILE* fp = fopen(proc_dir, "r");
                if (fp) {
                    char buf[256];
                    if (fgets(buf, sizeof(buf), fp) != NULL) {
                        if (strlen(buf) > 0) {
                            printf("%d\t\t%s\n", pid, buf);
                        }
                    }
                    fclose(fp);
                }
            }
        }
    }
    closedir(d);
    return 0;
}