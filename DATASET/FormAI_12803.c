//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *subnet_calculation(void *ip_addr);

int main() {
    int num_threads, i;
    char ip_address[16]; // for IPV4
    printf("Enter the IP address for subnet calculation: ");
    scanf("%s", ip_address);
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, subnet_calculation, (void *)ip_address);
        pthread_join(threads[i], NULL);
    }
    return 0;
}

void *subnet_calculation(void *ip_addr) {
    char *ip = (char *)ip_addr;
    printf("\nCalculating Subnet for IP %s on thread %ld", ip, pthread_self());

    // Write your subnet calculation logic here 

    printf("\nSubnet calculation complete for IP %s on thread %ld", ip, pthread_self());

    pthread_exit(NULL);
}