//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

/* Define number of threads for scanning */
#define MAX_THREADS 8

/* Define target IP, starting port, and ending port to scan */
char* target_ip = "192.168.0.1";
int start_port = 1;
int end_port = 65535;

/* Define struct for passing arguments to threads */
struct thread_args_t {
    int thread_id;
    int starting_port;
    int ending_port;
};

/* Define function for checking port */
int check_port(char* host, int port) {
    struct sockaddr_in sa;
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) { return -1; }
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    inet_pton(AF_INET, host, &(sa.sin_addr));
    int result = connect(sock, (struct sockaddr*)&sa, sizeof sa);
    close(sock);
    return result == 0 ? 1 : 0;
}

/* Define function for scanning ports */
void* scan_ports(void* threadargs) {
    struct thread_args_t* args = (struct thread_args_t*)threadargs;
    int thread_id = args->thread_id;
    int starting_port = args->starting_port;
    int ending_port = args->ending_port;
    printf("Thread #%d started. Scanning ports %d-%d\n", thread_id, starting_port, ending_port);
    for (int i = starting_port; i <= ending_port; i++) {
        if (check_port(target_ip, i) == 1) {
            printf("Thread #%d: %d open\n", thread_id, i);
        }
    }
    printf("Thread #%d finished.\n", thread_id);
    pthread_exit(NULL);
}

/* Main function */
int main() {
    /* Initialize variables */
    pthread_t threads[MAX_THREADS];
    struct thread_args_t thread_args[MAX_THREADS];
    int n = end_port - start_port + 1;
    int step = (n + MAX_THREADS - 1) / MAX_THREADS;
    int i = 0;

    /* Create threads and scan ports */
    for (i = 0; i < MAX_THREADS && start_port <= end_port; i++) {
        thread_args[i].thread_id = i + 1;
        thread_args[i].starting_port = start_port;
        thread_args[i].ending_port = start_port + step - 1;
        if (thread_args[i].ending_port > end_port) {
            thread_args[i].ending_port = end_port;
        }
        pthread_create(&threads[i], NULL, scan_ports, (void*)&thread_args[i]);
        start_port = thread_args[i].ending_port + 1;
    }

    /* Join threads */
    for (i = 0; i < MAX_THREADS && threads[i] != 0; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning thread has finished.\n");

    return 0;
}