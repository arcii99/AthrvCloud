//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080

void romeo_and_juliet(int sockfd) {
    char buffer[1024];
    char romeo_msg[1024] = "Oh, Juliet, dear Juliet! How my heart aches for thee!\n";
    char juliet_msg[1024] = "My Romeo, my love! I long for you every moment we are apart.\n";
    int n;

    // Romeo sends first message to Juliet
    write(sockfd, romeo_msg, strlen(romeo_msg));
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    printf("Juliet: %s", buffer);

    // Juliet sends message back to Romeo
    write(sockfd, juliet_msg, strlen(juliet_msg));
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    printf("Romeo: %s", buffer);

    // Repeat until error or close
    while(1) {
        memset(buffer, 0, sizeof(buffer));

        // Handling errors
        if ((n = read(sockfd, buffer, sizeof(buffer))) <= 0) {
            if (n == 0) {
                printf("Connection closed.\n");
            } else {
                perror("Error while receiving message.\n");
            }
            break;
        }

        printf("Juliet: %s", buffer);
        while (fgets(buffer, 1024, stdin)) {
            char* end = strchr(buffer, '\n');
            if (end) {
                *end = '\0';
            } else {
                buffer[sizeof(buffer) - 1] = '\0';
            }

            // Romeo says farewell and closes connection
            if (strcasecmp(buffer, "farewell") == 0) {
                printf("Romeo: Farewell my sweet Juliet. I shall love thee forevermore.\n");
                close(sockfd);
                exit(0);
            }

            // Romeo sends message to Juliet
            write(sockfd, buffer, strlen(buffer));
            memset(buffer, 0, sizeof(buffer));
            n = read(sockfd, buffer, sizeof(buffer));
            printf("Juliet: %s", buffer);
        }
    }
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Assigning IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connecting to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed.\n");
        exit(EXIT_FAILURE);
    }

    // Starting Romeo and Juliet chat
    romeo_and_juliet(sockfd);

    // Closing the socket
    close(sockfd);
    return 0;
}