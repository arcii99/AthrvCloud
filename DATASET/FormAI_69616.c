//FormAI DATASET v1.0 Category: Simple Web Server ; Style: scientific
/* Title: Simple Web Server
 * Description: A C program that acts as a simple web server
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

// Function prototypes
void error(const char *);
void send_file(int, char *);
void send_response(int, char *);
void process_request(int);

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    socklen_t clilen;
    struct sockaddr_in server_address, client_address;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error opening socket");
    }

    // Set server address
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));

    // Bind socket to server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    clilen = sizeof(client_address);

    // Accept and handle incoming connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &clilen);
        if (client_socket < 0) {
            error("Error accepting connection");
        }

        process_request(client_socket);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}

/* Function: error
 * Description: Prints an error message to stderr and exits the program
 * Input: char *msg - the error message to print
 * Output: None
 */
void error(const char *msg) {
    perror(msg);
    exit(1);
}

/* Function: send_file
 * Description: Sends the contents of a file to a client socket
 * Input: int client_socket - the client socket file descriptor
 *        char *filename - the name of the file to send
 * Output: None
 */
void send_file(int client_socket, char *filename) {
    int fd;
    ssize_t n;
    char buffer[BUFFER_SIZE];

    // Open file
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        error("Error opening file");
    }

    // Read file contents and send to client socket
    while ((n = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(client_socket, buffer, n) < 0) {
            error("Error writing to socket");
        }
    }

    close(fd);
}

/* Function: send_response
 * Description: Sends an HTTP response to a client socket
 * Input: int client_socket - the client socket file descriptor
 *        char *response - the HTTP response string to send
 * Output: None
 */
void send_response(int client_socket, char *response) {
    if (write(client_socket, response, strlen(response)) < 0) {
        error("Error writing to socket");
    }
}

/* Function: process_request
 * Description: Reads and processes an HTTP request from a client socket
 * Input: int client_socket - the client socket file descriptor
 * Output: None
 */
void process_request(int client_socket) {
    ssize_t n;
    char buffer[BUFFER_SIZE], *filename;
    int i;

    // Read HTTP request
    bzero(buffer, BUFFER_SIZE);
    n = read(client_socket, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("Error reading from socket");
    }

    // Parse filename from HTTP request
    filename = strtok(buffer, " ");
    filename = strtok(NULL, " ");

    // Check if file exists
    if (access(filename, F_OK) == -1) {
        send_response(client_socket, "HTTP/1.1 404 Not Found\r\n\r\n");
    } else {
        send_response(client_socket, "HTTP/1.1 200 OK\r\n\r\n");
        send_file(client_socket, filename);
    }
}