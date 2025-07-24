//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 65536
#define MAX_SSID_LENGTH 32

//Structure for an access point 
struct access_point {
    char ssid[MAX_SSID_LENGTH];
    char bssid[18];
    int channel;
    int signal_strength;
};

int main() {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in sin;
    struct access_point ap;
    socklen_t addr_len = sizeof(sin);
    
    //Create socket for scanning
    if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        perror("Failed to create scan socket");
        return 1;
    }
    
    //Bind the socket to a port number (0 to allow the OS to assign a free port)
    sin.sin_family = AF_INET;
    sin.sin_port = htons(0);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("Failed to bind scan socket");
        return 1;
    }
    
    //Set the socket to non-blocking to avoid blocking while waiting for responses
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    
    //Send scan request to all broadcast addresses on all Wi-Fi channels
    struct sockaddr_in dest_sin;
    dest_sin.sin_family = AF_INET;
    dest_sin.sin_port = htons(5353);
    inet_pton(AF_INET, "255.255.255.255", &(dest_sin.sin_addr));
    memset(buffer, 0, MAX_BUFFER_SIZE);
    memcpy(buffer, "\x00\x11\x22\x33\x44\x55\x00\x00\x00\x00\x00\x00\x08\x00",
           sizeof("\x00\x11\x22\x33\x44\x55\x00\x00\x00\x00\x00\x00\x08\x00"));
    for(int i=1; i<=11; i++) {
        buffer[32] = i;
        sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&dest_sin, sizeof(dest_sin));
        usleep(20000); //Wait 20 ms between channel scans
    }
    
    //Wait for scan response packets for 1 second
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    int num_responses = 0;
    while(select(sockfd+1, &readfds, NULL, NULL, &tv) > 0) {
        if(recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sin, &addr_len) == -1) {
            if(errno != EWOULDBLOCK) {
                perror("Failed to receive scan response packet");
            }
        }
        else if(strncmp(buffer+28, "\x00\x17\xdf", 3) == 0 && strncmp(buffer+44, "\x00\x50\xf2", 3) == 0) {
            //Found a scan response packet from an access point (based on MAC addresses)
            memcpy(ap.bssid, buffer+22, 6);
            sprintf(ap.ssid, "%.*s", buffer[68], buffer+69);
            ap.channel = (int)buffer[82];
            ap.signal_strength = (int)(signed char)(buffer[83]);
            printf("Found access point:\n");
            printf("  SSID: %s\n", ap.ssid);
            printf("  BSSID: %02X:%02X:%02X:%02X:%02X:%02X\n", ap.bssid[0], ap.bssid[1], ap.bssid[2], ap.bssid[3], ap.bssid[4], ap.bssid[5]);
            printf("  Channel: %i\n", ap.channel);
            printf("  Signal Strength: %idBm\n", ap.signal_strength);
            num_responses++;
        }
    }
    
    //Print number of access points found
    printf("Found %i access point%s\n", num_responses, num_responses==1 ? "" : "s");
    
    //Close the socket and exit
    close(sockfd);
    return 0;
}