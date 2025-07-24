//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 50
#define MAX_PORT 65535
#define TIMEOUT 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

FILE *output_file;

int scan_port(char *host, int port){
    struct sockaddr_in sin;
    int fd, ret;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1){
        perror("socket");
        return -1;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = inet_addr(host);

    ret = connect(fd, (struct sockaddr *)&sin, sizeof(sin));
    if (ret == -1){
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}

void *scanner(void *arg){
    char *host = (char *)arg;
    int port, status;

    while (1){
        pthread_mutex_lock(&mutex);
        port = (rand() % MAX_PORT) + 1;
        pthread_mutex_unlock(&mutex);

        status = scan_port(host, port);
        if (status == 0){
            printf("\n%d open", port);
            fprintf(output_file, "\n%d open", port);
        } else if (status == -1){
            break;
        }
    }

    return NULL;
}

int main(int argc, char **argv){
    if (argc < 2){
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    output_file = fopen("output.txt", "w");

    if (!output_file){
        perror("fopen");
        return 1;
    }

    fprintf(output_file, "Port scanner output for %s", argv[1]);

    pthread_t threads[MAX_THREADS];

    int i;
    for (i = 0; i < MAX_THREADS; i++){
        pthread_create(&threads[i], NULL, scanner, argv[1]);
    }

    sleep(TIMEOUT);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_cancel(threads[i]);
        pthread_join(threads[i], NULL);
    }

    fclose(output_file);
    
    return 0;
}