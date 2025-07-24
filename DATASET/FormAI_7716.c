//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

#define BUF_SIZE 1024
#define PORT 8888
#define MAX_CLIENTS 10

void error_handling(char *message);
void set_sockets(int serv_sock, int *clients, fd_set *reads, fd_set *writes);
void check_sockets(int serv_sock, int *clients, fd_set *reads, fd_set *writes);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock, clients[MAX_CLIENTS];
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    fd_set reads, writes;
    char buffer[BUF_SIZE];
    int option = 1, read_size;

    srand(time(NULL));

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");

    if(setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1)
        error_handling("setsockopt() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    if(listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    memset(clients, -1, sizeof(clients));
    FD_ZERO(&reads);
    FD_ZERO(&writes);
    FD_SET(serv_sock, &reads);

    while(1) {
        set_sockets(serv_sock, clients, &reads, &writes);
        check_sockets(serv_sock, clients, &reads, &writes);
    }
    return 0;
}

void set_sockets(int serv_sock, int *clients, fd_set *reads, fd_set *writes) {
    int i;
    FD_SET(serv_sock, reads);

    for(i=0 ; i<MAX_CLIENTS ; ++i) {
        if(clients[i] != -1) {
            FD_SET(clients[i], reads);
            FD_SET(clients[i], writes);
        }
    }
}

void check_sockets(int serv_sock, int *clients, fd_set *reads, fd_set *writes) {
    int i, clnt_sock, read_size;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    char buffer[BUF_SIZE];

    if(select(MAX_CLIENTS + 1, reads, writes, NULL, NULL) == -1) {
        error_handling("select() error");
    }

    if(FD_ISSET(serv_sock, reads)) {
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        if(clnt_sock == -1) {
            error_handling("accept() error");
        }

        for(i=0 ; i<MAX_CLIENTS ; ++i) {
            if(clients[i] == -1) {
                clients[i] = clnt_sock;
                FD_SET(clnt_sock, writes);
                break;
            }
        }
    }

    for(i=0 ; i<MAX_CLIENTS ; ++i) {
        if(clients[i] != -1) {
            if(FD_ISSET(clients[i], writes)) {
                int response = rand() % 10;
                sprintf(buffer, "Website Uptime Monitor: %d\n", response);
                if(send(clients[i], buffer, strlen(buffer), 0) != strlen(buffer)) {
                    close(clients[i]);
                    FD_CLR(clients[i], writes);
                    FD_CLR(clients[i], reads);
                    clients[i] = -1;
                }
            }

            if(FD_ISSET(clients[i], reads)) {
                char buffer[BUF_SIZE];
                read_size = read(clients[i], buffer, BUF_SIZE);
                if(read_size == 0) {
                    close(clients[i]);
                    FD_CLR(clients[i], writes);
                    FD_CLR(clients[i], reads);
                    clients[i] = -1;
                }
            }
        }
    }
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}