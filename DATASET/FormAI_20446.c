//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21

/* Function to connect to the FTP server */
int connectFTP(char* ip) {
    int sockfd;
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket\n");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(FTP_PORT);
    inet_pton(AF_INET, ip, &server.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error connecting to FTP server\n");
        return -1;
    }

    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error receiving message from FTP server\n");
        return -1;
    }

    printf("%s\n", buffer);

    return sockfd;
}

/* Function to log into the FTP server */
int loginFTP(int sockfd, const char* username, const char* password) {
    char buffer[1024];
    int n;

    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending username to FTP server\n");
        return -1;
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error receiving message from FTP server\n");
        return -1;
    }

    printf("%s\n", buffer);

    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending password to FTP server\n");
        return -1;
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error receiving message from FTP server\n");
        return -1;
    }

    printf("%s\n", buffer);

    if (buffer[0] == '5' && buffer[1] == '3' && buffer[2] == '0') {
        printf("Invalid username or password\n");
        return -1;
    }

    return 0;
}

/* Function to send a command to the FTP server */
int sendCommand(int sockfd, char* command) {
    char buffer[1024];
    int n;

    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending command to FTP server\n");
        return -1;
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error receiving message from FTP server\n");
        return -1;
    }

    printf("%s\n", buffer);

    return 0;
}

/* Function to download a file from the FTP server */
int downloadFTP(int sockfd, char* filename) {
    char buffer[1024];
    int n;

    snprintf(buffer, sizeof(buffer), "TYPE I\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending command to FTP server\n");
        return -1;
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error receiving message from FTP server\n");
        return -1;
    }

    printf("%s\n", buffer);

    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file\n");
        return -1;
    }

    snprintf(buffer, sizeof(buffer), "RETR %s\r\n", filename);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending command to FTP server\n");
        return -1;
    }

    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }

    fclose(fp);

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error receiving message from FTP server\n");
        return -1;
    }

    printf("%s\n", buffer);

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: %s <IP address> <username> <password> <filename>\n", argv[0]);
        return 0;
    }

    char* ip = argv[1];
    char* username = argv[2];
    char* password = argv[3];
    char* filename = argv[4];

    int sockfd = connectFTP(ip);
    if (sockfd < 0) {
        return 0;
    }

    if (loginFTP(sockfd, username, password) < 0) {
        close(sockfd);
        return 0;
    }

    if (downloadFTP(sockfd, filename) < 0) {
        close(sockfd);
        return 0;
    }

    close(sockfd);

    return 0;
}