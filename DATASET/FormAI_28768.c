//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER "mail.example.com"
#define PORT 110

void *recv_messages(void *);
void *send_messages(void *);

int main()
{
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Login credentials
    char *username = "exampleuser";
    char *password = "examplepassword";

    // Send login credentials
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    // Create threads for sending and receiving
    pthread_t recv_thread, send_thread;
    pthread_create(&recv_thread, NULL, recv_messages, &sockfd);
    pthread_create(&send_thread, NULL, send_messages, &sockfd);

    // Wait for threads to finish
    pthread_join(send_thread, NULL);
    pthread_join(recv_thread, NULL);

    // Close socket
    close(sockfd);

    return 0;
}

void *recv_messages(void *arg)
{
    int sockfd = *(int *) arg;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (1)
    {
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    pthread_exit(NULL);
}

void *send_messages(void *arg)
{
    int sockfd = *(int *) arg;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (1)
    {
        fgets(buffer, 1024, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }

    pthread_exit(NULL);
}