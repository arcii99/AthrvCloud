//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: distributed
// Include header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define FTP_PORT 21

int main()
{
    int sock_fd, n, flag = 0;
    const char *host = "localhost";
    struct sockaddr_in server_addr;
    char buffer[1024];
    
    // Create socket
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    if(inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0)
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    if(connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }
    
    // Receive server response
    n = read(sock_fd, buffer, sizeof(buffer));
    if(n < 0)
    {
        perror("Error reading response from server");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Login to server
    char *username = "USERNAME_HERE";
    char *password = "PASSWORD_HERE";
    char login_buf[1024];
    sprintf(login_buf, "USER %s\r\n", username);
    n = send(sock_fd, login_buf, strlen(login_buf), 0);
    if(n < 0)
    {
        perror("Error sending login username to server");
        exit(EXIT_FAILURE);
    }
    n = read(sock_fd, buffer, sizeof(buffer));
    if(n < 0)
    {
        perror("Error reading login response from server");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);
    sprintf(login_buf, "PASS %s\r\n", password);
    n = send(sock_fd, login_buf, strlen(login_buf), 0);
    if(n < 0)
    {
        perror("Error sending login password to server");
        exit(EXIT_FAILURE);
    }
    n = read(sock_fd, buffer, sizeof(buffer));
    if(n < 0)
    {
        perror("Error reading login response from server");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Enter PASV (passive mode)
    char pasv_buf[1024];
    n = send(sock_fd, "PASV\r\n", strlen("PASV\r\n"), 0);
    if(n < 0)
    {
        perror("Error sending PASV command to server");
        exit(EXIT_FAILURE);
    }
    n = read(sock_fd, buffer, sizeof(buffer));
    if(n < 0)
    {
        perror("Error reading PASV response from server");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // Parse PASV response and get data port
    char *addr_start = strstr(buffer, "(");
    char *addr_end = strstr(buffer, ")");
    if(!addr_start || !addr_end)
    {
        perror("Error parsing PASV response");
        exit(EXIT_FAILURE);
    }
    char addr_buf[255];
    strncpy(addr_buf, addr_start+1, addr_end-addr_start-1);
    addr_buf[addr_end-addr_start-1] = '\0';
    char *tokens[6];
    tokens[0] = strtok(addr_buf, ",");
    for(int i = 1; i < 6; i++)
    {
        tokens[i] = strtok(NULL, ",");
    }
    char data_server_ip[16];
    sprintf(data_server_ip, "%s.%s.%s.%s", tokens[0], tokens[1], tokens[2], tokens[3]);
    int data_port = atoi(tokens[4]) * 256 + atoi(tokens[5]);
    
    // Connect to data port
    struct sockaddr_in data_server_addr;
    int data_sock_fd;
    if((data_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Data socket creation error");
        exit(EXIT_FAILURE);
    }
    data_server_addr.sin_family = AF_INET;
    data_server_addr.sin_port = htons(data_port);
    if(inet_pton(AF_INET, data_server_ip, &data_server_addr.sin_addr) <= 0)
    {
        perror("Invalid data address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    if(connect(data_sock_fd, (struct sockaddr *)&data_server_addr, sizeof(data_server_addr)) < 0)
    {
        perror("Data connection Failed");
        exit(EXIT_FAILURE);
    }
    
    // Download file
    char *filename = "FILE_NAME_HERE";
    char retr_buf[1024];
    sprintf(retr_buf, "RETR %s\r\n", filename);
    n = send(sock_fd, retr_buf, strlen(retr_buf), 0);
    if(n < 0)
    {
        perror("Error sending RETR command to server");
        exit(EXIT_FAILURE);
    }
    n = read(sock_fd, buffer, sizeof(buffer));
    if(n < 0)
    {
        perror("Error reading RETR response from server");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);
    
    FILE *fp;
    if((fp = fopen(filename, "w")) == NULL)
    {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    
    char file_buffer[1024];
    while((n = read(data_sock_fd, file_buffer, sizeof(file_buffer))) > 0)
    {
        fwrite(file_buffer, sizeof(char), n, fp);
    }
    if(n < 0)
    {
        perror("Error reading file from server");
        exit(EXIT_FAILURE);
    }
    printf("File downloaded successfully");
    
    // Close connections and exit
    close(sock_fd);
    close(data_sock_fd);
    exit(EXIT_SUCCESS);
}