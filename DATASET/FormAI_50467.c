//FormAI DATASET v1.0 Category: Client Server Application ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>

#define PORT 8080
#define MESSAGE_LENGTH 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    int sockfd, newsockfd;
    int opt = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }

    memset(&server_address, '\0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0)
    {
        error("ERROR on binding");
    }

    if (listen(sockfd, 5) < 0)
    {
        error("ERROR on listening");
    }

    printf("Server is running and listening on port %d...\n", PORT);

    while(1) 
    {
        newsockfd = accept(sockfd, (struct sockaddr*) &client_address, &client_len);
        if (newsockfd < 0)
        {
            error("ERROR on accept");
        }

        char message[MESSAGE_LENGTH];
        memset(message, 0, MESSAGE_LENGTH);
        int read_status = read(newsockfd, message, MESSAGE_LENGTH);
        if (read_status < 0)
        {
            error("ERROR reading from socket");
        }

        printf("Message received from client: %s\n", message);

        char response[MESSAGE_LENGTH];
        memset(response, 0, MESSAGE_LENGTH);
        strcpy(response, "Hello from server!");

        int write_status = write(newsockfd, response, strlen(response));
        if (write_status < 0)
        {
            error("ERROR writing to socket");
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}