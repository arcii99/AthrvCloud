//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 21
#define BUFFER_SIZE 1024

/**
 * This function establishes a connection with the FTP server and
 * returns the socket file descriptor.
 */
int connect_to_server() {
    struct sockaddr_in server_addr;
    int sock_fd;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    return sock_fd;
}

/**
 * This function logs in to the FTP server using the given username
 * and password.
 */
void ftp_login(int sock_fd, const char *username, const char *password) {
    char user_command[BUFFER_SIZE];
    char pass_command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    sprintf(user_command, "USER %s\r\n", username);
    sprintf(pass_command, "PASS %s\r\n", password);

    /* Send the username command */
    send(sock_fd, user_command, strlen(user_command), 0);
    recv(sock_fd, response, BUFFER_SIZE, 0);
    printf("Response: %s", response);

    /* Send the password command */
    send(sock_fd, pass_command, strlen(pass_command), 0);
    recv(sock_fd, response, BUFFER_SIZE, 0);
    printf("Response: %s", response);
}

/**
 * This function retrieves a file from the FTP server and saves it
 * to the local machine.
 */
void ftp_get(int sock_fd, const char *remote_filename, const char *local_filename) {
    char pasv_command[] = "PASV\r\n";
    char retr_command[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    int data_sock_fd, bytes_received;
    FILE *local_file;

    sprintf(retr_command, "RETR %s\r\n", remote_filename);

    /* Send PASV command to get the data port */
    send(sock_fd, pasv_command, strlen(pasv_command), 0);
    recv(sock_fd, response, BUFFER_SIZE, 0);

    /* Parse the response to get the data port */
    char *token;
    int port;
    token = strtok(response, ",");
    for (int i = 0; i < 4; i++) {
        token = strtok(NULL, ",");
    }
    port = atoi(token) * 256;
    token = strtok(NULL, ",");
    port += atoi(token);

    /* Establish the data connection */
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    inet_pton(AF_INET, SERVER_ADDR, &data_addr.sin_addr);
    if ((data_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    if (connect(data_sock_fd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    /* Send the RETR command */
    send(sock_fd, retr_command, strlen(retr_command), 0);
    recv(sock_fd, response, BUFFER_SIZE, 0);
    printf("Response: %s", response);

    /* Read data from the data port and save it to a file */
    if ((local_file = fopen(local_filename, "wb")) == NULL) {
        perror("Failed to open local file");
        exit(EXIT_FAILURE);
    }
    while ((bytes_received = recv(data_sock_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, local_file);
    }
    fclose(local_file);

    /* Close the data connection */
    close(data_sock_fd);

    /* Check the final response after finishing the RETR command */
    recv(sock_fd, response, BUFFER_SIZE, 0);
    printf("Response: %s", response);
}

/**
 * This function logs out of the FTP server.
 */
void ftp_logout(int sock_fd) {
    char quit_command[] = "QUIT\r\n";
    char response[BUFFER_SIZE];

    send(sock_fd, quit_command, strlen(quit_command), 0);
    recv(sock_fd, response, BUFFER_SIZE, 0);
    printf("Response: %s", response);

    close(sock_fd);
}

int main() {
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char remote_filename[BUFFER_SIZE];
    char local_filename[BUFFER_SIZE];

    printf("Enter your username: ");
    fgets(username, BUFFER_SIZE, stdin);
    strtok(username, "\n");  // remove the newline character
    printf("Enter your password: ");
    fgets(password, BUFFER_SIZE, stdin);
    strtok(password, "\n");  // remove the newline character
    printf("Enter the remote filename: ");
    fgets(remote_filename, BUFFER_SIZE, stdin);
    strtok(remote_filename, "\n");  // remove the newline character
    printf("Enter the local filename: ");
    fgets(local_filename, BUFFER_SIZE, stdin);
    strtok(local_filename, "\n");  // remove the newline character

    /* Connect to the FTP server */
    int sock_fd = connect_to_server();

    /* Login with the given username and password */
    ftp_login(sock_fd, username, password);

    /* Retrieve the file and save it to the local machine */
    ftp_get(sock_fd, remote_filename, local_filename);

    /* Logout of the FTP server */
    ftp_logout(sock_fd);

    return 0;
}