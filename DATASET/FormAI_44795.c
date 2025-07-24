//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>

#define BUF_SIZE 1024 // buffer size
#define MAX_CONN 10 // max number of connections

// function to get current timestamp
char* get_timestamp() {
    time_t now;
    time(&now);
    return ctime(&now);
}

int main(int argc, char const *argv[])
{
    int server_fd, new_socket[MAX_CONN], valread[MAX_CONN];
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( 8888 );

    // bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, MAX_CONN) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // initialize buffers
    char buffer[BUF_SIZE] = {0};

    while(1) {
        fd_set readfds;
        int max_fd = 0;
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        max_fd = server_fd;

        for (int i = 0 ; i < MAX_CONN ; i++) {
            if(new_socket[i] > 0) {
                FD_SET(new_socket[i], &readfds);
            }
            if(new_socket[i] > max_fd) {
                max_fd = new_socket[i];
            }
        }

        // wait for any activity on sockets
        int activity = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        if(activity < 0) {
            perror("select error");
            continue;
        }

        // check for incoming connections
        if(FD_ISSET(server_fd, &readfds)) {
            int new_socket_fd;
            if ((new_socket_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < MAX_CONN; i++) {
                if(new_socket[i] == 0) {
                    printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    new_socket[i] = new_socket_fd;
                    break;
                }
            }
        }

        // check for data on existing connections
        for(int i = 0; i < MAX_CONN; i++) {
            if(FD_ISSET(new_socket[i], &readfds)) {
                valread[i] = read(new_socket[i], buffer, BUF_SIZE);
                if(valread[i] == 0) {
                    printf("%s Connection closed from %d\n", get_timestamp(), new_socket[i]);
                    close(new_socket[i]);
                    new_socket[i] = 0;
                }
                else {
                    printf("%s Message received from %d: %s\n", get_timestamp(), new_socket[i], buffer);
                }
            }
        }

    }

    return 0;
}