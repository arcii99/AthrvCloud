//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUF_SIZE 256
#define NUM_PLAYERS 3 // Number of players to test ping

// Function to calculate average ping time
int calculateAveragePing(int socket_fd, struct sockaddr_in *server_addr, char *ip_address, int num_pings)
{
    // Initialize variables
    char buffer[BUF_SIZE];
    int ping_times[num_pings];
    memset(&ping_times, 0, sizeof(ping_times));
    int total_ping_time = 0;
    int num_failed_pings = 0;
    int ping_attempt = 1;
    
    // Iterate through specified number of pings
    for(int i = 0; i < num_pings; i++)
    {
        // Construct and send ping packet
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);
        sprintf(buffer, "Ping attempt %d from %s", ping_attempt++, ip_address);
        sendto(socket_fd, buffer, strlen(buffer), 0, (struct sockaddr*) server_addr, sizeof(*server_addr));

        // Wait for pong response, or timeout
        socklen_t addr_len = sizeof(*server_addr);
        int num_bytes = recvfrom(socket_fd, buffer, BUF_SIZE, 0, (struct sockaddr*) server_addr, &addr_len);
        if(num_bytes == -1)
        {
            printf("Ping attempt %d failed: Timeout\n", i+1);
            num_failed_pings++;
            continue;
        }
        
        // Calculate ping time and add to total
        gettimeofday(&end_time, NULL);
        int ping_time = (int)((end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec)) / 1000;
        total_ping_time += ping_time;
        ping_times[i] = ping_time;
        
        printf("Ping attempt %d success: %d ms\n", i+1, ping_time);
        usleep(1000000); // Wait 1 second before sending next ping
    }
    
    // Calculate and print average ping time and packet loss
    int avg_ping_time = total_ping_time / (num_pings - num_failed_pings);
    float packet_loss_rate = ((float)num_failed_pings / num_pings) * 100;
    printf("\nResults for %s\n", ip_address);
    printf("Average ping time: %d ms\n", avg_ping_time);
    printf("Packet loss rate: %.1f %%\n", packet_loss_rate);
    
    // Return average ping time
    return avg_ping_time;
}

int main()
{
    // Get server IP addresses
    char *server_ips[NUM_PLAYERS] = {"192.168.0.1", "192.168.0.2", "192.168.0.3"};
    
    // Create UDP socket
    int socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(socket_fd == -1)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // Define server address structure
    struct hostent *server = gethostbyname("localhost");
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr = *((struct in_addr*) server->h_addr);
    
    // Calculate and print ping times for each server
    for(int i = 0; i < NUM_PLAYERS; i++)
    {
        int avg_ping_time = calculateAveragePing(socket_fd, &server_addr, server_ips[i], 5);
        printf("%s average ping time: %d ms\n\n", server_ips[i], avg_ping_time);
    }
    
    // Close socket and exit
    close(socket_fd);
    return 0;
}