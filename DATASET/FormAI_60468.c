//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21 // FTP default control port

// Helper function to send messages to the server
void send_msg(int sockfd, char* message) {
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set address and port information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Wait for server to send welcome message
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer); // Print welcome message

    // Login to server - send username
    char username[] = "USER anonymous\r\n";
    send_msg(sockfd, username);
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer); // Print server response

    // Login to server - send password
    char password[] = "PASS ftp@example.com\r\n";
    send_msg(sockfd, password);
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer); // Print server response

    // Change directory to Downloads folder
    char change_dir[] = "CWD Downloads\r\n";
    send_msg(sockfd, change_dir);
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer); // Print server response

    // Download file example.txt
    char download[] = "RETR example.txt\r\n";
    send_msg(sockfd, download);
    FILE* fp = fopen("example.txt", "w"); // Open file to write contents
    int nbytes;
    while ((nbytes = recv(sockfd, buffer, 1024, 0)) > 0) {
        fwrite(buffer, 1, nbytes, fp); // Write contents to file
    }
    fclose(fp);

    // Logout from server
    char quit[] = "QUIT\r\n";
    send_msg(sockfd, quit);
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer); // Print server response

    // Close socket
    close(sockfd);

    return 0;
}