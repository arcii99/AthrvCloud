//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_PACKET_SIZE 1024

void* receiver(void* arg);
void* sender(void* arg);

int main() {
    int sockfd, ret;
    struct sockaddr_in client_addr;
    pthread_t r_thread, s_thread;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket!\n");
        exit(1);
    }
    printf("Socket created...\n");

    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr*)&client_addr, sizeof(client_addr));
    if (ret < 0) {
        printf("Error connecting to the server!\n");
        exit(1);
    }
    printf("Connected to the server...\n");
    
    pthread_create(&r_thread, NULL, receiver, (void*)&sockfd);
    pthread_create(&s_thread, NULL, sender, (void*)&sockfd);

    pthread_join(r_thread, NULL);
    pthread_join(s_thread, NULL);

    close(sockfd);
    printf("Exiting...\n");

    return 0;
}

void* receiver(void* arg) {
    int sockfd = *((int*)arg);
    char buffer[MAX_PACKET_SIZE];
    int n = 0;

    while (1) {
        n = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);

        if (n < 0) {
            printf("Error receiving data!\n");
            break;
        }

        printf("Received: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
}

void* sender(void* arg) {
    int sockfd = *((int*)arg);
    char buffer[MAX_PACKET_SIZE];
    int n = 0;
    
    while (1) {
        printf("Enter message: ");
        fgets(buffer, MAX_PACKET_SIZE, stdin);

        n = send(sockfd, buffer, strlen(buffer), 0);

        if (n < 0) {
            printf("Error sending data!\n");
            break;
        }
    }
}