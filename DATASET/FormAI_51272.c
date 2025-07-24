//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21
#define MAX_READ_BUFFER 1024

int main(int argc, char *argv[]) {
    int sock_fd, num_bytes;
    char read_buf[MAX_READ_BUFFER];
    struct sockaddr_in server_addr;

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Read welcome message
    num_bytes = read(sock_fd, read_buf, MAX_READ_BUFFER);
    if (num_bytes < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", num_bytes, read_buf);

    // Login as anonymous user
    char user_cmd[] = "USER anonymous\r\n";
    if (write(sock_fd, user_cmd, strlen(user_cmd)) < 0) {
        perror("Error sending USER command");
        exit(EXIT_FAILURE);
    }
    num_bytes = read(sock_fd, read_buf, MAX_READ_BUFFER);
    if (num_bytes < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", num_bytes, read_buf);

    // Send password
    char pass_cmd[] = "PASS password\r\n";
    if (write(sock_fd, pass_cmd, strlen(pass_cmd)) < 0) {
        perror("Error sending PASS command");
        exit(EXIT_FAILURE);
    }
    num_bytes = read(sock_fd, read_buf, MAX_READ_BUFFER);
    if (num_bytes < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", num_bytes, read_buf);

    // Change to binary mode
    char bin_cmd[] = "TYPE I\r\n";
    if (write(sock_fd, bin_cmd, strlen(bin_cmd)) < 0) {
        perror("Error sending TYPE command");
        exit(EXIT_FAILURE);
    }
    num_bytes = read(sock_fd, read_buf, MAX_READ_BUFFER);
    if (num_bytes < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", num_bytes, read_buf);

    // Change to passive mode
    char pasv_cmd[] = "PASV\r\n";
    if (write(sock_fd, pasv_cmd, strlen(pasv_cmd)) < 0) {
        perror("Error sending PASV command");
        exit(EXIT_FAILURE);
    }
    num_bytes = read(sock_fd, read_buf, MAX_READ_BUFFER);
    if (num_bytes < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", num_bytes, read_buf);

    // Parse PASV response to get data IP and port
    char *ip1, *ip2, *ip3, *ip4, *p1, *p2;
    int data_port;
    sscanf(read_buf, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%*d,%*d)\n(%[^,],%[^,],%[^,],%[^,],%[^,],%[^)])",
           &ip1, &ip2, &ip3, &ip4, &p1, &p2);
    data_port = atoi(p1) * 256 + atoi(p2);

    // Open data connection
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    if (inet_pton(AF_INET, ip1, &data_addr.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(EXIT_FAILURE);
    }
    int data_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_fd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Error connecting to data port");
        exit(EXIT_FAILURE);
    }

    // Request file
    char retr_cmd[] = "RETR file.txt\r\n";
    if (write(sock_fd, retr_cmd, strlen(retr_cmd)) < 0) {
        perror("Error sending RETR command");
        exit(EXIT_FAILURE);
    }

    // Read file data from data connection
    FILE *outfile = fopen("file.txt", "w");
    while ((num_bytes = read(data_fd, read_buf, MAX_READ_BUFFER)) > 0) {
        fwrite(read_buf, sizeof(char), num_bytes, outfile);
    }
    fclose(outfile);
    close(data_fd);

    // Close control connection
    char quit_cmd[] = "QUIT\r\n";
    if (write(sock_fd, quit_cmd, strlen(quit_cmd)) < 0) {
        perror("Error sending QUIT command");
        exit(EXIT_FAILURE);
    }
    num_bytes = read(sock_fd, read_buf, MAX_READ_BUFFER);
    if (num_bytes < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", num_bytes, read_buf);
    close(sock_fd);

    return 0;
}