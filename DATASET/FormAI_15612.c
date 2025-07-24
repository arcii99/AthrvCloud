//FormAI DATASET v1.0 Category: Client Server Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    // Setting up server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Establishing connection
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Connection failed.\n");
        exit(1);
    }

    // Receiving init message from server
    char init_msg[25];
    read(sockfd, init_msg, sizeof(init_msg));
    printf("Server: %s\n", init_msg);

    // Sending username to server
    char username[25];
    printf("\nEnter username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n"); // Removing newline character
    write(sockfd, username, strlen(username));

    // Receiving password prompt from server
    char password_prompt[50];
    read(sockfd, password_prompt, sizeof(password_prompt));
    printf("\nServer: %s", password_prompt);

    // Sending password to server
    char password[25];
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n"); // Removing newline character
    write(sockfd, password, strlen(password));

    // Receiving login result from server
    char login_res[25];
    read(sockfd, login_res, sizeof(login_res));
    if (strcmp(login_res, "SUCCESS") == 0) {
        printf("\n\nServer: Welcome %s!\n", username);
    } else {
        printf("\n\nServer: Access denied.\n");
    }

    close(sockfd);
    return 0;
}