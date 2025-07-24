//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
/*
Author: [Your Name]
Program Description: This program demonstrates the usage of TCP/IP sockets by performing statistical analysis on a given set of numbers.
*/

#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<math.h>

#define SERVER_PORT 8080
#define BUF_SIZE 256

int main(int argc, char *argv[]){
    int sock, client_sock, client_len, n, i;
    double sum = 0.0, mean = 0.0, variance = 0.0, std_deviation = 0.0;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];
    double data[BUF_SIZE/8]; //since we'll be sending double data through the socket, buffer size will be 8 times smaller than BUF_SIZE

    //create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    //set socket options
    int opt = 1;
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){ 
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    //bind socket to address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if(bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    //start listening for incoming connections
    if(listen(sock, 3) < 0){
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    //accept incoming client connection
    client_len = sizeof(client_addr);
    if((client_sock = accept(sock, (struct sockaddr *)&client_addr, (socklen_t *)&client_len)) < 0){
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    printf("Client connected successfully\n");

    //receive data from client
    if((n = read(client_sock, buffer, BUF_SIZE)) < 0){
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    //convert buffer to double data for computation
    memcpy(data, buffer, n);
    int num_of_elements = n / sizeof(double);

    //calculate statistical values
    for(i=0; i<num_of_elements; i++){
        sum += data[i];
    }
    mean = sum / num_of_elements;
    for(i=0; i<num_of_elements; i++){
        variance += pow((data[i] - mean), 2);
    }
    variance = variance / num_of_elements;
    std_deviation = sqrt(variance);

    //send computed values back to client
    snprintf(buffer, BUF_SIZE, "%.2lf, %.2lf, %.2lf", mean, variance, std_deviation);
    if(send(client_sock, buffer, strlen(buffer), 0) < 0){
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    printf("Statistical analysis results sent back to client\n");

    close(sock);
    return 0;
}