//FormAI DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
    DIR *dir;
    pid_t pid;

    printf("\nArtistic Process Viewer\n");
    while(1)
    {
        printf("\n\nProcesses:\n");
        dir = opendir("/proc");
        struct dirent *entry;
        while((entry = readdir(dir)) != NULL)
        {
            if(entry->d_type == DT_DIR)
            {
                char *endptr;
                pid = strtol(entry->d_name, &endptr, 10);
                if (*endptr == '\0')
                {
                    char stat_path[256];
                    snprintf(stat_path, sizeof(stat_path), "/proc/%ld/stat", (long)pid);
                    FILE *fp = fopen(stat_path, "r");
                    if(fp)
                    {
                        char name[256];
                        fscanf(fp, "%ld %256s", &pid, name);
                        printf("%ld\t%s\n", pid, name);
                        fclose(fp);
                    }
                }
            }
        }
        closedir(dir);
        sleep(5);
        system("clear");
    }

    return 0;
}