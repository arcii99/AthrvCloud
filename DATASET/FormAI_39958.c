//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#define PORT 5000
#define BUFFER_SIZE 1024
#define MAX_CONSECUTIVE_FAILURES 5
#define PACKET_LOSS_THRESHOLD 0.5
#define TIME_DELAY_THRESHOLD 100 //milliseconds

typedef struct {
    float packet_loss_ratio;
    float average_delay;
} qos_params;

int consecutive_failures = 0;

void signal_handler(int sig) {
    printf("\nCtrl+C received. Exiting...\n");
    exit(0);
}

void calculate_qos_params(char *buffer, qos_params *qos) {
    //parse the buffer to extract packet loss ratio and average delay
    float packet_loss_ratio, average_delay;
    sscanf(buffer, "%f %f\n", &packet_loss_ratio, &average_delay);

    qos->packet_loss_ratio = packet_loss_ratio;
    qos->average_delay = average_delay;
}

void monitor_qos() {
    int sock_fd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    qos_params qos = {0, 0};
    struct timeval start_time, end_time;
    signal(SIGINT, signal_handler);

    //create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Socket creation error\n");
        exit(1);
    }

    //set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        exit(1);
    }

    //connect to server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        consecutive_failures = 0;
        //send data request to server
        n = write(sock_fd, "request_qos\n", strlen("request_qos\n"));
        if (n < 0) {
            printf("Error writing to socket\n");
            consecutive_failures++;
            if (consecutive_failures >= MAX_CONSECUTIVE_FAILURES) {
                printf("Too many consecutive failures. Exiting...\n");
                exit(1);
            }
            continue;
        }

        //get start time for timing the delay
        gettimeofday(&start_time, NULL);

        //read data from server
        n = read(sock_fd, buffer, BUFFER_SIZE);
        if (n < 0) {
            printf("Error reading from socket\n");
            consecutive_failures++;
            if (consecutive_failures >= MAX_CONSECUTIVE_FAILURES) {
                printf("Too many consecutive failures. Exiting...\n");
                exit(1);
            }
            continue;
        }
        buffer[n] = '\0';

        //get end time and calculate delay
        gettimeofday(&end_time, NULL);
        double delay = (double) (end_time.tv_usec - start_time.tv_usec) / 1000.0;
        if (delay >= TIME_DELAY_THRESHOLD) {
            printf("Warning: delay of %.2f milliseconds exceeds threshold\n", delay);
        }

        //calculate packet loss ratio and average delay
        calculate_qos_params(buffer, &qos);

        //determine if network is performing suitably
        if (qos.packet_loss_ratio >= PACKET_LOSS_THRESHOLD) {
            printf("Warning: packet loss ratio of %.2f exceeds allowable limit\n", qos.packet_loss_ratio);
        } else if (qos.average_delay >= TIME_DELAY_THRESHOLD) {
            printf("Warning: average delay of %.2f milliseconds exceeds threshold\n", qos.average_delay);
        } else {
            printf("Network is performing suitably\n");
        }
        
        sleep(10); //wait 10 seconds before querying again
    }
}

int main() {
    monitor_qos();
    return 0;
}