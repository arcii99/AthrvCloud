//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define BUFFER_SIZE 256

// Define the QoS Thresholds
#define LOW_THRESHOLD 100
#define MEDIUM_THRESHOLD 500
#define HIGH_THRESHOLD 1000

// Define the types of alerts
#define NO_ALERT 0
#define LOW_ALERT 1
#define MEDIUM_ALERT 2
#define HIGH_ALERT 3
#define DISCONNECT_ALERT 4

// Function to create server socket
int create_server_socket(char *server_ip, int server_port)
{
    int sockfd, optval;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR: Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket option to reuse the address
    optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));

    // Set server address
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_aton(server_ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(server_port);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("ERROR: Unable to bind socket");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(sockfd, MAX_CLIENTS) < 0)
    {
        perror("ERROR: Unable to listen on socket");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to handle client connections
void *handle_client(void *arg)
{
    int client_fd = *((int *)arg);
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int alerts_count = 0;

    // Loop to read data from client
    while ((bytes_read = read(client_fd, buffer, BUFFER_SIZE)) > 0)
    {
        // Calculate the network QoS
        int network_qos = (bytes_read * 8) / 1000000;

        // Check the QoS against the thresholds and generate alerts
        int alert_type = NO_ALERT;
        if (network_qos < LOW_THRESHOLD)
        {
            alert_type = LOW_ALERT;
        }
        else if (network_qos < MEDIUM_THRESHOLD)
        {
            alert_type = MEDIUM_ALERT;
        }
        else if (network_qos < HIGH_THRESHOLD)
        {
            alert_type = HIGH_ALERT;
        }
        else
        {
            alert_type = DISCONNECT_ALERT;
        }

        // Print the QoS and alert status
        printf("Network QoS: %d Mbps | Alert: ", network_qos);
        if (alert_type == NO_ALERT)
        {
            printf("No Alert\n");
        }
        else if (alert_type == LOW_ALERT)
        {
            alerts_count++;
            printf("Low Alert (%d)\n", alerts_count);
        }
        else if (alert_type == MEDIUM_ALERT)
        {
            alerts_count++;
            printf("Medium Alert (%d)\n", alerts_count);
        }
        else if (alert_type == HIGH_ALERT)
        {
            alerts_count++;
            printf("High Alert (%d)\n", alerts_count);
        }
        else
        {
            printf("Disconnect Alert\n");
            break;
        }
    }

    // Close the client socket
    close(client_fd);

    pthread_exit(NULL);
}

// Main function
int main()
{
    int server_fd, client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t tid[MAX_CLIENTS];
    int i = 0;

    // Create the server socket
    server_fd = create_server_socket(SERVER_IP, SERVER_PORT);

    // Loop to accept client connections
    while (1)
    {
        // Accept a client connection
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0)
        {
            perror("ERROR: Unable to accept client connection");
            continue;
        }

        // Spawn a new thread to handle the client connection
        if (pthread_create(&tid[i], NULL, handle_client, (void *)&client_fd) != 0)
        {
            perror("ERROR: Unable to create thread");
            continue;
        }

        // Increment the thread counter
        i++;
        if (i >= MAX_CLIENTS)
        {
            i = 0;
            while (i < MAX_CLIENTS)
            {
                pthread_join(tid[i++], NULL);
            }
            i = 0;
        }
    }

    // Close the server socket
    close(server_fd);

    return 0;
}