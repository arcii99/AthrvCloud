//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NETWORK_STATUS_NORMAL 0
#define NETWORK_STATUS_SLOW 1
#define NETWORK_STATUS_DOWN 2

#define UPLOAD_THRESHOLD 80
#define DOWNLOAD_THRESHOLD 80

typedef struct {
    int upload_speed;
    int download_speed;
} NetworkSpeeds;

int get_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

NetworkSpeeds get_network_speeds() {
    NetworkSpeeds speeds;
    speeds.upload_speed = get_random_int(10, 100);
    speeds.download_speed = get_random_int(10, 100);
    return speeds;
}

int determine_network_status(NetworkSpeeds speeds) {
    if(speeds.download_speed < DOWNLOAD_THRESHOLD || speeds.upload_speed < UPLOAD_THRESHOLD) {
        return NETWORK_STATUS_DOWN;
    }
    else if(speeds.download_speed < DOWNLOAD_THRESHOLD * 1.5 || speeds.upload_speed < UPLOAD_THRESHOLD * 1.5) {
        return NETWORK_STATUS_SLOW;
    }
    else {
        return NETWORK_STATUS_NORMAL;
    }
}

void print_network_status(int status) {
    switch(status) {
        case NETWORK_STATUS_NORMAL:
            printf("Network status: NORMAL\n");
            break;
        case NETWORK_STATUS_SLOW:
            printf("Network status: SLOW\n");
            break;
        case NETWORK_STATUS_DOWN:
            printf("Network status: DOWN\n");
            break;
        default:
            printf("Invalid network status.\n");
            break;
    }
}

void handle_network_issue() {
    printf("Oh no! The network is down. We need to find a way to fix it...\n");
    // Some code here to handle the network issue in a post-apocalyptic world... 
}

int main() {
    srand(time(0));
    
    printf("Welcome to the Network Quality of Service (QoS) monitor!\n");
    printf("Press Ctrl-C to exit.\n");
    
    while(1) {
        sleep(1);
        
        NetworkSpeeds speeds = get_network_speeds();
        
        printf("Upload speed: %d Mbps - Download speed: %d Mbps\n", speeds.upload_speed, speeds.download_speed);
        
        int status = determine_network_status(speeds);
        print_network_status(status);
        
        if(status == NETWORK_STATUS_DOWN) {
            handle_network_issue();
        }
    }
    
    return 0;
}