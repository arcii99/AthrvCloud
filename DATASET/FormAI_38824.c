//FormAI DATASET v1.0 Category: Client Server Application ; Style: optimized
//A simple client server application where the client sends a string to the server, 
//and the server converts all the uppercase characters in the string to lowercase and sends the modified string back to the client.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    struct sockaddr_in s_address;
    int s_socket, c_socket, valread;
    char buffer[1024] = {0};
    char reply[1024] = {0};
    int opt = 1;
    int addrlen = sizeof(s_address);

    // Creating socket
    if ((s_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the specified address and port
    if (setsockopt(s_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    s_address.sin_family = AF_INET;
    s_address.sin_addr.s_addr = INADDR_ANY;
    s_address.sin_port = htons(PORT);

    // Attaching socket to the specified address and port
    if (bind(s_socket, (struct sockaddr *)&s_address,
                                 sizeof(s_address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(s_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connections
    if ((c_socket = accept(s_socket, (struct sockaddr *)&s_address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Reading data sent by client
    valread = read( c_socket , buffer, 1024);
    printf("Received: %s\n",buffer);

    // Converting uppercase characters in the received string to lowercase
    for(int i = 0; i < strlen(buffer); i++){
        if(isupper(buffer[i])){
            reply[i] = tolower(buffer[i]);
        }
        else {
            reply[i] = buffer[i];
        }
    }

    // Sending the modified string back to the client
    send(c_socket , reply , strlen(reply) , 0 );
    printf("Reply sent: %s\n", reply);

    // Closing the sockets
    close(c_socket);
    close(s_socket);
    return 0;
}