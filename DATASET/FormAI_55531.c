//FormAI DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

struct process_info {
    int pid;
    char name[256];
};

struct thread_args {
    struct process_info process_list[MAX_PROCESSES];
    int num_processes;
};

void *get_process_list(void *args) {
    struct thread_args *targs = (struct thread_args *) args;
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[256];
            sprintf(path, "/proc/%s/status", entry->d_name);

            FILE *fp = fopen(path, "r");

            if (fp != NULL) {
                char line[256];
                char name[256];
                int pid = -1;

                while (fgets(line, sizeof(line), fp)) {
                    if (sscanf(line, "Name:\t%s", name) == 1) {
                        strncpy(targs->process_list[targs->num_processes].name, name, sizeof(targs->process_list[targs->num_processes].name));
                    } else if (sscanf(line, "Pid:\t%d", &pid) == 1) {
                        targs->process_list[targs->num_processes].pid = pid;
                    }
                }

                if (pid != -1) {
                    targs->num_processes++;
                }

                fclose(fp);
            }
        }
    }

    closedir(dir);

    return NULL;
}

int main() {
    pthread_t thread;
    struct thread_args targs;
    memset(&targs, 0, sizeof(targs));

    pthread_create(&thread, NULL, get_process_list, &targs);

    printf("%-10s\t%s\n", "PID", "Name");
    printf("------------------------------------------------\n");

    while (targs.num_processes == 0) {
        usleep(1000);
    }

    for (int i = 0; i < targs.num_processes; i++) {
        printf("%-10d\t%s\n", targs.process_list[i].pid, targs.process_list[i].name);
    }

    pthread_join(thread, NULL);

    return 0;
}