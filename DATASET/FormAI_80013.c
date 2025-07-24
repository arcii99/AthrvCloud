//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>

#define SERVER "ftp.server.com"
#define PORT 21

int main(int argc, char **argv) {

    // Establish connection to FTP server
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error: Could not create socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0) {
        perror("Error: Could not connect to server");
        return -1;
    }

    // Log in to FTP server
    char username[50], password[50], buffer[256];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    sprintf(buffer, "USER %s", username);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: Could not send username to server");
        return -1;
    }

    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Could not receive response from server");
        return -1;
    }

    sprintf(buffer, "PASS %s", password);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: Could not send password to server");
        return -1;
    }

    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Could not receive response from server");
        return -1;
    }

    // Read user command and send to FTP server
    char command[50];

    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);

    if(send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error: Could not send command to server");
        return -1;
    }

    memset(buffer, 0, sizeof(buffer));
    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error: Could not receive response from server");
        return -1;
    }

    printf("%s", buffer);

    return 0;
}