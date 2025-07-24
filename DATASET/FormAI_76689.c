//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define PROXY_IP "192.168.1.1"
#define PROXY_PORT 8888

int main(int argc, char* argv[])
{
    //Create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0)
    {
        printf("Failed to create socket\n");
        return -1;
    }

    struct sockaddr_in proxy_address;
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = inet_addr(PROXY_IP);
    proxy_address.sin_port = htons(PROXY_PORT);

    //Connect to the proxy server
    int connect_status = connect(client_socket, (struct sockaddr*) &proxy_address, sizeof(proxy_address));
    if(connect_status < 0)
    {
        printf("Failed to connect to the proxy server\n");
        return -1;
    }

    //Send HTTP GET request to the server
    char* message = "GET / HTTP/1.1\r\nHost: " SERVER_IP "\r\n\r\n";
    if(send(client_socket, message, strlen(message), 0) < 0)
    {
        printf("Failed to send GET request\n");
        return -1;
    }

    //Receive response from the server
    char response[1024];
    memset(response, 0, sizeof(response));
    if(recv(client_socket, response, sizeof(response), 0) < 0)
    {
        printf("Failed to receive response\n");
        return -1;
    }

    printf("Response from the server:\n%s\n", response);

    //Close the client socket
    close(client_socket);

    return 0;
}