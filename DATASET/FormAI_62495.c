//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<string.h>
#include<time.h>

#define BUF_SIZE 4096
#define PORT 50000

// Function to calculate average QoS
float calculate_average_qos(int *qos_array, int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += qos_array[i];
    }
    float avg = (float)sum/n;
    return avg;
}

int main() {
    int sock_fd;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr, client_addr;
    int client_len = sizeof(struct sockaddr_in);

    // Creating socket
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sock_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Initializing server and client address structures
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Binding socket to server address
    if(bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    printf("Server listening at port %d...\n", PORT);

    while(1) {
        memset(buffer, '\0', BUF_SIZE);

        // receiving message from client
        int recv_len = recvfrom(sock_fd, buffer, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &client_len);

        if (recv_len < 0) {
            perror("Error receiving data");
            exit(EXIT_FAILURE);
        }

        // Printing received message along with client IP and Port
        printf("Received message: %s from client %s:%d\n", buffer, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Generating random QoS value between 1 and 10
        srand(time(0));
        int qos = rand()%10 + 1;

        // Sending QoS value to client
        if(sendto(sock_fd, &qos, sizeof(qos), 0, (struct sockaddr *)&client_addr, client_len) < 0) {
            perror("Error sending data");
            exit(EXIT_FAILURE);
        }

        printf("Sent QoS value %d to client %s:%d\n", qos, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Calculating average QoS for past 5 messages
        static int qos_list[5] = {0};
        static int count = 0;
        int n = 5;        
        qos_list[count] = qos;
        count++;

        if(count == 5) {
            float avg_qos = calculate_average_qos(qos_list, n);
            printf("Average QoS for past 5 messages: %0.2f\n", avg_qos);
            count = 0;
        }
    }

    return 0;
}