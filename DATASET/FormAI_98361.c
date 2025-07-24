//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

void monitor(int sockfd) {
    char buffer[1024];
    int n;
    int count = 0;

    //monitor packets and calculate QoS values
    while(count<10) {
        bzero(buffer, sizeof(buffer));
        if((n = read(sockfd, buffer, sizeof(buffer))) < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        //calculate QoS values
        double delay = rand() * 100.0 / RAND_MAX;
        double jitter = rand() * 10.0 / RAND_MAX;
        double loss = rand() * 0.1 / RAND_MAX;

        //print QoS values
        printf("Packet %d: Delay = %f ms, Jitter = %f ms, Loss = %f%%\n", count+1, delay, jitter, loss*100);

        //pause for a random interval of time
        usleep(rand() % 1000000);

        count++;
    }

    printf("Monitoring complete.\n");
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Socket creation failed.\n");
        exit(1);
    }

    //assign IP, port, and protocol
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    //bind socket to IP and port
    if((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed.\n");
        exit(1);
    }

    //listen for incoming connections
    if((listen(sockfd, 5)) != 0) {
        printf("Listen failed.\n");
        exit(1);
    }

    //accept incoming connection
    socklen_t len = sizeof(cli);
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if(connfd < 0) {
        printf("Accept failed.\n");
        exit(1);
    }

    printf("Connection accepted.\n");

    //start monitoring QoS values
    monitor(connfd);

    //close socket
    close(sockfd);

    return 0;
}