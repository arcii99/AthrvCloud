//FormAI DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
// Romeo.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
        perror("Could not create socket");

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        perror("Could not bind socket");

    if(listen(sock, 5) < 0)
        perror("Could not listen to socket");


    struct sockaddr_in client_address;
    int client_address_length = sizeof(client_address);
    int client_sock = accept(sock, (struct sockaddr *)&client_address, &client_address_length);
    if(client_sock < 0)
        perror("Could not accept client connection");

    char message[256];
    while(1)
    {
        bzero(message, 256);
        read(client_sock, message, 256);

        printf("Juliet: Dear Romeo, you sent me: %s\n", message);

        if(strncmp("exit", message, 4) == 0)
            break;

        printf("Juliet: Write some code for me, Romeo: ");

        bzero(message, 256);
        fgets(message, 256, stdin);

        write(client_sock, message, strlen(message));
    }

    close(client_sock);
    close(sock);

    return 0;
}