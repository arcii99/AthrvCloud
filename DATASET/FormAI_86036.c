//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int proxy_socket, client_socket, opt = 1;
    struct sockaddr_in proxy_address, client_address;
    char buffer[1024];

    // create proxy socket
    if ((proxy_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set proxy socket options
    if (setsockopt(proxy_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(PORT);

    // bind proxy socket to address and port
    if (bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(proxy_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server running on port %d...\n", PORT);

    // accept incoming connections and forward requests
    while (1)
    {
        int addr_len = sizeof(client_address);
        if ((client_socket = accept(proxy_socket, (struct sockaddr *)&client_address, (socklen_t*)&addr_len)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Request received from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // receive request
        memset(buffer, 0, sizeof(buffer));
        if (recv(client_socket, buffer, sizeof(buffer), 0) < 0)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        // print request
        printf("%s\n", buffer);

        // forward request to server
        int server_socket;
        struct sockaddr_in server_address;
        char *server_ip = "127.0.0.1";
        int server_port = 80;

        // create server socket
        if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr(server_ip);
        server_address.sin_port = htons(server_port);

        // connect to server
        if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        {
            perror("connect failed");
            exit(EXIT_FAILURE);
        }

        // send request to server
        if (send(server_socket, buffer, strlen(buffer), 0) < 0)
        {
            perror("send");
            exit(EXIT_FAILURE);
        }

        // receive response from server
        memset(buffer, 0, sizeof(buffer));
        if (recv(server_socket, buffer, sizeof(buffer), 0) < 0)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        // print response
        printf("%s\n", buffer);

        // send response to client
        if (send(client_socket, buffer, strlen(buffer), 0) < 0)
        {
            perror("send");
            exit(EXIT_FAILURE);
        }

        // close sockets
        close(client_socket);
        close(server_socket);
    }

    return 0;
}