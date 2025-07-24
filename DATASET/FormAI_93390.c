//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
 
#define NUM_THREADS 10
 
void *ping(void *arg) {
    char *hostname = (char *)arg;
    struct hostent *host_info;
    struct sockaddr_in addr;
    int sock, status, timeout = 5000;
 
    if ((host_info = gethostbyname(hostname)) == NULL) {
        printf("Error: Invalid host name!\n");
        pthread_exit(NULL);
    }
 
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr = *((struct in_addr *)host_info->h_addr);
 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Failed to create socket!\n");
        pthread_exit(NULL);
    }
 
    struct timeval timeout_val;
    timeout_val.tv_sec = timeout / 1000;
    timeout_val.tv_usec = (timeout % 1000) * 1000;
 
    if ((setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout_val,
            sizeof(struct timeval))) != 0) {
        printf("Error: Failed to set receive timeout!\n");
        close(sock);
        pthread_exit(NULL);
    }
 
    if ((setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout_val,
            sizeof(struct timeval))) != 0) {
        printf("Error: Failed to set send timeout!\n");
        close(sock);
        pthread_exit(NULL);
    }
 
    if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) ==
            -1) {
        printf("Host %s is down.\n", hostname);
    } else {
        printf("Host %s is up.\n", hostname);
    }
 
    close(sock);
    pthread_exit(NULL);
}
 
int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;
 
    if (argc <= 1) {
        printf("Error: Please specify at least one host name!\n");
        return 1;
    }
 
    for (int i = 1; i < argc; i++) {
        rc = pthread_create(&threads[i-1], NULL, ping, (void *)argv[i]);
        if (rc) {
            printf("Error: Failed to create thread %d!\n", i-1);
            return 1;
        }
    }
 
    for (int i = 1; i < argc; i++) {
        rc = pthread_join(threads[i-1], NULL);
        if (rc) {
            printf("Error: Failed to join thread %d!\n", i-1);
            return 1;
        }
    }
 
    return 0;
}