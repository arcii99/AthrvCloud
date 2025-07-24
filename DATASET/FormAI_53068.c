//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 21

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_received;

    // Greet the server with a medieval-style message
    strcpy(buffer, "Hail and well met! I, thy humble servant, doth seek to establish a connection to thine server.");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s\n", buffer);

    // Log in to the server with a username and password
    strcpy(buffer, "Milord, prithee grant me passage by telling me thy username and password.");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s\n", buffer);

    char username[20], password[20];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    sprintf(buffer, "%s %s", username, password);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s\n", buffer);

    // Change to a specified directory on the server
    strcpy(buffer, "Milord, prithee instruct me which directory to enter.");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s\n", buffer);

    char directory[50];
    scanf("%s", directory);
    sprintf(buffer, "CWD %s", directory);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s\n", buffer);

    // Retrieve a file from the server
    strcpy(buffer, "Milord, I crave thy permission to retrieve a file from thine server.");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s\n", buffer);

    char filename[50];
    scanf("%s", filename);
    sprintf(buffer, "RETR %s", filename);
    send(sock, buffer, strlen(buffer), 0);

    FILE *file_ptr = fopen(filename, "w");
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0)
    {
        fwrite(buffer, sizeof(char), bytes_received, file_ptr);
    }
    fclose(file_ptr);

    // Disconnect from server
    strcpy(buffer, "Farewell, milord. I shall depart now.");
    send(sock, buffer, strlen(buffer), 0);

    close(sock);
    return 0;
}