//FormAI DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int socket_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    int address_size = sizeof(server_address);
    char buffer[MAX_BUFFER];

    // Step 1: Create a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error: Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Bind socket to a port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
   
    if (bind(socket_fd, (struct sockaddr *)&server_address, address_size) < 0) {
        perror("Error: Socket Bind Failed");
        exit(EXIT_FAILURE);
    }
   
    // Step 3: Listening to incoming requests
    if (listen(socket_fd, 3) < 0) {
        perror("Error: Socket Listening Failed");
        exit(EXIT_FAILURE);
    }
   
    // Step 4: Accept the incoming client socket
    if ((client_fd = accept(socket_fd, (struct sockaddr *)&client_address, 
                       (socklen_t*)&address_size)) < 0) {
        perror("Error: Socket Acceptance Failed");
        exit(EXIT_FAILURE);
    }
   
    // Step 5: Read and write data to the client
    while (1) {
        memset(buffer, 0, MAX_BUFFER);
        read(client_fd, buffer, MAX_BUFFER);
        printf("\nClient: %s", buffer);

        memset(buffer, 0, MAX_BUFFER);
        printf("\nServer: ");
        fgets(buffer, MAX_BUFFER, stdin);
        write(client_fd, buffer, strlen(buffer));
   
        // Step 6: Close the client socket
        close(client_fd);
    }
   
    // Step 7: Close the server socket
    close(socket_fd);
    return 0;
}