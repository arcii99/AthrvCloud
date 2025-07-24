//FormAI DATASET v1.0 Category: Networking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 4444

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int n;

    /* Open a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Initialize server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Connect to the server */
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Surrealist Networking Program\n");

    while (1)
    {
        printf("\nEnter your message: ");

        /* Read message from user */
        bzero(buffer, 1024);
        fgets(buffer, 1024, stdin);

        /* Send message to server */
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0)
        {
            perror("Error writing to socket");
            break;
        }

        /* Read server response */
        bzero(buffer, 1024);
        n = read(sockfd, buffer, 1024);

        if (n < 0)
        {
            perror("Error reading from socket");
            break;
        }

        /* Print server response */
        printf("Server response: %s", buffer);
    }

    /* Close socket */
    close(sockfd);

    return 0;
}