//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
/* FTP Client Example Program */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 21 //FTP port number defined
#define MAXSIZE 1024 //Maximum buffer size

int main(int argc, char *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[MAXSIZE] = {0};

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return -1;
    }

    //Set the socket's address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\n Invalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the FTP server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Connection Failed \n");
        return -1;
    }

    // Read welcome message from the FTP server
    valread = read( sock , buffer, MAXSIZE);
    printf("%s\n",buffer );

    // Send user name to the FTP server
    char* user_name = "USER anonymous\r\n";
    send(sock, user_name, strlen(user_name), 0);
    valread = read(sock, buffer, MAXSIZE);
    printf("%s\n", buffer);

    // Send password to the FTP server
    char* password = "PASS anonymous\r\n";
    send(sock, password, strlen(password), 0);
    valread = read(sock, buffer, MAXSIZE);
    printf("%s\n", buffer);

    // Enter passive mode to prepare for file transfer
    char* pasv_mode = "PASV\r\n";
    send(sock, pasv_mode, strlen(pasv_mode), 0);

    // Read the server's port for file transfer
    valread = read(sock, buffer, MAXSIZE);
    printf("%s\n", buffer);

    // Extract the server's port from the PASV response
    int port = 0;
    char* ip_address = strtok(buffer, "(),");
    for (int i = 0; i < 4; i++) {
        ip_address = strtok(NULL, "(),");
    }
    int p1 = atoi(strtok(NULL, "(),"));
    int p2 = atoi(strtok(NULL, "(),"));
    port = (p1 << 8) | p2;

    //Create a new socket for the file transfer using the server's IP and port
    int new_sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr)<=0)
    {
        printf("\n Invalid address/ Address not supported \n");
        return -1;
    }
    if(connect(new_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Connection Failed \n");
        return -1;
    }

    // Read file from the FTP server and store it on local machine
    FILE* fp = fopen("file.txt", "w");
    char* get_file = "RETR file.txt\r\n";
    send(sock, get_file, strlen(get_file), 0);
    while((valread = read(new_sock, buffer, MAXSIZE)) > 0)
    {
        fwrite(buffer, 1, valread, fp);
    }
    fclose(fp);
    printf("\n File downloaded successfully! \n");

    // Quit the FTP session
    char* quit = "QUIT\r\n";
    send(sock, quit, strlen(quit), 0);
    valread = read(sock, buffer, MAXSIZE);
    printf("%s\n", buffer);
    close(sock);
    return 0;
}