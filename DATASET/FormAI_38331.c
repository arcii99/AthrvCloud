//FormAI DATASET v1.0 Category: Port Scanner ; Style: Alan Touring
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

int main(int argc, char *argv[]) 
{ 
    int sock = 0, port = 0, err = 0, valread = 0; 
    struct sockaddr_in serv_addr; 
    char* ip_address = argv[1]; 
    int start_port = atoi(argv[2]); 
    int end_port = atoi(argv[3]); 
    
    // Loop through all specified ports 
    for (port = start_port; port <= end_port; port++) 
    { 
        // Create socket 
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        { 
            printf("Socket creation error.\n"); 
            return -1; 
        } 
    
        // Configure server address 
        serv_addr.sin_family = AF_INET; 
        serv_addr.sin_port = htons(port); 
    
        // Convert IP address from text to binary form 
        if (inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0)  
        { 
            printf("Invalid IP address.\n"); 
            return -1; 
        } 
    
        // Attempt to connect to port 
        err = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)); 
        if (err >= 0) 
        { 
            printf("Port %d is open.\n", port); 
        } 
    
        // Close socket 
        close(sock); 
    } 
    
    return 0; 
}