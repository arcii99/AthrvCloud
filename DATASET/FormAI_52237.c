//FormAI DATASET v1.0 Category: Socket programming ; Style: future-proof
// A futuristic example of C socket programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {

    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    socklen_t addr_len = sizeof(serv_addr);
    fd_set read_fds;
    int i, max_fd, new_fd, client_socket[MAX_CLIENTS], activity, addrlen, sd, val_read;

    int server_fd = socket(AF_INET, SOCK_STREAM, 0); // create server socket
    if (server_fd == 0) {
        printf("Could not create socket");
        return 1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(client_socket, 0, sizeof(client_socket));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8888);

    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { // bind IP address and port to socket
        printf("Bind failed");
        return 1;
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) { // start listening for connections
        printf("Listen failed");
        return 1;
    }

    printf("Listening on port 8888\n");

    while(1) {

        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        max_fd = server_fd;

        for (i = 0 ; i < MAX_CLIENTS ; i++) { // add all connected clients to the socket set
            sd = client_socket[i];
            if (sd > 0)
                FD_SET(sd, &read_fds);
            if (sd > max_fd)
                max_fd = sd;
        }

        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL); // wait for activity on any of the sockets

        if ((activity < 0) && (errno!=EINTR)) {
            printf("Select error");
        }

        if (FD_ISSET(server_fd, &read_fds)) { // new connection request
            if ((new_fd = accept(server_fd, (struct sockaddr *)&serv_addr, (socklen_t*)&addr_len)) < 0) {
                printf("Accept error");
            }
            // add new client to array of clients
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_fd;
                    printf("Client %d connected\n", i+1);
                    break;
                }
            }
        }

        for (i = 0; i < MAX_CLIENTS; i++) { // check for incoming data from clients
            sd = client_socket[i];
            if (FD_ISSET(sd, &read_fds)) {
                if ((val_read = read(sd, buffer, BUFFER_SIZE)) == 0) { // client closed connection
                    printf("Client %d disconnected\n", i+1);
                    close(sd);
                    client_socket[i] = 0;
                }
                else { // process client's message and send response
                    buffer[val_read] = '\0';
                    printf("Client %d sent: %s", i+1, buffer);
                    send(sd, "Message received", strlen("Message received"), 0);
                }
            }
        }
    }

    return 0;
}