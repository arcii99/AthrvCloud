//FormAI DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

int main() {
    int sockfd, newsockfd, client_length, message_length;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_MSG_LEN];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    int binding_status = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (binding_status < 0) {
        printf("Error binding socket");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        printf("Error listening incoming requests");
        exit(1);
    }

    printf("Puzzle Time: Can you guess the word I am thinking of?\n");
    printf("(Hint: It's a 5-letter word that starts with 'S')\n");
    while(1) {
        client_length = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_length);

        message_length = read(newsockfd, buffer, MAX_MSG_LEN);
        buffer[message_length] = '\0';

        if(strcmp(buffer, "START") == 0) {
            write(newsockfd, "GUESS: ", strlen("GUESS:"));

            message_length = read(newsockfd, buffer, MAX_MSG_LEN);
            buffer[message_length] = '\0';

            if(strcmp(buffer, "SHIRT") == 0) {
                write(newsockfd, "YOU GUESSED IT RIGHT!", strlen("YOU GUESSED IT RIGHT!"));
                close(newsockfd);
                exit(0);
            } else {
                write(newsockfd, "WRONG ANSWER. TRY AGAIN LATER!", strlen("WRONG ANSWER. TRY AGAIN LATER!"));
                close(newsockfd);
                exit(1);
            }
        } else {
            write(newsockfd, "INVALID COMMAND. TRY AGAIN LATER!", strlen("INVALID COMMAND. TRY AGAIN LATER!"));
            close(newsockfd);
            exit(1);
        }
    }
    close(sockfd);
    return 0;
}