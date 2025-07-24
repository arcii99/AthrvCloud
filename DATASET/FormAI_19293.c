//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
// This is a FTP client program written in C
// It allows the user to connect to a FTP server,
// Download and upload files to the server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"   // The FTP server IP address
#define SERVER_PORT 21          // The FTP server port

// A helper function to print FTP server response
void print_response(int sock)
{
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);
    buffer[len] = '\0';
    printf("%s", buffer);
}

// The main function
int main()
{
    // Create the socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("ERROR: Cannot create socket\n");
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("ERROR: Cannot connect to server\n");
        return -1;
    }

    // Print the welcome message from the server
    int success = 0;
    print_response(sock);

    // Send the login credentials to the server
    char user[50], pass[50];
    printf("\nUsername: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    char login_cmd[100];
    sprintf(login_cmd, "USER %s\r\n", user);
    send(sock, login_cmd, strlen(login_cmd), 0);
    print_response(sock);

    sprintf(login_cmd, "PASS %s\r\n", pass);
    send(sock, login_cmd, strlen(login_cmd), 0);
    print_response(sock);

    // Enter passive mode
    send(sock, "PASV\r\n", strlen("PASV\r\n"), 0);
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);
    buffer[len] = '\0';
    printf("%s", buffer);

    // Get the port number from the response
    char *p1 = strchr(buffer, '(');
    char *p2 = strchr(p1, ')');
    char *p3 = strchr(p1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    int port1 = atoi(p3+1);
    char *p4 = strchr(p3+1, ',');
    int port2 = atoi(p4+1);
    int data_port = port1*256 + port2;

    // Request the file list from the server
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);

    // Connect to the data port
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    inet_pton(AF_INET, SERVER_IP, &data_addr.sin_addr);
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0)
    {
        printf("ERROR: Cannot connect to server\n");
        return -1;
    }

    // Receive the file list
    char file_list[1024];
    len = recv(data_sock, file_list, 1024, 0);
    file_list[len] = '\0';
    printf("%s", file_list);

    // Close the data socket
    close(data_sock);

    // Download a file from the server
    char filename[50];
    printf("\nEnter filename to download: ");
    scanf("%s", filename);

    char download_cmd[100];
    sprintf(download_cmd, "RETR %s\r\n", filename);
    send(sock, download_cmd, strlen(download_cmd), 0);

    // Enter passive mode
    send(sock, "PASV\r\n", strlen("PASV\r\n"), 0);
    len = recv(sock, buffer, 1024, 0);
    buffer[len] = '\0';
    printf("%s", buffer);

    // Get the port number from the response
    p1 = strchr(buffer, '(');
    p2 = strchr(p1, ')');
    p3 = strchr(p1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    port1 = atoi(p3+1);
    p4 = strchr(p3+1, ',');
    port2 = atoi(p4+1);
    data_port = port1*256 + port2;

    // Connect to the data port
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0)
    {
        printf("ERROR: Cannot connect to server\n");
        return -1;
    }

    // Receive the file content
    char file_content[1024];
    len = recv(data_sock, file_content, 1024, 0);
    file_content[len] = '\0';

    // Save the file content to disk
    FILE *fp = fopen(filename, "w");
    if(fp != NULL)
    {
        fprintf(fp, "%s", file_content);
        fclose(fp);
    }

    // Close the data socket
    close(data_sock);

    // Upload a file to the server
    printf("\nEnter filename to upload: ");
    scanf("%s", filename);

    // Read the file content from disk
    fp = fopen(filename, "r");
    char file_buffer[1024];
    if(fp != NULL)
    {
        size_t newLen = fread(file_buffer, sizeof(char), 1024, fp);
        fclose(fp);
        file_buffer[newLen] = '\0';
    }

    // Enter passive mode
    send(sock, "PASV\r\n", strlen("PASV\r\n"), 0);
    len = recv(sock, buffer, 1024, 0);
    buffer[len] = '\0';
    printf("%s", buffer);

    // Get the port number from the response
    p1 = strchr(buffer, '(');
    p2 = strchr(p1, ')');
    p3 = strchr(p1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    p3 = strchr(p3+1, ',');
    port1 = atoi(p3+1);
    p4 = strchr(p3+1, ',');
    port2 = atoi(p4+1);
    data_port = port1*256 + port2;

    // Connect to the data port
    data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0)
    {
        printf("ERROR: Cannot connect to server\n");
        return -1;
    }

    // Upload the file content to the server
    sprintf(download_cmd, "STOR %s\r\n", filename);
    send(sock, download_cmd, strlen(download_cmd), 0);
    send(data_sock, file_buffer, strlen(file_buffer), 0);

    // Close the data stream
    close(data_sock);

    // Quit the FTP session
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    // Close the control socket
    close(sock);

    return 0;
}