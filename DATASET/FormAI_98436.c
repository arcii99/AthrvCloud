//FormAI DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <pthread.h>

void *print_process_info(void *arg);

int main(void) {
    long num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of CPUs detected: %ld\n", num_cpus);

    pthread_t threads[num_cpus];
    for (int i = 0; i < num_cpus; ++i) {
        pthread_create(&threads[i], NULL, print_process_info, (void *) (intptr_t) i);
    }
    for (int i = 0; i < num_cpus; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *print_process_info(void *arg) {
    int cpu_num = (intptr_t) arg;
    printf("Thread %d running on CPU %d\n", (int) pthread_self(), cpu_num);

    char command[100];
    snprintf(command, sizeof(command), "ps -C %s -o pid,user,%cpu,command --sort=-%cpu | head",
             "bash"); // Replace "bash" with the process you want to monitor
    FILE *fp = popen(command, "r");

    if (fp == NULL) {
        printf("Failed to execute the command\n");
        return NULL;
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    pclose(fp);
    return NULL;
}