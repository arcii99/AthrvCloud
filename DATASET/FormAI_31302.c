//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
  
#define NETMASK_16 65535        // 1111111111111111 
  
int main(int argc, char *argv[]) 
{ 
    int fd, sockfd; 
    struct sockaddr_in servaddr, cliaddr; 
    uint16_t network_id, subnet_id; 
  
    // Creating socket file descriptor 
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    // Creating and binding structure for server
    memset(&servaddr, 0, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(5000); 
      
    // Bind server address to the socket 
    if (bind(fd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    printf("Server is listening\n"); 
  
    // Communication loop begins 
    while(1){ 
        unsigned int len;
        int n = recvfrom(fd, &network_id, sizeof(network_id),  
                MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
                &len); 
        network_id = ntohs(network_id); 
  
        // counting the number of zeros in subnet mask 
        int count = 0; 
        int netmask = NETMASK_16; 
        while(!(netmask & ( 1 << 15 ))){ 
            count++; 
            netmask = netmask << 1; 
        } 
  
        subnet_id = network_id >> count; 
        subnet_id = subnet_id << count; 
        subnet_id = htons(subnet_id); 
  
        sendto(fd, &subnet_id, sizeof(subnet_id),  
            MSG_CONFIRM,  
            (const struct sockaddr *) &cliaddr, 
                len); 
        printf("Subnet-ID sent to the client with id %u is: %u\n", 
                ntohs(cliaddr.sin_port), ntohs(subnet_id)); 
    } 
    return 0; 
}