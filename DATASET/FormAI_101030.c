//FormAI DATASET v1.0 Category: Chat server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int server_desc, new_socket, valread;
    struct sockaddr_in serv_addr;
    char *message = "Hello from server!";
    char buffer[1024] = {0};
    
    // Creating socket file descriptor
    if ((server_desc = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Could not create socket.\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_desc, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Bind failed.\n");
        return -1;
    }

    // Listening for incoming connections
    if (listen(server_desc, 3) < 0)
    {
        printf("Listen failed.\n");
        return -1;
    }

    while(1)
    {
        printf("Server is waiting for new connections...\n");

        // Accept incoming connection
        if ((new_socket = accept(server_desc, (struct sockaddr *)&serv_addr,
            (socklen_t*)&serv_addr)) < 0)
        {
            printf("Could not accept incoming connection.\n");
            return -1;
        }

        printf("New connection accepted!\n");

        // Send message to client
        send(new_socket, message, strlen(message), 0);
        printf("Hello message sent to client!\n");

        // Receive client's message and display it
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);
        memset(buffer, 0 , 1024);   // Clear the buffer

        // Close the socket
        close(new_socket);
    }

    return 0;
}