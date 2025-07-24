//FormAI DATASET v1.0 Category: System boot optimizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

void *optimize_boot(void *thread_id)
{
    long id = (long)thread_id;
    printf("Thread %ld: started.\n", id);
    if (id == 0) {
        printf("Thread %ld: cleaning temporary files.\n", id);
        system("rm -rf /tmp/*");
    }
    else if (id == 1) {
        printf("Thread %ld: disabling unnecessary services.\n", id);
        system("systemctl disable bluetooth.service");
        system("systemctl disable cups.service");
        system("systemctl disable avahi-daemon.service");
    }
    else if (id == 2) {
        printf("Thread %ld: optimizing boot parameters.\n", id);
        system("echo \"vm.swappiness=10\" >> /etc/sysctl.conf");
        system("echo \"net.core.rmem_max=16777216\" >> /etc/sysctl.conf");
        system("echo \"net.core.wmem_max=16777216\" >> /etc/sysctl.conf");
        system("echo \"net.ipv4.tcp_rmem=4096 87380 16777216\" >> /etc/sysctl.conf");
        system("echo \"net.ipv4.tcp_wmem=4096 87380 16777216\" >> /etc/sysctl.conf");
    }
    else {
        printf("Thread %ld: updating system packages.\n", id);
        system("apt-get update");
        system("apt-get upgrade -y");
    }
    printf("Thread %ld: finished.\n", id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, optimize_boot, (void *)i);
        if (rc) {
            printf("Error creating thread %ld, return code: %d\n", i, rc);
            exit(-1);
        }
    }

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Boot optimization completed successfully.\n");

    return 0;
}