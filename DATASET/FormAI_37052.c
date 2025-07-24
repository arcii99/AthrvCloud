//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE_LENGTH 1024
#define MAX_BUFFER_SIZE 65535

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_address> <user_name> <password>\n", argv[0]);
        exit(1);
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    char *server_address = argv[1];
    int server_port = 993;

    // Convert server address to network byte order and build the server address structure
    struct in_addr ip_address;
    if (inet_pton(AF_INET, server_address, &ip_address) != 1) {
        fprintf(stderr, "Invalid server address: %s\n", server_address);
        exit(1);
    }
    struct sockaddr_in server_address_in;
    memset(&server_address_in, 0, sizeof(server_address_in));
    server_address_in.sin_family = AF_INET;
    server_address_in.sin_port = htons(server_port);
    server_address_in.sin_addr = ip_address;

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address_in, sizeof(server_address_in)) == -1) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Receive greeting message from the server
    char buffer[MAX_BUFFER_SIZE];
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive greeting message from server");
        exit(1);
    }
    printf("%s", buffer);

    // Login with user name and password
    char user_name[MAX_LINE_LENGTH];
    char password[MAX_LINE_LENGTH];
    snprintf(user_name, MAX_LINE_LENGTH, "%s", argv[2]);
    snprintf(password, MAX_LINE_LENGTH, "%s", argv[3]);

    char login_command[MAX_LINE_LENGTH];
    snprintf(login_command, MAX_LINE_LENGTH, "LOGIN %s %s\r\n", user_name, password);

    if (send(socket_fd, login_command, strlen(login_command), 0) == -1) {
        perror("Failed to send login command to server");
        exit(1);
    }

    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive response for login command from server");
        exit(1);
    }
    printf("%s", buffer);

    // List all mailbox folders
    char list_command[MAX_LINE_LENGTH];
    snprintf(list_command, MAX_LINE_LENGTH, "list \"\" *\r\n");

    if (send(socket_fd, list_command, strlen(list_command), 0) == -1) {
        perror("Failed to send list command to server");
        exit(1);
    }

    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive response for list command from server");
        exit(1);
    }
    printf("%s", buffer);

    // Select a mailbox folder
    char mailbox_name[MAX_LINE_LENGTH] = "INBOX";
    char select_command[MAX_LINE_LENGTH];
    snprintf(select_command, MAX_LINE_LENGTH, "select \"%s\"\r\n", mailbox_name);

    if (send(socket_fd, select_command, strlen(select_command), 0) == -1) {
        perror("Failed to send select command to server");
        exit(1);
    }

    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive response for select command from server");
        exit(1);
    }
    printf("%s", buffer);

    // Search for all unseen messages
    char unseen_search_command[MAX_LINE_LENGTH];
    snprintf(unseen_search_command, MAX_LINE_LENGTH, "tag UID SEARCH UNSEEN\r\n");

    if (send(socket_fd, unseen_search_command, strlen(unseen_search_command), 0) == -1) {
        perror("Failed to send search command to server");
        exit(1);
    }

    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive response for search command from server");
        exit(1);
    }

    // Parse the search result
    char *start_p = strstr(buffer, "SEARCH ");
    if (start_p == NULL) {
        fprintf(stderr, "Failed to parse search result\n");
        exit(1);
    }
    start_p += strlen("SEARCH ");
    char *end_p = strchr(start_p, '\r');
    if (end_p == NULL) {
        fprintf(stderr, "Failed to parse search result\n");
        exit(1);
    }
    *end_p = '\0';

    // Fetch all unseen messages
    char fetch_command[MAX_LINE_LENGTH];
    snprintf(fetch_command, MAX_LINE_LENGTH, "tag UID FETCH %s BODY[HEADER]\r\n", start_p);

    if (send(socket_fd, fetch_command, strlen(fetch_command), 0) == -1) {
        perror("Failed to send fetch command to server");
        exit(1);
    }

    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive response for fetch command from server");
        exit(1);
    }
    printf("%s", buffer);

    // Logout and close the connection
    char logout_command[MAX_LINE_LENGTH] = "LOGOUT\r\n";

    if (send(socket_fd, logout_command, strlen(logout_command), 0) == -1) {
        perror("Failed to send logout command to server");
        exit(1);
    }

    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Failed to receive response for logout command from server");
        exit(1);
    }
    printf("%s", buffer);

    close(socket_fd);

    return 0;
}