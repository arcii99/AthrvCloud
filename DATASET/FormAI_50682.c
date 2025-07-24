//FormAI DATASET v1.0 Category: Client Server Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

int main() {
    int fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024];
    
    // Create a socket
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Fill in server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket with the server address
    if (bind(fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Receive messages from clients
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int len = recvfrom(fd, buffer, sizeof(buffer), 
                           MSG_WAITALL, (struct sockaddr *)&client_addr,
                           &client_len);
        if (len < 0) {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }
        
        // Print client information
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        printf("Received a message from %s:%d\n", client_ip, ntohs(client_addr.sin_port));
        
        // Analyze the message
        char *msg = strtok(buffer, " ");
        int nums[1000];
        int len_nums = 0;
        while (msg != NULL) {
            nums[len_nums++] = atoi(msg);
            msg = strtok(NULL, " ");
        }
        double mean = 0.0;
        for (int i = 0; i < len_nums; i++) {
            mean += nums[i];
        }
        mean /= len_nums;
        double var = 0.0;
        for (int i = 0; i < len_nums; i++) {
            var += (nums[i] - mean) * (nums[i] - mean);
        }
        var /= len_nums;
        double std_dev = sqrt(var);
        
        // Send back the result to the client
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "mean=%.2f var=%.2f std_dev=%.2f", mean, var, std_dev);
        if (sendto(fd, buffer, strlen(buffer), 
                   MSG_CONFIRM, (const struct sockaddr *)&client_addr, 
                   client_len) < 0) {
            perror("sendto failed");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}