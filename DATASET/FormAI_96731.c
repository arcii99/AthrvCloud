//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;

    // Create a client socket and verify it
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Set the server address and port number
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);

    // Convert the IP address string to binary form
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("Error: Invalid IP address\n");
        return 1;
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Connection failed\n");
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the server welcome message
    if (read(client_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Error: Failed to receive message from server\n");
        return 1;
    }

    printf("%s", buffer);

    // Send the username
    char username[MAX_BUFFER_SIZE];
    printf("Username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the password prompt
    if (read(client_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Error: Failed to receive message from server\n");
        return 1;
    }

    printf("%s", buffer);

    // Send the password
    char password[MAX_BUFFER_SIZE];
    printf("Password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the server response
    if (read(client_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Error: Failed to receive message from server\n");
        return 1;
    }

    printf("%s", buffer);

    // Send the PASV command to enter passive mode
    sprintf(buffer, "PASV\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the server response with the port for the data connection
    if (read(client_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Error: Failed to receive message from server\n");
        return 1;
    }

    printf("%s", buffer);

    // Parse the port number from the server response
    int port_number = 0;
    char *port_string = strtok(buffer, ",");
    for (int i = 0; i < 4; i++) {
        port_number = port_number * 256 + atoi(port_string);
        port_string = strtok(NULL, ",");
    }
    port_number = port_number * 256 + atoi(port_string);

    // Create a data socket and connect to the server
    struct sockaddr_in data_address;
    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(port_number);
    if (inet_pton(AF_INET, argv[1], &data_address.sin_addr) <= 0) {
        printf("Error: Invalid IP address\n");
        return 1;
    }
    if (connect(data_socket, (struct sockaddr *)&data_address, sizeof(data_address)) < 0) {
        printf("Error: Connection failed\n");
        return 1;
    }

    // Send the TYPE command to set the transfer type to binary
    sprintf(buffer, "TYPE I\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the server response
    if (read(client_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Error: Failed to receive message from server\n");
        return 1;
    }

    printf("%s", buffer);

    // Send the RETR command to retrieve a file from the server
    char filename[MAX_BUFFER_SIZE];
    printf("File name: ");
    scanf("%s", filename);
    sprintf(buffer, "RETR %s\r\n", filename);
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the server response with the file size
    if (read(client_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Error: Failed to receive message from server\n");
        return 1;
    }

    printf("%s", buffer);

    // Parse the file size from the server response
    int file_size = 0;
    if (strstr(buffer, "150") != NULL) {
        char *size_string = strtok(buffer, " ");
        for (int i = 0; i < 4; i++) {
            size_string = strtok(NULL, " ");
        }
        file_size = atoi(size_string);
    }

    // Receive the file data and save it to a file
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Failed to open file\n");
        return 1;
    }
    int received_bytes = 0;
    int total_bytes = 0;
    while ((received_bytes = read(data_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
        total_bytes += received_bytes;
        fwrite(buffer, received_bytes, 1, file);
    }
    fclose(file);

    // Read the server response with the transfer status
    if (read(client_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Error: Failed to receive message from server\n");
        return 1;
    }

    printf("%s", buffer);

    // Send the QUIT command to disconnect from the server
    sprintf(buffer, "QUIT\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the server goodbye message
    if (read(client_socket, buffer, MAX_BUFFER_SIZE) < 0) {
        printf("Error: Failed to receive message from server\n");
        return 1;
    }

    printf("%s", buffer);

    // Close the sockets and exit the program
    close(data_socket);
    close(client_socket);
    return 0;
}