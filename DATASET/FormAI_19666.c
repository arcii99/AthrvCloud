//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define IMAP_PORT 143

// Global variables
int sockfd;
char buf[BUF_SIZE];
char username[BUF_SIZE];
char password[BUF_SIZE];
int current_msg_id;

// Prototypes
void connect_to_server();
void login();
void logout();
void send_command(char *command);
void list_messages();
void display_message(char *msg_id);

int main() {
    printf("Welcome to the multiplayer IMAP client!\n");
    printf("Please enter your username: ");
    fgets(username, BUF_SIZE, stdin);
    strtok(username, "\n");  // remove newline character from username
    
    printf("Please enter your password: ");
    fgets(password, BUF_SIZE, stdin);
    strtok(password, "\n");  // remove newline character from password
    
    connect_to_server();
    login();
    
    while (1) {
        printf("> ");
        fgets(buf, BUF_SIZE, stdin);
        strtok(buf, "\n");  // remove newline character from command
        
        if (strcmp(buf, "list") == 0) {
            list_messages();
        } else if (strncmp(buf, "view ", 5) == 0) {
            display_message(buf + 5);
        } else if (strcmp(buf, "logout") == 0) {
            logout();
            break;
        } else {
            send_command(buf);
        }
    }
    
    printf("Goodbye!\n");
    close(sockfd);
    
    return 0;
}

void connect_to_server() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect() error");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to server!\n");
}

void login() {
    sprintf(buf, "login %s %s", username, password);
    send_command(buf);
    recv(sockfd, buf, BUF_SIZE, 0);  // receive server response
    printf("%s\n", buf);
}

void logout() {
    send_command("logout");
    recv(sockfd, buf, BUF_SIZE, 0);  // receive server response
    printf("%s\n", buf);
}

void send_command(char *command) {
    sprintf(buf, "%d %s", ++current_msg_id, command);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, BUF_SIZE, 0);  // receive server response
    printf("%s\n", buf);
}

void list_messages() {
    send_command("list");
    recv(sockfd, buf, BUF_SIZE, 0);  // receive server response
    printf("%s", buf);
}

void display_message(char *msg_id) {
    sprintf(buf, "view %s", msg_id);
    send_command(buf);
    recv(sockfd, buf, BUF_SIZE, 0);  // receive server response
    printf("%s\n", buf);
}