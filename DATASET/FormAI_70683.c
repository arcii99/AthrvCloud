//FormAI DATASET v1.0 Category: Firewall ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main()
{
    int server_fd, opt = 1;
    struct sockaddr_in address;

    char buffer[BUFFER_SIZE] = {0};
    char *deny_list[] = {"facebook", "twitter", "reddit", "youtube"};

    /*Create the server socket*/
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    /*Set the server socket options*/
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Error in setting socket options");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    /* Bind the socket */
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    /* Start listening for incoming connections */
    if (listen(server_fd, 3) < 0)
    {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Starting Firewall on port %d...\n", PORT);

    while (1)
    {
        int new_socket, valread;
        struct sockaddr_in client_address;
        int client_address_len = sizeof(client_address);

        /* Accept incoming connection request */
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address,
                                 (socklen_t *)&client_address_len)) < 0)
        {
            perror("Accepting incoming connection failed");
            exit(EXIT_FAILURE);
        }

        /* Extract the IP Address of incoming client connection */
        char *client_ip = inet_ntoa(client_address.sin_addr);
        printf("\nIncoming connection from IP Address: %s\n", client_ip);

        /* Read the received data */
        valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("Received data: %s\n", buffer);

        /* Check if received data matches any keywords in the deny_list*/
        for (int i = 0; i < (sizeof(deny_list) / sizeof(deny_list[0])); i++)
        {
            if (strstr(buffer, deny_list[i]) != NULL)
            {
                printf("Access denied to keyword: %s\n", deny_list[i]);

                /* Send message to the client*/
                char *deny_message = "You are not allowed to access this page.";
                write(new_socket, deny_message, strlen(deny_message));

                /* Log the access denied event */
                time_t t = time(NULL);
                struct tm *time_ptr = localtime(&t);
                FILE *fp = fopen("firewall_log.txt", "a+");
                fprintf(fp, "%d-%d-%d %02d:%02d:%02d | IP: %s | Keyword: %s\n",
                        time_ptr->tm_year + 1900, time_ptr->tm_mon + 1, time_ptr->tm_mday,
                        time_ptr->tm_hour, time_ptr->tm_min, time_ptr->tm_sec,
                        client_ip, deny_list[i]);
                fclose(fp);

                /* Close the connection */
                close(new_socket);

                break;
            }
        }

        /* If none of the keywords match, then grant access */
        char *accept_message = "Access granted!";
        write(new_socket, accept_message, strlen(accept_message));
        printf("Access granted to the client.\n");

        /* Log the access granted event */
        time_t t = time(NULL);
        struct tm *time_ptr = localtime(&t);
        FILE *fp = fopen("firewall_log.txt", "a+");
        fprintf(fp, "%d-%d-%d %02d:%02d:%02d | IP: %s | Access Granted\n",
                time_ptr->tm_year + 1900, time_ptr->tm_mon + 1, time_ptr->tm_mday,
                time_ptr->tm_hour, time_ptr->tm_min, time_ptr->tm_sec,
                client_ip);
        fclose(fp);

        /* Close the connection */
        close(new_socket);
    }

    return 0;
}