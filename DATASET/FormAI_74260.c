//FormAI DATASET v1.0 Category: Chat server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
    int server_fd, new_socket, valread, max_sd, client_sockets[MAX_CLIENTS], client_count = 0;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    fd_set read_fds;
    char *reply = "Your message has been received.\n";
     
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
    // Attach socket to the port 8080
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d \n", PORT);
     
    // Loop to handle incoming connections and messages
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        max_sd = server_fd;

        //Adding connected clients to the socket fd_set
        for (int i = 0; i < client_count; i++) {
            int sock_fd = client_sockets[i];
            if (sock_fd > 0)
                FD_SET(sock_fd, &read_fds);
            if (sock_fd > max_sd)
                max_sd = sock_fd;
        }
     
        //Wait for an activity on one of the sockets
        if (select(max_sd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }
         
        //If server's socket activity detected then it means someone is connecting
        if (FD_ISSET(server_fd, &read_fds)) {
            struct sockaddr_in client_addr;
            int addrlen = sizeof(client_addr);
            
            if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen))<0) {
                perror("accept failed");
                continue;
            }
         
            printf("\nNew client connected with IP address: %s and port number: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            
            //Add the new socket to the client_sockets list
            client_sockets[client_count++] = new_socket;
        }

        //Loop to handle message from connected clients
        for (int i = 0; i < client_count; i++) {
            int sock_fd = client_sockets[i];
            if (FD_ISSET(sock_fd, &read_fds)) {
                if ((valread = read(sock_fd, buffer, 1024)) == 0) {
                    printf("\nClient disconnected with IP address: %s and port number: %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    
                    //Close the disconnected client's socket and remove from the client_sockets list
                    close(sock_fd);
                    client_sockets[i] = 0;
                } else {
                    printf("%s\n", buffer);

                    //Reply to the client with acknowledgement message
                    send(sock_fd, reply, strlen(reply), 0);
                }
                memset(buffer, 0, sizeof(buffer)); //clear the buffer
            }
        }
    }

    return 0;
}