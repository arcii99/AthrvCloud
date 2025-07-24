//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <fcntl.h>
#include <ctype.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define PORT "8080"
#define MAX_PENDING 10
#define MAX_PACKET_SIZE 1024

int create_socket(int *sockfd, struct sockaddr_in *addr)
{
    int yes = 1; 

    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        return -1;
    }

    if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt error");
        return -1;
    }

    addr->sin_family = AF_INET;
    addr->sin_port = htons(atoi(PORT));
    addr->sin_addr.s_addr = INADDR_ANY;
    memset(&(addr->sin_zero), '\0', 8);

    if (bind(*sockfd, (struct sockaddr *)addr, sizeof(struct sockaddr)) == -1) {
        perror("bind error");
        return -1;
    }

    if (listen(*sockfd, MAX_PENDING) == -1) {
        perror("listen error");
        return -1;
    }

    return 0;
}

void handle_client(int sockfd, fd_set *master_set, int *fdmax)
{
    char buf[MAX_PACKET_SIZE];
    int nbytes;

    if ((nbytes = recv(sockfd, buf, sizeof(buf), 0)) <= 0) {
        if (nbytes == 0) {
            printf("socket %d hung up\n", sockfd);
        } else {
            perror("recv error");
        }
        close(sockfd);
        FD_CLR(sockfd, master_set);
    } else {
        printf("received %d bytes from socket %d\n", nbytes, sockfd);
    }
}

void start_monitor(int sockfd)
{
    int optval = 1;
    int res;

    /* Set TCP_NODELAY option */
    res = setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY,
                    &optval, sizeof(optval));
    if (res != 0) {
        perror("setsockopt error");
    }

    /* TODO: add your monitoring functionality here */
}

int main(int argc, char *argv[])
{
    fd_set master_set, read_set;
    struct sockaddr_in server_addr, client_addr;
    int sockfd, new_fd, fdmax, i;
    socklen_t addrlen;
    char remote_ip[INET_ADDRSTRLEN];
    struct hostent *he;
    char *port = PORT;

    FD_ZERO(&master_set);
    FD_ZERO(&read_set);

    if (argc > 1) {
        port = argv[1];
    }

    if (create_socket(&sockfd, &server_addr) != 0) {
        exit(EXIT_FAILURE);
    }

    FD_SET(sockfd, &master_set);
    fdmax = sockfd;

    printf("monitor started on port %s\n", port);

    while(1) {
        read_set = master_set;

        if (select(fdmax+1, &read_set, NULL, NULL, NULL) == -1) {
            perror("select error");
            exit(EXIT_FAILURE);
        }

        for(i=0; i<=fdmax; i++) {
            if (FD_ISSET(i, &read_set)) {
                if (i == sockfd) {
                    addrlen = sizeof(client_addr);

                    if ((new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
                        perror("accept error");
                    } else {
                        FD_SET(new_fd, &master_set);

                        if (new_fd > fdmax) {
                            fdmax = new_fd;
                        }

                        he = gethostbyaddr((const char *)&client_addr.sin_addr.s_addr,
                                        sizeof(client_addr.sin_addr.s_addr), AF_INET);
                        inet_ntop(AF_INET, &client_addr.sin_addr, remote_ip, INET_ADDRSTRLEN);
                        printf("new connection from %s:%d\n", remote_ip, ntohs(client_addr.sin_port));

                    }
                } else {
                    handle_client(i, &master_set, &fdmax);
                }
            }
        }

        if (FD_ISSET(sockfd, &read_set)) {
            start_monitor(sockfd);
        }
    }

    return 0;
}