//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

int main()
{
    int sockfd = 0;
    char buf[MAX_BUF_SIZE] = {0};
    char filename[20] = {0};
    char recv_data[MAX_BUF_SIZE] = {0};
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send username and password
    sprintf(buf, "USER %s\r\n", "USERNAME");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, recv_data, MAX_BUF_SIZE, 0);
    printf("Response: %s\n", recv_data);

    sprintf(buf, "PASS %s\r\n", "PASSWORD");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, recv_data, MAX_BUF_SIZE, 0);
    printf("Response: %s\n", recv_data);

    // Set transfer mode to binary
    sprintf(buf, "TYPE I\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, recv_data, MAX_BUF_SIZE, 0);
    printf("Response: %s\n", recv_data);

    // Enter passive mode
    sprintf(buf, "PASV\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, recv_data, MAX_BUF_SIZE, 0);
    printf("Response: %s\n", recv_data);

    // Extract the server IP and port from the PASV response
    int start = strchr(recv_data, '(') - recv_data + 1;
    int end = strchr(recv_data, ')') - recv_data;
    char addr_port[MAX_BUF_SIZE] = {0};
    strncpy(addr_port, &recv_data[start], end - start);
    char *addr_port_split = strtok(addr_port, ",");
    char server_ip[16] = {0};
    for (int i = 0; i < 4; ++i)
    {
        strcat(server_ip, addr_port_split);
        if (i != 3)
        {
            strcat(server_ip, ".");
        }
        addr_port_split = strtok(NULL, ",");
    }
    addr_port_split = strtok(NULL, ",");
    int server_port = atoi(addr_port_split) * 256;
    addr_port_split = strtok(NULL, ",");
    server_port += atoi(addr_port_split);

    // Connect to the server in passive mode
    struct sockaddr_in serv_data_addr;
    serv_data_addr.sin_family = AF_INET;
    serv_data_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &serv_data_addr.sin_addr) <= 0)
    {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    int sockfd_data = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sockfd_data, (struct sockaddr *)&serv_data_addr, sizeof(serv_data_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "RETR %s", "filename.txt");
    send(sockfd, buf, strlen(buf), 0);

    // Check if file exists
    recv(sockfd, recv_data, MAX_BUF_SIZE, 0);
    if (recv_data[0] == '5')
    {
        printf("File not found on server\n");
        return EXIT_FAILURE;
    }

    // Receive file from server
    FILE *fp = fopen("filename.txt", "w");
    while (1)
    {
        ssize_t num_bytes = recv(sockfd_data, buf, MAX_BUF_SIZE, 0);
        if (num_bytes == 0)
        {
            break;
        }
        fwrite(buf, sizeof(char), num_bytes, fp);
    }
    printf("File received successfully from server\n");

    // Close socket and file
    close(sockfd);
    close(sockfd_data);
    fclose(fp);

    return EXIT_SUCCESS;
}