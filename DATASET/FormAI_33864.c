//FormAI DATASET v1.0 Category: Simple Web Server ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main()
{
    //create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //define the server address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    //listen for incoming connections
    listen(server_socket, 5);

    //accept incoming connections
    int client_socket;
    while(1)
    {
        client_socket = accept(server_socket, NULL, NULL);

        //send HTTP response
        char response[1024] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from your Simple Web Server!";
        send(client_socket, response, strlen(response), 0);

        //close the socket
        close(client_socket);
    }

    //close the server socket
    close(server_socket);

    return 0;
}