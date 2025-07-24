//FormAI DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define MAX_SIZE 1000

// Function to check if a given string is a valid IP address
int isValidIpAddress(char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}

// Function to check if a given port number is valid (between 1 and 65535)
int isValidPort(char *portNumber)
{
    int port = atoi(portNumber);
    return (port >= 1 && port <= 65535);
}

int main()
{
    // Define variables for storing user input and temporary values
    char buffer[MAX_SIZE];
    char ipAddress[MAX_SIZE];
    char portNumber[MAX_SIZE];
    char input[MAX_SIZE];
    int i, j, k, c;

    // Define variables for the socket and server address
    int serverSocket;
    struct sockaddr_in serverAddr;

    // Set up the server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Create the socket
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Bind the socket to the server address
    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // Listen for incoming connections
    listen(serverSocket, 5);

    // Print a message to the console
    printf("Shape-shifting Firewall started...\n");

    while (1)
    {
        // Accept a new connection
        int clientSocket = accept(serverSocket, NULL, NULL);

        // If the connection was successful, read data from the client
        if (clientSocket >= 0)
        {
            memset(buffer, '\0', MAX_SIZE);
            read(clientSocket, buffer, MAX_SIZE);

            // Check if the request is a valid HTTP request
            if (strstr(buffer, "HTTP") != NULL)
            {
                // Get the client IP address and port number
                struct sockaddr_storage addr;
                socklen_t len = sizeof(addr);
                getpeername(clientSocket, (struct sockaddr *)&addr, &len);
                struct sockaddr_in *s = (struct sockaddr_in *)&addr;
                inet_ntop(AF_INET, &s->sin_addr, ipAddress, sizeof ipAddress);
                sprintf(portNumber, "%d", ntohs(s->sin_port));

                // Print the request and the client's IP address and port to the console
                printf("Received HTTP request from %s:%s:\n", ipAddress, portNumber);
                printf("%s\n", buffer);

                // Perform shape-shifting on the requested URL
                char *tempBuffer = buffer;
                char *pos;
                while ((pos = strstr(tempBuffer, "GET")) != NULL || (pos = strstr(tempBuffer, "POST")) != NULL)
                {
                    pos += strlen("GET ");
                    char *endPos = strchr(pos, ' ');
                    if (endPos != NULL)
                    {
                        *endPos = '\0';
                        char *url = pos;
                        // Shape-shift the URL
                        for (i = 0; i < strlen(url); i++)
                        {
                            if (isdigit(url[i]))
                            {
                                url[i] = '9' - url[i] + '0';
                            }
                            else if (isalpha(url[i]))
                            {
                                if (islower(url[i]))
                                {
                                    url[i] = 'z' - url[i] + 'a';
                                }
                                else
                                {
                                    url[i] = 'Z' - url[i] + 'A';
                                }
                            }
                            else
                            {
                                url[i] = '^';
                            }
                        }
                        *endPos = ' ';
                        tempBuffer = endPos;
                    }
                    else
                    {
                        break;
                    }
                }

                // Print the shape-shifted request to the console
                printf("Shape-shifted request:\n%s\n", buffer);

                // Check if the requested IP address is valid
                if (isValidIpAddress(ipAddress))
                {
                    // Check if the requested port number is valid
                    if (isValidPort(portNumber))
                    {
                        // Connect to the requested server
                        struct sockaddr_in destAddr;
                        destAddr.sin_family = AF_INET;
                        destAddr.sin_port = htons(atoi(portNumber));
                        inet_pton(AF_INET, ipAddress, &destAddr.sin_addr);

                        int destSocket = socket(PF_INET, SOCK_STREAM, 0);
                        if (connect(destSocket, (struct sockaddr *)&destAddr, sizeof(destAddr)) >= 0)
                        {
                            // Forward the client's request to the server
                            write(destSocket, buffer, strlen(buffer));

                            // Forward the server's response to the client
                            memset(buffer, '\0', MAX_SIZE);
                            while ((c = read(destSocket, buffer, MAX_SIZE)) > 0)
                            {
                                write(clientSocket, buffer, c);
                                memset(buffer, '\0', MAX_SIZE);
                            }
                        }
                        close(destSocket);
                    }
                    else
                    {
                        const char *errorMessage = "Invalid port number.";
                        write(clientSocket, errorMessage, strlen(errorMessage));
                    }
                }
                else
                {
                    const char *errorMessage = "Invalid IP address.";
                    write(clientSocket, errorMessage, strlen(errorMessage));
                }
            }
            else
            {
                const char *errorMessage = "Invalid request.";
                write(clientSocket, errorMessage, strlen(errorMessage));
            }

            // Close the client socket
            close(clientSocket);
        }
    }

    // Close the server socket
    close(serverSocket);

    return 0;
}