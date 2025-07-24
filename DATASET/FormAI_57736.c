//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <arpa/inet.h>  
#include <sys/socket.h>    
    
// Function to print usage and exit
void usage()  
{  
    printf("Futuristic Port Scanner\n");  
    printf("Usage: ./portscanner <IP address>\n");  
}  
    
int main(int argc, char *argv[])  
{  
    if (argc != 2) {  
        usage();  
        return -1;  
    }  
    
    // Get IP address from command line argument  
    char *target = argv[1];  
    int sock;  
    struct sockaddr_in server;  
    int start_port, end_port;  
    
    // Set port range for scanning  
    start_port = 1;  
    end_port = 65535;  
    
    // Create socket  
    sock = socket(AF_INET , SOCK_STREAM , 0);  
    if (sock == -1)  
    {  
        perror("Could not create socket");  
        return -1;  
    }  
    printf("Socket created\n");  
    
    // Set address details  
    server.sin_addr.s_addr = inet_addr(target);  
    server.sin_family = AF_INET;  
    
    // Scan ports in range  
    for (int port = start_port; port <= end_port; port++)  
    {  
        // Set port  
        server.sin_port = htons(port);  
        
        // Connect to port  
        if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)  
        {  
            // Connection failed  
            printf("%d closed\n", port);  
            fflush(stdout);  
        }  
        else  
        {  
            // Connection successful  
            printf("%d open\n", port);  
            fflush(stdout);  
        }  
    }  
    
    return 0;  
}