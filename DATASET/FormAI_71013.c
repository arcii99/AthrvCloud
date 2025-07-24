//FormAI DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <dirent.h>

int main(void) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
                char filename[50];
                sprintf(filename, "/proc/%s/stat", ent->d_name);
                FILE *file = fopen(filename, "r");
                if (file) {
                    int pid;
                    char comm[50], state;
                    fscanf(file, "%d (%[^)]) %c", &pid, comm, &state);
                    printf("%d\t%s\t%c\n", pid, comm, state);
                    fclose(file);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Could not open /proc directory");
        return 1;
    }

    return 0;
}