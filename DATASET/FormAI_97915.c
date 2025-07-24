//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#define PORT 50000
#define HOST "127.0.0.1"

int main(int argc, const char *argv[]) {
    unsigned int sent_data = 0;
    unsigned int received_data = 0;
    unsigned int total_data_size = 500000;
    
    //create a socket
    int sockfd, data_fd;
    struct sockaddr_in addr;
    char buf[1024];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Socket failed");
        exit(1);
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(HOST);
    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("Connect failed");
        exit(1);
    }
    
    //start sending data
    while (sent_data < total_data_size) {
        int bytes;
        if((bytes = write(sockfd, buf, 1024)) < 0){
            perror("Write error");
            exit(1);
        }
        sent_data += bytes;
    }
    printf("Sent: %d bytes\n", sent_data);
    close(sockfd);
    
    //start receiving data
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Socket failed");
        exit(1);
    }
    
    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("Connect failed");
        exit(1);
    }
    
    while (received_data < total_data_size) {
        int bytes;
        if((bytes = read(sockfd, buf, 1024)) < 0){
            perror("Read error");
            exit(1);
        }
        received_data += bytes;
    }
    printf("Received: %d bytes\n", received_data);
    close(sockfd);
    return 0;
}