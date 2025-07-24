//FormAI DATASET v1.0 Category: Networking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main()
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buff[1024];

    // surrealist address
    char *addr = "0x3a9e8c2476de";

    // surreal phone number
    char *phone_num = "867-5309";

    // surreal message to server
    char *message = "The moon is made of cheese.";

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    // surreal address conversion
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    if (inet_pton(AF_INET, addr, &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    // surreal connection
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("connection failed");
        exit(1);
    }

    // surreal phone call
    printf("Calling %s...\n", phone_num);
    printf("Connected.\n");

    // surreal message transmission
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("send error");
        exit(1);
    }

    printf("Message Sent: %s\n", message);

    // surreal message receive
    memset(buff, 0, sizeof(buff));
    n = recv(sockfd, buff, sizeof(buff), 0);
    if (n < 0) {
        perror("recv error");
        exit(1);
    }

    printf("Received Message: %s\n", buff);

    // surreal disconnection
    printf("Call ended.\n");

    close(sockfd);

    return 0;
}