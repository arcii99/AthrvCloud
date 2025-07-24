//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024 // Buffer size for packets
#define PORT 21 // Default port for FTP

int main(int argc, char const *argv[])
{
    int control_socket, data_socket; // Control and data sockets
    struct sockaddr_in server_address; // Server address struct
    char buffer[BUFSIZE]; // Buffer for incoming packets
    int response_code; // Response code from server
    char username[50], password[50], filename[50]; // File and login info

    // Create control socket
    control_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address
    memset(&server_address, 0, sizeof(server_address)); // Clear struct
    server_address.sin_family = AF_INET; // IPv4
    server_address.sin_addr.s_addr = inet_addr(argv[1]); // Server IP
    server_address.sin_port = htons(PORT); // Port number

    // Connect to server
    connect(control_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    recv(control_socket, buffer, BUFSIZE, 0); // Receive welcome message

    // Enter username and password
    printf("Enter username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    send(control_socket, buffer, strlen(buffer), 0); // Send username
    recv(control_socket, buffer, BUFSIZE, 0); // Receive response
    sscanf(buffer, "%d", &response_code); // Parse response code

    if(response_code == 331) // Username accepted, prompt for password
    {
        printf("Enter password: ");
        scanf("%s", password);
        sprintf(buffer, "PASS %s\r\n", password);
        send(control_socket, buffer, strlen(buffer), 0); // Send password
        recv(control_socket, buffer, BUFSIZE, 0); // Receive response
        sscanf(buffer, "%d", &response_code); // Parse response code
    }

    if(response_code == 230) // Login successful
    {
        printf("Login successful.\n");

        // Enter filename
        printf("Enter filename: ");
        scanf("%s", filename);

        // Set up data socket
        struct sockaddr_in data_address; // Data address struct
        int data_port; // Port number for data connection
        char* end; // Used to parse port number from response

        sprintf(buffer, "PASV\r\n"); // Send passive mode command
        send(control_socket, buffer, strlen(buffer), 0);
        recv(control_socket, buffer, BUFSIZE, 0); // Receive response
        sscanf(buffer, "%d", &response_code); // Parse response code
        if(response_code == 227) // Entering passive mode
        {
            // Parse IP and port info from response
            end = strrchr(buffer, ')');
            *end = '\0';
            end = strrchr(buffer, ',');
            data_port = atoi(end+1);
            *end = '\0';
            end = strrchr(buffer, ',');
            data_port += atoi(end+1)*256;

            memset(&data_address, 0, sizeof(data_address)); // Clear struct
            data_address.sin_family = AF_INET; // IPv4
            data_address.sin_addr.s_addr = inet_addr(argv[1]); // Server IP
            data_address.sin_port = htons(data_port); // Port number
            data_socket = socket(AF_INET, SOCK_STREAM, 0); // Create data socket
            connect(data_socket, (struct sockaddr*)&data_address, sizeof(data_address)); // Connect to server
        }

        sprintf(buffer, "RETR %s\r\n", filename); // Send retrieve command
        send(control_socket, buffer, strlen(buffer), 0);
        recv(control_socket, buffer, BUFSIZE, 0); // Receive response
        sscanf(buffer, "%d", &response_code); // Parse response code
        if(response_code == 150) // File ok, sending contents
        {
            FILE* fp = fopen(filename, "wb"); // Open file for writing
            if(fp == NULL)
            {
                printf("Error: unable to open file for writing.\n");
                exit(1);
            }
            memset(buffer, 0, BUFSIZE); // Clear buffer
            int bytes_received;
            while((bytes_received = recv(data_socket, buffer, BUFSIZE, 0)) > 0)
            {
                fwrite(buffer, 1, bytes_received, fp); // Write to file
                memset(buffer, 0, BUFSIZE); // Clear buffer
            }
            fclose(fp); // Close file
            printf("File transfer complete.\n");
        }
        else // Error
        {
            printf("Error: unable to retrieve file.\n");
            exit(1);
        }

        sprintf(buffer, "QUIT\r\n"); // Send quit command
        send(control_socket, buffer, strlen(buffer), 0);
        recv(control_socket, buffer, BUFSIZE, 0); // Receive response
        printf("Logged out.\n");

        return 0;
    }
    else // Login failed
    {
        printf("Login failed.\n");
        exit(1);
    } 
}