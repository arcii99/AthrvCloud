//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 65535

struct imaps_client {
    char *server;
    char *username;
    char *password;
    int port;
    int sockfd;
};

int connect_to_server(struct imaps_client *client) {
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(client->port);
    inet_pton(AF_INET, client->server, &server_address.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection to server failed");
        return -1;
    }

    client->sockfd = sockfd;
    return 0;
}

int login_to_server(struct imaps_client *client) {
    char buffer[MAX_BUFFER_SIZE];
    char command[MAX_BUFFER_SIZE];

    // Send login command
    sprintf(command, "LOGIN %s %s\r\n", client->username, client->password);
    send(client->sockfd, command, strlen(command), 0);

    // Receive response
    memset(buffer, 0, MAX_BUFFER_SIZE);
    recv(client->sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Parse response
    char *response = strstr(buffer, "OK");
    if (response == NULL) {
        printf("Login failed.\n");
        return -1;
    }

    printf("Login successful.\n");
    return 0;
}

int fetch_emails(struct imaps_client *client) {
    char buffer[MAX_BUFFER_SIZE];
    char command[MAX_BUFFER_SIZE];

    // Send fetch command
    sprintf(command, "FETCH 1:* (BODY[HEADER.FIELDS (DATE SUBJECT FROM)])\r\n");
    send(client->sockfd, command, strlen(command), 0);

    // Receive response
    memset(buffer, 0, MAX_BUFFER_SIZE);
    recv(client->sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Parse response
    char *response = strstr(buffer, "OK");
    if (response == NULL) {
        printf("Fetch failed.\n");
        return -1;
    }

    printf("Emails fetched successfully:\n");
    printf("%s", buffer);
    return 0;
}

void print_usage() {
    printf("Usage: ./imaps_client <server> <username> <password> <port>\n");
}

int main(int argc, char **argv) {
    if (argc != 5) {
        print_usage();
        return -1;
    }

    struct imaps_client client;
    client.server = argv[1];
    client.username = argv[2];
    client.password = argv[3];
    client.port = atoi(argv[4]);

    if (connect_to_server(&client) < 0) {
        return -1;
    }

    if (login_to_server(&client) < 0) {
        return -1;
    }

    if (fetch_emails(&client) < 0) {
        return -1;
    }

    // Close socket and exit
    close(client.sockfd);
    return 0;
}