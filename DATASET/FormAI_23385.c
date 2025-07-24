//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

/* Define a structure to hold the monitored parameters */
typedef struct {
    unsigned long int total_packets;
    unsigned long int total_bytes;
    unsigned int min_packet_size;
    unsigned int max_packet_size;
    unsigned int avg_packet_size;
    unsigned int packet_loss_ratio;
    float avg_packet_time;
    unsigned int max_packet_time;
    unsigned int min_packet_time;
} QoS_measurements;

/* Initialize the measurements structure */
void init_measurements(QoS_measurements *m) {
    m->total_packets = 0;
    m->total_bytes = 0;
    m->min_packet_size = 0;
    m->max_packet_size = 0;
    m->avg_packet_size = 0;
    m->packet_loss_ratio = 0;
    m->avg_packet_time = 0.0f;
    m->max_packet_time = 0;
    m->min_packet_time = 0;
}

/* Update the measurements structure with new packet data */
void update_measurements(QoS_measurements *m, u_char *buffer, int size, struct timeval t) {
    m->total_packets++;
    m->total_bytes += size;
    if (m->min_packet_size == 0 || size < m->min_packet_size) {
        m->min_packet_size = size;
    }
    if (size > m->max_packet_size) {
        m->max_packet_size = size;
    }
    if (m->avg_packet_size == 0) {
        m->avg_packet_size = size;
    } else {
        m->avg_packet_size = ((m->avg_packet_size * (m->total_packets - 1)) + size) / m->total_packets;
    }
    if (buffer[0] == 'A') {
        if (m->min_packet_time == 0 || (t.tv_sec - m->max_packet_time) < m->min_packet_time) {
            m->min_packet_time = t.tv_sec - m->max_packet_time;
        }
        if ((t.tv_sec - m->max_packet_time) > m->max_packet_time) {
            m->max_packet_time = t.tv_sec - m->max_packet_time;
        }
        if (m->avg_packet_time == 0.0f) {
            m->avg_packet_time = t.tv_sec - m->max_packet_time;
        } else {
            m->avg_packet_time = ((m->avg_packet_time * (m->total_packets - 1)) + (t.tv_sec - m->max_packet_time)) / m->total_packets;
        }
    } else {
        m->packet_loss_ratio = ((m->total_packets - m->packet_loss_ratio) * 100) / m->total_packets;
    }
}

/* Print the current measurements to the console */
void print_measurements(QoS_measurements *m) {
    printf("Total packets: %lu\n", m->total_packets);
    printf("Total bytes: %lu\n", m->total_bytes);
    printf("Smallest packet: %u bytes\n", m->min_packet_size);
    printf("Largest packet: %u bytes\n", m->max_packet_size);
    printf("Average packet size: %u bytes\n", m->avg_packet_size);
    printf("Packet loss ratio: %u percent\n", m->packet_loss_ratio);
    printf("Average packet time: %f seconds\n", m->avg_packet_time);
    printf("Smallest packet time: %u seconds\n", m->min_packet_time);
    printf("Largest packet time: %u seconds\n", m->max_packet_time);
}

int main(int argc, char *argv[]) {
    int socket_desc, read_size;
    struct sockaddr_in server, client;
    char client_message[BUFFER_SIZE], response[BUFFER_SIZE];
    QoS_measurements measurements;
    struct timeval tval_before, tval_after, tval_result;

    /* Initiate the measurements structure */
    init_measurements(&measurements);

    /* Create a socket */
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    /* Prepare the sockaddr_in structure */
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    /* Bind the socket to a specific port */
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    printf("Socket bind successful\n");

    /* Listen for incoming connections */
    listen(socket_desc, 3);

    /* Accept incoming connections */
    printf("Waiting for incoming connections...\n");
    int c = sizeof(struct sockaddr_in);
    while ((socket_desc = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c))) {
        printf("Connection accepted\n");

        /* Receive data from client */
        while ((read_size = recv(socket_desc, client_message, BUFFER_SIZE, 0)) > 0) {
            /* Save time that packet arrived */
            gettimeofday(&tval_before, NULL);

            /* Update the measurements structure */
            update_measurements(&measurements, client_message, read_size, tval_before);

            /* Send a response to the client */
            sprintf(response, "Echo: %s", client_message);
            write(socket_desc, response, strlen(response));
            memset(client_message, 0, BUFFER_SIZE);
        }
        if (read_size == 0) {
            printf("Client disconnected\n");
            fflush(stdout);
        } else if (read_size == -1) {
            perror("recv failed");
        }
        close(socket_desc);
    }

    /* Print the final measurements */
    print_measurements(&measurements);

    return 0;
}