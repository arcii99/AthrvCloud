//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

// function to calculate QoS
float calc_qos(float bw, float latency, float dropped, float jitter){
    float qos = ((bw * 10) + (1 / latency) - (dropped / 10) - (jitter * 2));
    return qos;
}

int main(int argc, char *argv[])
{
    struct sockaddr_in server;
    struct sockaddr_in client;
    int sd, new_sd;
    socklen_t client_len;

    // create socket
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd == -1)
    {
        perror("Error: Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int opt_val = 1;
    if(setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof opt_val) < 0)
    {
        perror("Error: Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // bind socket to IP and port
    server.sin_family = AF_INET;
    server.sin_port = htons(9999);
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(sd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Error: Bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if(listen(sd, 3) < 0)
    {
        perror("Error: Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    // accept incoming connections
    while(1)
    {
        client_len = sizeof(client);
        new_sd = accept(sd, (struct sockaddr *)&client, &client_len);
        if(new_sd < 0)
        {
            perror("Error: Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Incoming connection from %s\n", inet_ntoa(client.sin_addr));

        // read data from socket
        char buffer[1024] = {0};
        int valread = read(new_sd , buffer, 1024);
        printf("Data received: %s\n",buffer );

        // calculate QoS
        float bw = 10.0;
        float latency = 0.5;
        float dropped = 0.1;
        float jitter = 0.2;
        float qos = calc_qos(bw, latency, dropped, jitter);

        // send QoS result to client
        char qos_result[20];
        snprintf(qos_result, 20, "%.2f", qos);
        send(new_sd, qos_result, strlen(qos_result), 0);
        printf("QoS result sent: %s\n", qos_result);

        close(new_sd);
    }

    close(sd);
    return 0;
}