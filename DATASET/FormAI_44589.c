//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 8192

void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname username password\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }
    
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(143);

    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }
    
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        error("Error reading from server");
    }
    
    char login_command[MAX_BUFFER_SIZE];
    snprintf(login_command, MAX_BUFFER_SIZE, ". login %s %s\n", username, password);
    
    if (write(sockfd, login_command, strlen(login_command)) < 0) {
        error("Error writing to server");
    }
    
    memset(buffer, 0, MAX_BUFFER_SIZE);
    
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        error("Error reading from server");
    }
    
    if (!strstr(buffer, "OK")) {
        error("Error logging in");
    }
    
    while (true) {
        printf("> ");
        memset(buffer, 0, MAX_BUFFER_SIZE);
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        
        char *command = strtok(buffer, " ");
        
        if (strcmp(command, "list") == 0) {
            if (write(sockfd, ". list \"\" *\n", strlen(". list \"\" *\n")) < 0) {
                error("Error writing to server");
            }
            
            memset(buffer, 0, MAX_BUFFER_SIZE);
            
            if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
                error("Error reading from server");
            }
            
            printf("%s", buffer);
        } else if (strcmp(command, "select") == 0) {
            char *mailbox = strtok(NULL, " ");
            char select_command[MAX_BUFFER_SIZE];
            snprintf(select_command, MAX_BUFFER_SIZE, ". select %s\n", mailbox);
            
            if (write(sockfd, select_command, strlen(select_command)) < 0) {
                error("Error writing to server");
            }
            
            memset(buffer, 0, MAX_BUFFER_SIZE);
            
            if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
                error("Error reading from server");
            }
            
            printf("%s", buffer);
        } else if (strcmp(command, "logout") == 0) {
            if (write(sockfd, ". logout\n", strlen(". logout\n")) < 0) {
                error("Error writing to server");
            }
            
            memset(buffer, 0, MAX_BUFFER_SIZE);
            
            if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
                error("Error reading from server");
            }
            
            if (strstr(buffer, "BYE")) {
                break;
            }
        } else {
            printf("Unknown command.\n");
        }
    }
    
    close(sockfd);
    
    return 0;
}