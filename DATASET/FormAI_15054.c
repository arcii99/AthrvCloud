//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
/*
Title: Statistical Data Aggregation using TCP/IP Programming
Author: [Your Name]

Description: This program utilizes TCP/IP programming to receive statistical data 
             from multiple sources and generates an aggregated report.
             The report contains the sum, average, maximum and minimum of the 
             received numerical data.
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to calculate the sum of an integer array
int sum(int arr[], int n) {
    int result = 0;
    for(int i=0;i<n;i++)
        result += arr[i];
    return result;
}

// Function to calculate the maximum of an integer array
int max(int arr[], int n) {
    int result = arr[0];
    for(int i=0;i<n;i++)
        if(arr[i]>result)
            result = arr[i];
    return result;
}

// Function to calculate the minimum of an integer array
int min(int arr[], int n) {
    int result = arr[0];
    for(int i=0;i<n;i++)
        if(arr[i]<result)
            result = arr[i];
    return result;
}

int main(int argc, char const *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    int data_count, data_received = 0;
    int numerical_data[1024];

    // Create a socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Configure the address information for the server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Wait for a client to connect
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Receive the number of data items being transmitted
    valread = read( new_socket , buffer, BUFFER_SIZE);
    data_count = atoi(buffer);
    printf("Number of Data Points: %d\n", data_count);

    // Receive the numerical data items
    while(data_received < data_count){
        valread = read( new_socket , buffer, BUFFER_SIZE);
        numerical_data[data_received] = atoi(buffer);
        printf("Received: %d\n", numerical_data[data_received]);
        data_received++;
    }

    // Calculate the statistical quantities
    int sum_val = sum(numerical_data, data_count);
    int max_val = max(numerical_data, data_count);
    int min_val = min(numerical_data, data_count);
    float avg_val = (float)sum_val/data_count;

    // Send the statistical report back to the client
    char send_buffer[BUFFER_SIZE] = {0};
    snprintf(send_buffer, BUFFER_SIZE, "Sum: %d\nAverage: %.2f\nMaximum: %d\nMinimum: %d\n", sum_val, avg_val, max_val, min_val);
    send(new_socket , send_buffer , strlen(send_buffer) , 0 );
    printf("Statistical Report Sent.\n");
    return 0;
}