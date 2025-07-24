//FormAI DATASET v1.0 Category: Client Server Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to calculate the mean of an array of numbers
double calc_mean(double arr[], int size) {
    double sum = 0.0;
    for(int i=0;i<size;i++){
        sum += arr[i];
    }
    return sum/size;
}

// Function to calculate the median of an array of numbers
double calc_median(double arr[], int size) {
    if(size%2==0){
        int mid = size/2;
        return (arr[mid]+arr[mid-1])/2.0;
    }
    else{
        return arr[size/2];
    }
}

int main() {
    // Initializing variables for server
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    char buffer[1024];
    int addrlen = sizeof(server_addr);
    int PORT = 8080;
    
    // Creating socket file descriptor for server
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting server options
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Binding socket to the server address
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for connections
    if(listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started\n");
    
    // Accepting connections and handling client requests
    while(1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if(client_fd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        printf("Client connected\n");
        
        // Receiving array size and elements from client
        int size;
        recv(client_fd, &size, sizeof(int), 0);
        double arr[size];
        recv(client_fd, &arr, sizeof(arr), 0);
        
        // Calculating mean and median of array
        double mean = calc_mean(arr, size);
        double median = calc_median(arr, size);
        
        // Sending mean and median back to client
        char* response = malloc(1024*sizeof(char));
        sprintf(response, "Mean: %lf\nMedian: %lf", mean, median);
        send(client_fd, response, strlen(response), 0);
        
        // Closing client connection
        printf("Client disconnected\n");
        close(client_fd);
    }
    
    return 0;
}