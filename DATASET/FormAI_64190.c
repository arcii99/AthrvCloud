//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_DEVICES 1000
#define MAX_IP_LENGTH 15

struct Device {
    char ip_address[MAX_IP_LENGTH+1];
    char device_name[BUFFER_SIZE];
    char mac_address[18];
};

struct Device devices[MAX_DEVICES];
int num_devices = 0;

void* scan_network(void* arg);

int main(int argc, char** argv) {
    pthread_t thread_id;
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);
    pthread_create(&thread_id, &attr, scan_network, NULL);
    
    pthread_join(thread_id, NULL);
    
    return 0;
}

void* scan_network(void* arg) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
        return NULL;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5353);
    addr.sin_addr.s_addr = inet_addr("224.0.0.251");
    
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        close(sock);
        return NULL;
    }
    
    int optval = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        fprintf(stderr, "Error setting socket option: %s\n", strerror(errno));
        close(sock);
        return NULL;
    }
    
    struct ip_mreq group;
    group.imr_multiaddr.s_addr = inet_addr("224.0.0.251");
    group.imr_interface.s_addr = htonl(INADDR_ANY);
    
    if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group, sizeof(group)) < 0) {
        fprintf(stderr, "Error joining multicast group: %s\n", strerror(errno));
        close(sock);
        return NULL;
    }
    
    while (true) {
        char buffer[BUFFER_SIZE];
        ssize_t num_bytes = recv(sock, buffer, BUFFER_SIZE, 0);
        if (num_bytes < 0) {
            fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
            continue;
        }
        
        if (strncmp(buffer, "\xff\xfa", 2) != 0) {
            continue;
        }
        
        int i = 2;
        char device_name[BUFFER_SIZE];
        memset(device_name, 0, BUFFER_SIZE);
        
        while (i < num_bytes && !isspace(buffer[i])) {
            device_name[i-2] = buffer[i];
            i++;
        }
        
        while (i < num_bytes && isspace(buffer[i])) {
            i++;
        }
        
        char ip_address[MAX_IP_LENGTH+1];
        memset(ip_address, 0, MAX_IP_LENGTH+1);
        int j = 0;
        
        while (i < num_bytes && !isspace(buffer[i])) {
            ip_address[j] = buffer[i];
            i++;
            j++;
        }
        
        if (strlen(ip_address) == MAX_IP_LENGTH && ip_address[MAX_IP_LENGTH-1] == '.') {
            continue;
        }
        
        char mac_address[18];
        memset(mac_address, 0, 18);
        int k = 0;
        
        while (i < num_bytes) {
            sprintf(mac_address+k*3, "%02x:", (unsigned char) buffer[i]);
            i++;
            k++;
        }
        
        mac_address[17] = '\0';
        
        bool known_device = false;
        for (int i = 0; i < num_devices; i++) {
            if (strcmp(devices[i].ip_address, ip_address) == 0) {
                known_device = true;
                break;
            }
        }
        
        if (!known_device) {
            strcpy(devices[num_devices].device_name, device_name);
            strcpy(devices[num_devices].ip_address, ip_address);
            strcpy(devices[num_devices].mac_address, mac_address);
            printf("New device found: %s - %s - %s\n", device_name, ip_address, mac_address);
            num_devices++;
        }
    }
    
    close(sock);
    return NULL;
}