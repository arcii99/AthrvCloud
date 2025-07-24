//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    char mode[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    int data_port;
    char buffer[BUFFER_SIZE];

    // create socket for control connection
    int control_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (control_sockfd < 0)
        error("ERROR opening control socket");

    // set up control address structure
    struct sockaddr_in control_addr;
    control_addr.sin_family = AF_INET;
    control_addr.sin_port = htons(21);
    control_addr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to control address structure
    if (bind(control_sockfd, (struct sockaddr *) &control_addr, sizeof(control_addr)) < 0)
        error("ERROR on binding control socket");

    // listen for control connection
    listen(control_sockfd, 5);

    printf("Welcome to the FTP Client Example Program!\n");

    while (1) {
        // accept control connection
        int control_newsockfd = accept(control_sockfd, NULL, NULL);
        if (control_newsockfd < 0)
            error("ERROR on accept control connection");

        // send welcome message and get mode selection
        sprintf(buffer, "220 Welcome to the FTP Client Example Program!\nEnter 'PASV' or 'PORT': ");
        send(control_newsockfd, buffer, strlen(buffer), 0);
        recv(control_newsockfd, mode, BUFFER_SIZE, 0);

        // parse mode selection
        mode[strcspn(mode, "\r\n")] = 0;
        if (strcmp(mode, "PASV") == 0) {
            // enter passive mode
            sprintf(buffer, "227 Entering Passive Mode (127,0,0,1,0,%d)\r\n", data_port);
            send(control_newsockfd, buffer, strlen(buffer), 0);

            // create socket for data connection
            int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (data_sockfd < 0)
                error("ERROR opening data socket");

            // set up data address structure
            struct sockaddr_in data_addr;
            data_addr.sin_family = AF_INET;
            data_addr.sin_port = htons(data_port);
            data_addr.sin_addr.s_addr = INADDR_ANY;

            // bind socket to data address structure
            if (bind(data_sockfd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0)
                error("ERROR on binding data socket");

            // listen for data connection
            listen(data_sockfd, 5);

            // accept data connection
            int data_newsockfd = accept(data_sockfd, NULL, NULL);
            if (data_newsockfd < 0)
                error("ERROR on accept data connection");

            // get filename and command
            sprintf(buffer, "150 File status okay; about to open data connection.\r\n");
            send(control_newsockfd, buffer, strlen(buffer), 0);
            recv(control_newsockfd, filename, BUFFER_SIZE, 0);
            recv(control_newsockfd, command, BUFFER_SIZE, 0);

            // parse filename and command
            filename[strcspn(filename, "\r\n")] = 0;
            command[strcspn(command, "\r\n")] = 0;

            // send file or directory listing
            if (strcmp(command, "RETR") == 0) {
                FILE *file = fopen(filename, "rb");
                if (file == NULL) {
                    sprintf(buffer, "550 File not found.\r\n");
                    send(control_newsockfd, buffer, strlen(buffer), 0);
                } else {
                    sprintf(buffer, "226 Closing data connection. Requested file action successful.\r\n");
                    send(control_newsockfd, buffer, strlen(buffer), 0);

                    while (1) {
                        int n = fread(buffer, 1, BUFFER_SIZE, file);
                        if (n == 0)
                            break;

                        send(data_newsockfd, buffer, n, 0);
                    }

                    fclose(file);
                }
            } else {
                sprintf(buffer, "226 Closing data connection. Requested file action successful.\r\n");
                send(control_newsockfd, buffer, strlen(buffer), 0);

                system(command);
                FILE *listing_file = fopen("listing.txt", "rb");
                if (listing_file == NULL) {
                    sprintf(buffer, "550 File not found.\r\n");
                    send(control_newsockfd, buffer, strlen(buffer), 0);
                } else {
                    while (1) {
                        int n = fread(buffer, 1, BUFFER_SIZE, listing_file);
                        if (n == 0)
                            break;

                        send(data_newsockfd, buffer, n, 0);
                    }

                    fclose(listing_file);
                    remove("listing.txt");
                }
            }

            // close data connection
            close(data_newsockfd);
            close(data_sockfd);
        } else {
            // enter active mode
            sprintf(buffer, "500 Active mode not supported.\r\n");
            send(control_newsockfd, buffer, strlen(buffer), 0);
        }

        // close control connection
        close(control_newsockfd);
    }

    // close control socket
    close(control_sockfd);

    return 0;
}